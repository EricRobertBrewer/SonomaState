//
//  PentagoRootViewController.m
//  PentagoProject1
//
//  Created by Eric Brewer on 2/10/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "PentagoRootViewController.h"

@implementation PentagoRootViewController
/*
- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)didReceiveMemoryWarning
{
    // Releases the view if it doesn't have a superview.
    [super didReceiveMemoryWarning];
    
    // Release any cached data, images, etc that aren't in use.
}
*/
#pragma mark - View lifecycle
/*
// Implement loadView to create a view hierarchy programmatically, without using a nib.
- (void)loadView
{
}
*/
// Implement viewDidLoad to do additional setup after loading the view, typically from a nib.
- (void)viewDidLoad{
    
    for( int board_x = 0; board_x < NUM_BOARDS_WIDE; board_x++ )
        for( int board_y = 0; board_y < NUM_BOARDS_HIGH; board_y++ ){
            boardView[board_x][board_y] = [[PentagoBoardView alloc] initWithDimension:
                                           CGRectMake(( 2 * GRID_BORDER + GRID_DIMENSION ) * board_x + GRID_BORDER,
                                                      ( 2 * GRID_BORDER + GRID_DIMENSION ) * board_y + GRID_BORDER + GRID_Y,
                                                      GRID_DIMENSION,
                                                      GRID_DIMENSION)];
            /*[boardView[board_x][board_y].view setFrame:*/
            [boardView[board_x][board_y] setBoardIdX:board_x IdY:board_y];
            [self.view addSubview:boardView[board_x][board_y].view];
        }

    for( int pnum = 0; pnum < NUM_PLAYERS; pnum++ )
        marbleColorId[pnum] = pnum;
    
    upperLabel = [[UILabel alloc] initWithFrame:CGRectMake(LABEL_X, LABEL_Y, LABEL_WIDTH, LABEL_HEIGHT)];
    upperLabel.text = @"PENTAGO - PRESS START";
    upperLabel.textAlignment = UITextAlignmentCenter;
    upperLabel.font = [UIFont fontWithName:@"Helvetica" size:FONT_SIZE];
    //upperLabel.adjustsFontSizeToFitWidth = YES;
    upperLabel.baselineAdjustment = UIBaselineAdjustmentAlignCenters;
    upperLabel.textColor = [UIColor whiteColor];
    upperLabel.backgroundColor = [UIColor clearColor];
    [self.view addSubview:upperLabel];
    
    startGameButton = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    [startGameButton setFrame:CGRectMake(BUTTON_X, BUTTON_Y, BUTTON_WIDTH, BUTTON_HEIGHT)];
    [startGameButton setTitle:@"START GAME" forState:UIControlStateNormal];
    [startGameButton addTarget:self action:@selector(startNewGame:) forControlEvents:UIControlEventTouchDown];
    [self.view addSubview:startGameButton];
    
    game = [PentagoGame alloc];
    
    [super viewDidLoad];
}

- (void)checkForValidTouchAtX:(int)x AtY:(int)y WithBoardIdX:(int)board_x BoardIdY:(int)board_y{
    
    if( !startGameButton.hidden ){
        NSLog(@"CANNOT TOUCH, !startGameButton.hidden");
        return;
    }
    if( [game isOKtoSwipe] ){
        NSLog(@"CANNOT TOUCH, [game isOKtoSwipe]");
        return;
    }
    if( boardView[board_x][board_y].isAnimating ){
        NSLog(@"CANNOT TOUCH, boardView[board_x][board_y].isAnimating");
        return;
    }
    if( ![game makeMoveAtX:x AtY:y OnBoardX:board_x BoardY:board_y] ){
        NSLog(@"CANNOT TOUCH, ![game makeMoveAtX:x AtY:y OnBoardX:board_x BoardY:board_y]");
        return;
    }
    
    [boardView[board_x][board_y] placeMarbleAtX:x AtY:y WithMarbleColor:marbleColorId[[game whoseTurnItIs]]];
    [self announceEndOfGame];
    upperLabel.text = [NSString stringWithFormat:@"Player %i: Swipe a board", [game whoseTurnItIs] + 1];
    [game debugPrintBoard];
}

