//
//  PentagoGame.m
//  PentagoProject1
//
//  Created by Eric Brewer on 2/10/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "PentagoGame.h"

@implementation PentagoGame

- (PentagoGame*)init{
    
    for( int grid_x = 0; grid_x < NUM_BOARDS_WIDE * TILE_DEPTH + 2; grid_x++ )
        for( int grid_y = 0; grid_y < NUM_BOARDS_HIGH * TILE_DEPTH + 2; grid_y++ )
            pieceGrid[grid_x][grid_y] = 0;
    
    for( int grid_x = 0; grid_x < NUM_BOARDS_WIDE * TILE_DEPTH; grid_x++ )
        for( int grid_y = 0; grid_y < NUM_BOARDS_HIGH * TILE_DEPTH; grid_y++ )
            pieceGrid[grid_x+1][grid_y+1] = 0;
    
    _turns = 0;
    
    _isOKtoSwipe = NO;
    
    for( int pnum = 0; pnum < NUM_PLAYERS; pnum++ )
        _playerHasWon[pnum] = NO;
    _catsGame = NO;
    
    for( int board_x = 0; board_x < NUM_BOARDS_WIDE; board_x++ )
        for( int board_y = 0; board_y < NUM_BOARDS_WIDE; board_y++ )
            _cardinal[board_x][board_y] = NORTH;
    
    return self;
}

- (BOOL)makeMoveAtX:(int)x AtY:(int)y OnBoardX:(int)board_x BoardY:(int)board_y{

    int new_x, new_y;
    if( _cardinal[board_x][board_y] == NORTH ){
        new_x = x;
        new_y = y;
    }
    else if( _cardinal[board_x][board_y] == EAST ){
        new_x = TILE_DEPTH - y - 1;
        new_y = x;
    }
    else if( _cardinal[board_x][board_y] == SOUTH ){
        new_x = TILE_DEPTH - x - 1;
        new_y = TILE_DEPTH - y - 1;
    }
    else if( _cardinal[board_x][board_y] == WEST ){
        new_x = y;
        new_y = TILE_DEPTH - x - 1;
    }
    else
        assert( 0 );
    
    if( pieceGrid[board_x*TILE_DEPTH+new_x+1][board_y*TILE_DEPTH+new_y+1] )
        return NO;
    
    pieceGrid[board_x*TILE_DEPTH+new_x+1][board_y*TILE_DEPTH+new_y+1] = _turns % NUM_PLAYERS + 1;
    [self checkWinnerAtPointX:board_x*TILE_DEPTH+new_x+1 PointY:board_y*TILE_DEPTH+new_y+1];
    _isOKtoSwipe = YES;
    return YES;
}

- (int)whoseTurnItIs{
    
    return _turns % NUM_PLAYERS;
}

- (BOOL)isOKtoSwipe{
    
    return _isOKtoSwipe;
}

- (BOOL)playerHasWon:(int)player{
    
    return _playerHasWon[player];
}

- (BOOL)catsGame{
    
    return _catsGame;
}

- (void)rotateBoardX:(int)board_x BoardY:(int)board_y InDirection:(RotationDirection)dir{
    
    int temp[TILE_DEPTH][TILE_DEPTH];
    if( dir == CLOCKWISE ){
        for( int x = 0; x < TILE_DEPTH; x++ )
            for( int y = 0; y < TILE_DEPTH; y++ )
                temp[x][y] = pieceGrid[board_x*TILE_DEPTH+y+1][board_y*TILE_DEPTH+TILE_DEPTH-x];
        _cardinal[board_x][board_y] = ( _cardinal[board_x][board_y] + 1 ) % 4;
    }
    else if( dir == COUNTER_CLOCKWISE ){
        for( int x = 0; x < TILE_DEPTH; x++ )
            for( int y = 0; y < TILE_DEPTH; y++ )
                temp[x][y] = pieceGrid[board_x*TILE_DEPTH+TILE_DEPTH-y][board_y*TILE_DEPTH+x+1];
        _cardinal[board_x][board_y] = ( _cardinal[board_x][board_y] + 3 ) % 4;
    }
    else
        assert( 0 );
    
    for( int x = 0; x < TILE_DEPTH; x++ )
        for( int y = 0; y < TILE_DEPTH; y++ )
            pieceGrid[board_x*TILE_DEPTH+x+1][board_y*TILE_DEPTH+y+1] = temp[x][y];
    [self checkWinnerOnBoardX:board_x BoardY:board_y];
    _isOKtoSwipe = NO;
    _turns++;
    if( _turns == TILE_DEPTH * NUM_BOARDS_WIDE * TILE_DEPTH * NUM_BOARDS_HIGH )
        _catsGame = YES;
}

- (void)checkWinnerOnBoardX:(int)board_x BoardY:(int)board_y{
    
    for( int x = 0; x < TILE_DEPTH; x++ )
        for( int y = 0; y < TILE_DEPTH; y++ )
            [self checkWinnerAtPointX:board_x*TILE_DEPTH+x+1 PointY:board_y*TILE_DEPTH+y+1];
}

- (void)checkWinnerAtPointX:(int)x PointY:(int)y{
    
    if( !pieceGrid[x][y] )
        return;
    
    int candidate = pieceGrid[x][y];
    int step = 0;
    int shift = 0;
    
    // VERTICAL
    shift = 1;
    while( pieceGrid[x][y-shift] == candidate )
        shift++;
    shift--;
    step = 1;
    while( pieceGrid[x][y-shift+step] == candidate ){
        step++;
        if( step == WIN_LENGTH )
            _playerHasWon[candidate] = YES;
    }
    // HORIZONTAL
    shift = 1;
    while( pieceGrid[x-shift][y] == candidate )
        shift++;
    shift--;
    step = 1;
    while( pieceGrid[x-shift+step][y] == candidate ){
        step++;
        if( step == WIN_LENGTH )
            _playerHasWon[candidate] = YES;
    }
    // POSITIVE DIAGONAL
    shift = 1;
    while( pieceGrid[x-shift][y-shift] == candidate )
        shift++;
    shift--;
    step = 1;
    while( pieceGrid[x-shift+step][y-shift+step] == candidate ){
        step++;
        if( step == WIN_LENGTH )
            _playerHasWon[candidate] = YES;
    }
    // NEGATIVE DIAGONAL
    shift = 1;
    while( pieceGrid[x+shift][y-shift] == candidate )
        shift++;
    shift--;
    step = 1;
    while( pieceGrid[x+shift-step][y-shift+step] == candidate ){
        step++;
        if( step == WIN_LENGTH )
            _playerHasWon[candidate] = YES;
    }
}
                          
- (void)debugPrintBoard{
    
    for( int row = 0; row < NUM_BOARDS_HIGH * TILE_DEPTH; row++ )
        NSLog(@"%i %i %i %i %i %i",
              pieceGrid[0+1][row+1],
              pieceGrid[1+1][row+1],
              pieceGrid[2+1][row+1],
              pieceGrid[3+1][row+1],
              pieceGrid[4+1][row+1],
              pieceGrid[5+1][row+1] );
}

- (void)dealloc{
    
    [super dealloc];
}

@end
