//
//  PentagoBoardView.m
//  PentagoProject1
//
//  Created by Eric Brewer on 2/10/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "PentagoBoardView.h"
#import "AppDelegate.h"

@implementation PentagoBoardView

@synthesize cardinal = _cardinal;
@synthesize lastTouch = _lastTouch;
@synthesize isAnimating = _isAnimating;

- (void)viewDidLoad{

    [self loadInternals];
    [self setupSwipeGestureRecognizers];
    
    [super viewDidLoad];
}

- (id)initWithDimension:(CGRect)dimension{
    
    boardImageView = [[UIImageView alloc] initWithFrame:dimension];
    [boardImageView setImage:[UIImage imageNamed:@"grid.png"]];
    [self.view addSubview:boardImageView];
    
    for( int col = 0; col < TILE_DEPTH; col++ )
        for( int row = 0; row < TILE_DEPTH; row++ )
            boardTiles[col][row] = CGRectMake(boardImageView.frame.origin.x + boardImageView.frame.size.width / TILE_DEPTH * col,
                                              boardImageView.frame.origin.y + boardImageView.frame.size.height / TILE_DEPTH * row,
                                              boardImageView.frame.size.width / TILE_DEPTH,
                                              boardImageView.frame.size.height / TILE_DEPTH);
    
    return self;
}

- (void)loadInternals{
    
    //boardImageView = [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"grid.png"]];
    //[self.view addSubview:boardImageView];
    /*
    for( int col = 0; col < TILE_DEPTH; col++ )
        for( int row = 0; row < TILE_DEPTH; row++ )
            boardTiles[col][row] = CGRectMake(boardImageView.frame.origin.x + boardImageView.image.size.width / TILE_DEPTH * col,
                                              boardImageView.frame.origin.y + boardImageView.image.size.height / TILE_DEPTH * row,
                                              boardImageView.image.size.width / TILE_DEPTH,
                                              boardImageView.image.size.height / TILE_DEPTH);
    */
    _boardIdX = -1;
    _boardIdY = -1;
    
    placedMarbles = [[NSMutableArray alloc] init];
    
    _isAnimating = NO;
    _cardinal = NORTH;
}

- (void)setupSwipeGestureRecognizers{
    
    UISwipeGestureRecognizer *up = [[UISwipeGestureRecognizer alloc] initWithTarget:self action:@selector( userSwipedUp: )];
    up.direction = UISwipeGestureRecognizerDirectionUp;
    [self.view addGestureRecognizer:up];
    [up release];
    
    UISwipeGestureRecognizer *right = [[UISwipeGestureRecognizer alloc] initWithTarget:self action:@selector( userSwipedRight: )];
    right.direction = UISwipeGestureRecognizerDirectionRight;
    [self.view addGestureRecognizer:right];
    [right release];
    
    UISwipeGestureRecognizer *down = [[UISwipeGestureRecognizer alloc] initWithTarget:self action:@selector( userSwipedDown: )];
    down.direction = UISwipeGestureRecognizerDirectionDown;
    [self.view addGestureRecognizer:down];
    [down release];
    
    UISwipeGestureRecognizer *left = [[UISwipeGestureRecognizer alloc] initWithTarget:self action:@selector( userSwipedLeft: )];
    left.direction = UISwipeGestureRecognizerDirectionLeft;
    [self.view addGestureRecognizer:left];
    [left release];
}

- (void)setBoardIdX:(int)x IdY:(int)y{
    
    _boardIdX = x;
    _boardIdY = y;
}

