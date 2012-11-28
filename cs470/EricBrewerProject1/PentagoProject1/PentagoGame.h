//
//  PentagoGame.h
//  PentagoProject1
//
//  Created by Eric Brewer on 2/10/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>

#define MIN_PLAYERS     2
#define MAX_PLAYERS     8
#define NUM_PLAYERS     8
#define WIN_LENGTH      5
#define NUM_BOARDS_WIDE 2
#define NUM_BOARDS_HIGH 2

@interface PentagoGame : NSObject{
    
    int pieceGrid[NUM_BOARDS_WIDE*TILE_DEPTH+2][NUM_BOARDS_HIGH*TILE_DEPTH+2];
    
    int _turns;
    
    BOOL _isOKtoSwipe;

    BOOL _playerHasWon[NUM_PLAYERS];
    BOOL _catsGame;
    
    int _cardinal[NUM_BOARDS_WIDE][NUM_BOARDS_HIGH];
}

- (PentagoGame*)init;
- (BOOL)makeMoveAtX:(int)x AtY:(int)y OnBoardX:(int)board_x BoardY:(int)board_y;
- (int)whoseTurnItIs;
- (BOOL)isOKtoSwipe;
- (BOOL)playerHasWon:(int)player;
- (BOOL)catsGame;
- (void)rotateBoardX:(int)board_x BoardY:(int)board_y InDirection:(RotationDirection)dir;
- (void)checkWinnerOnBoardX:(int)x BoardY:(int)y;
- (void)checkWinnerAtPointX:(int)x PointY:(int)y;
- (void)debugPrintBoard;

- (void)dealloc;

@end
