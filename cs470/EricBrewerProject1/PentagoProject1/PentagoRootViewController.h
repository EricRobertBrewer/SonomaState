//
//  PentagoRootViewController.h
//  PentagoProject1
//
//  Created by Eric Brewer on 2/10/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PentagoGame.h"
#import "PentagoBoardView.h"

#define SCREEN_WIDTH    768
#define SCREEN_HEIGHT   1024
#define GRID_BORDER     6
#define GRID_Y          93
#define GRID_DIMENSION  (SCREEN_WIDTH/NUM_BOARDS_WIDE)-(2*GRID_BORDER)
#define LABEL_X         80
#define LABEL_Y         20
#define LABEL_WIDTH     (SCREEN_WIDTH-2*LABEL_X)
#define LABEL_HEIGHT    95
#define FONT_SIZE       36
#define BUTTON_X        190
#define BUTTON_Y        900
#define BUTTON_WIDTH    (SCREEN_WIDTH-2*BUTTON_X)
#define BUTTON_HEIGHT   60

@interface PentagoRootViewController : UIViewController{
    
    PentagoBoardView *boardView[NUM_BOARDS_WIDE][NUM_BOARDS_HIGH];
    
    int marbleColorId[NUM_PLAYERS];
    
    UILabel *upperLabel;
    UIButton *startGameButton;

    PentagoGame *game;
    BOOL game_over;
}

- (void)checkForValidTouchAtX:(int)x AtY:(int)y WithBoardIdX:(int)board_x BoardIdY:(int)board_y;
- (void)checkForValidSwipeWithDirection:(RotationDirection)dir WithBoardIdX:(int)board_x BoardIdY:(int)board_y;
- (void)announceEndOfGame;

- (void)dealloc;

@end