- (void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event{
    
    UITouch *touch = [touches anyObject];
    _lastTouch = [touch locationInView:self.view];
    
    for( int col = 0; col < TILE_DEPTH; col++ )
        for( int row = 0; row < TILE_DEPTH; row++ )
            if( CGRectContainsPoint( boardTiles[col][row], _lastTouch ) ){
                NSLog( @"Touch at BoardX:%i Y:%i column:%i row:%i", _boardIdX, _boardIdY, col, row );
                [self userTouchedTileAtX:col AtY:row];
            }
}

- (void)userTouchedTileAtX:(int)x AtY:(int)y{
    
    AppDelegate *appDel = (AppDelegate*)[[UIApplication sharedApplication] delegate];
    PentagoRootViewController *prvc = [appDel getRootViewController];
    [prvc checkForValidTouchAtX:x AtY:y WithBoardIdX:_boardIdX BoardIdY:_boardIdY];
}

- (void)userSwipedUp:(id)sender{
    
    NSLog( @"SwipeUp at BoardX:%i Y:%i AtPointX:%i Y:%i", _boardIdX, _boardIdY, (int)_lastTouch.x, (int)_lastTouch.y );
    
    BOOL onLeftEdge = NO;
    BOOL onRightEdge = NO;
    for( int row = 0; row < TILE_DEPTH; row++ ){
        if( CGRectContainsPoint(boardTiles[0][row], _lastTouch) )
            onLeftEdge = YES;
        if( CGRectContainsPoint(boardTiles[TILE_DEPTH-1][row], _lastTouch) )
            onRightEdge = YES;
    }
    
    AppDelegate *appDel = (AppDelegate*)[[UIApplication sharedApplication] delegate];
    PentagoRootViewController *prvc = [appDel getRootViewController];
    if( onLeftEdge )
        [prvc checkForValidSwipeWithDirection:CLOCKWISE WithBoardIdX:_boardIdX BoardIdY:_boardIdY];
    if( onRightEdge )
        [prvc checkForValidSwipeWithDirection:COUNTER_CLOCKWISE WithBoardIdX:_boardIdX BoardIdY:_boardIdY];
}

- (void)userSwipedRight:(id)sender{
    
    NSLog( @"SwipeRight at BoardX:%i Y:%i AtPointX:%i Y:%i", _boardIdX, _boardIdY, (int)_lastTouch.x, (int)_lastTouch.y );
    
    BOOL onTopEdge = NO;
    BOOL onBottomEdge = NO;
    for( int col = 0; col < TILE_DEPTH; col++ ){
        if( CGRectContainsPoint(boardTiles[col][0], _lastTouch) )
            onTopEdge = YES;
        if( CGRectContainsPoint(boardTiles[col][TILE_DEPTH-1], _lastTouch) )
            onBottomEdge = YES;
    }
    
    AppDelegate *appDel = (AppDelegate*)[[UIApplication sharedApplication] delegate];
    PentagoRootViewController *prvc = [appDel getRootViewController];
    
    if( onTopEdge )
        [prvc checkForValidSwipeWithDirection:CLOCKWISE WithBoardIdX:_boardIdX BoardIdY:_boardIdY];
    if( onBottomEdge )
        [prvc checkForValidSwipeWithDirection:COUNTER_CLOCKWISE WithBoardIdX:_boardIdX BoardIdY:_boardIdY];
}

- (void)userSwipedDown:(id)sender{
    
    NSLog( @"SwipeDown at BoardX:%i Y:%i AtPointX:%i Y:%i", _boardIdX, _boardIdY, (int)_lastTouch.x, (int)_lastTouch.y );
    
    BOOL onLeftEdge = NO;
    BOOL onRightEdge = NO;
    for( int row = 0; row < TILE_DEPTH; row++ ){
        if( CGRectContainsPoint(boardTiles[0][row], _lastTouch) )
            onLeftEdge = YES;
        if( CGRectContainsPoint(boardTiles[TILE_DEPTH-1][row], _lastTouch) )
            onRightEdge = YES;
    }
    
    AppDelegate *appDel = (AppDelegate*)[[UIApplication sharedApplication] delegate];
    PentagoRootViewController *prvc = [appDel getRootViewController];
    
    if( onLeftEdge )
        [prvc checkForValidSwipeWithDirection:COUNTER_CLOCKWISE WithBoardIdX:_boardIdX BoardIdY:_boardIdY];
    if( onRightEdge )
        [prvc checkForValidSwipeWithDirection:CLOCKWISE WithBoardIdX:_boardIdX BoardIdY:_boardIdY];
}

- (void)userSwipedLeft:(id)sender{
    
    NSLog( @"SwipeLeft at BoardX:%i Y:%i AtPointX:%i Y:%i", _boardIdX, _boardIdY, (int)_lastTouch.x, (int)_lastTouch.y );
    
    BOOL onTopEdge = NO;
    BOOL onBottomEdge = NO;
    for( int col = 0; col < TILE_DEPTH; col++ ){
        if( CGRectContainsPoint(boardTiles[col][0], _lastTouch) )
            onTopEdge = YES;
        if( CGRectContainsPoint(boardTiles[col][TILE_DEPTH-1], _lastTouch) )
            onBottomEdge = YES;
    }
    
    AppDelegate *appDel = (AppDelegate*)[[UIApplication sharedApplication] delegate];
    PentagoRootViewController *prvc = [appDel getRootViewController];
    
    if( onTopEdge )
        [prvc checkForValidSwipeWithDirection:COUNTER_CLOCKWISE WithBoardIdX:_boardIdX BoardIdY:_boardIdY];
    if( onBottomEdge )
        [prvc checkForValidSwipeWithDirection:CLOCKWISE WithBoardIdX:_boardIdX BoardIdY:_boardIdY];
}

- (void)placeMarbleAtX:(int)x AtY:(int)y WithMarbleColor:(int)color{
    
    NSLog( @"placeMarbleAtX:%i Y:%i WithMarbleColor:%i", x, y, color );
    
    // Display the marble. At this point, we know that the move at this tile was valid.
    UIImageView *marble = [[UIImageView alloc] initWithFrame:boardTiles[x][y]];
    if( color == BLUE )
        [marble setImage:[UIImage imageNamed:@"blueMarble.png"]];
    else if( color == GRAY )
        [marble setImage:[UIImage imageNamed:@"grayMarble.png"]];
    else if( color == GREEN )
        [marble setImage:[UIImage imageNamed:@"greenMarble.png"]];
    else if( color == PINK )
        [marble setImage:[UIImage imageNamed:@"pinkMarble.png"]];
    else if( color == PURPLE )
        [marble setImage:[UIImage imageNamed:@"purpleMarble.png"]];
    else if( color == RED )
        [marble setImage:[UIImage imageNamed:@"redMarble.png"]];
    else if( color == TEAL )
        [marble setImage:[UIImage imageNamed:@"tealMarble.png"]];
    else
        [marble setImage:[UIImage imageNamed:@"yellowMarble.png"]];
    [self.view addSubview:marble];
    [placedMarbles addObject:marble];
    [marble release];
}

- (void)rotateInDirection:(RotationDirection)dir{
    
    _isAnimating = YES;
    
    if( dir == CLOCKWISE ){
        [UIView beginAnimations:@"rotateClockwise" context:nil];
        [UIView setAnimationDuration:ROTATE_TIME];
        [UIView setAnimationBeginsFromCurrentState:YES];
        [UIView setAnimationDelegate:self];
        [UIView setAnimationDidStopSelector:@selector(animationDidStop)];
        self.view.transform = CGAffineTransformMakeRotation( _cardinal * M_PI_2 + M_PI_2 );
        //for( UIImageView *iv in placedMarbles )
        //    iv.transform = CGAffineTransformMakeRotation( _cardinal * M_PI_2 - M_PI_2 );
        [UIView commitAnimations];
        _cardinal = ( _cardinal + 1 ) % 4;
    }
    else if( dir == COUNTER_CLOCKWISE ){
        [UIView beginAnimations:@"rotateCounterClockwise" context:nil];
        [UIView setAnimationDuration:ROTATE_TIME];
        [UIView setAnimationBeginsFromCurrentState:YES];
        [UIView setAnimationDelegate:self];
        [UIView setAnimationDidStopSelector:@selector(animationDidStop)];
        self.view.transform = CGAffineTransformMakeRotation( _cardinal * M_PI_2 - M_PI_2 );
        //for( UIImageView *iv in placedMarbles )
        //    iv.transform = CGAffineTransformMakeRotation( _cardinal * M_PI_2 + M_PI_2 );
        [UIView commitAnimations];
        _cardinal = ( _cardinal + 3 ) % 4;
    }
    else
        assert( 0 );
}

- (void)animationDidStop{
    
    _isAnimating = NO;
}

// Clobber all the marble image views.
- (void)clearBoard{
    
    for( int i = 0; i < [placedMarbles count]; i++ )
        [[placedMarbles objectAtIndex:i] removeFromSuperview];
    [placedMarbles removeAllObjects];
}

- (void)dealloc{
    
    [boardImageView release];
    [placedMarbles release];

    [super dealloc];
}

/*
// Only override drawRect: if you perform custom drawing.
// An empty implementation adversely affects performance during animation.
- (void)drawRect:(CGRect)rect
{
    // Drawing code
}
*/

@end