- (void)checkForValidSwipeWithDirection:(RotationDirection)dir WithBoardIdX:(int)board_x BoardIdY:(int)board_y{
    
    if( !startGameButton.hidden ){
        NSLog(@"CANNOT SWIPE, !startGameButton.hidden");
        return;
    }
    if( ![game isOKtoSwipe] ){
        NSLog(@"CANNOT SWIPE, ![game isOKtoSwipe]");
        return;
    }
    if( boardView[board_x][board_y].isAnimating ){
        NSLog(@"CANNOT SWIPE, boardView[board_x][board_y].isAnimating");
        return;
    }
    
    [boardView[board_x][board_y] rotateInDirection:dir];
    [game rotateBoardX:board_x BoardY:board_y InDirection:dir];
    [self announceEndOfGame];
    upperLabel.text = [NSString stringWithFormat:@"Player %i: Place a marble", [game whoseTurnItIs] + 1];
    [game debugPrintBoard];
}

- (void)announceEndOfGame{
 
    for( int pnum = 0; pnum < NUM_PLAYERS; pnum++ )
        if( [game playerHasWon:pnum] )
            game_over = YES;
    if( game_over ){
        UIAlertView *goodGame = [[UIAlertView alloc] initWithTitle:@"Game Over"
                                                           message:@"So obvious!"
                                                          delegate:nil 
                                                 cancelButtonTitle:@"OK" 
                                                 otherButtonTitles:nil];
        [goodGame show];
        [goodGame release];
        startGameButton.hidden = NO;
        
    }
    else if( [game catsGame] ){
        UIAlertView *catsGame = [[UIAlertView alloc] initWithTitle:@"Cat's Game"
                                                           message:@"Nobody won!"
                                                          delegate:nil 
                                                 cancelButtonTitle:@"OK" 
                                                 otherButtonTitles:nil];
        [catsGame show];
        [catsGame release];
        startGameButton.hidden = NO;
    }
}

- (void)startNewGame:(id)sender{
    
    startGameButton.hidden = YES;
    
    for( int board_x = 0; board_x < NUM_BOARDS_WIDE; board_x++ )
        for( int board_y = 0; board_y < NUM_BOARDS_HIGH; board_y++ )
            [boardView[board_x][board_y] clearBoard];
    
    game = [game init];
    
    game_over = NO;
            
    assert( NUM_PLAYERS >= MIN_PLAYERS );
    assert( NUM_PLAYERS <= MAX_PLAYERS );
    BOOL colorTaken[NUM_MARBLE_COLORS];
    for( int cnum = 0; cnum < NUM_MARBLE_COLORS; cnum++ )
        colorTaken[cnum] = NO;
    for( int pnum = 0; pnum < NUM_PLAYERS; pnum++ ){
        do
            marbleColorId[pnum] = arc4random() % NUM_MARBLE_COLORS;
        while( colorTaken[marbleColorId[pnum]] );
        colorTaken[marbleColorId[pnum]] = YES;
    }

    upperLabel.text = [NSString stringWithFormat:@"Player %i: Place a marble", [game whoseTurnItIs] + 1];
}

- (void)dealloc{
    
    for( int board_x; board_x < NUM_BOARDS_WIDE; board_x++ )
        for( int board_y; board_y < NUM_BOARDS_HIGH; board_y++ )
            [boardView[board_x][board_y] release];
    [upperLabel release];
    [startGameButton release];
    [game release];
    
    [super dealloc];
}
/*
- (void)viewDidUnload
{
    [super viewDidUnload];
    // Release any retained subviews of the main view.
    // e.g. self.myOutlet = nil;
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    // Return YES for supported orientations
	return YES;
}
*/
@end
