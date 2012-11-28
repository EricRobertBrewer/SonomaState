//
//  PentagoBoardView.h
//  PentagoProject1
//
//  Created by Eric Brewer on 2/10/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>

#define NUM_MARBLE_COLORS 8
#define ROTATE_TIME       0.8

typedef enum{
    BLUE,
    GRAY,
    GREEN,
    PINK,
    PURPLE,
    RED,
    TEAL,
    YELLOW
} MarbleColor;

@interface PentagoBoardView : UIViewController{
    
    int _boardIdX;
    int _boardIdY;
    
    UIImageView *boardImageView;
    CGRect boardTiles[TILE_DEPTH][TILE_DEPTH];
    
    NSMutableArray *placedMarbles;
    
    CGPoint _lastTouch;
    
    BOOL _isAnimating;
    int _cardinal;
}

- (void)loadInternals;
- (void)setupSwipeGestureRecognizers;

- (id)initWithDimension:(CGRect)dimension;
- (void)setBoardIdX:(int)x IdY:(int)y;
- (void)userTouchedTileAtX:(int)x AtY:(int)y;
- (void)placeMarbleAtX:(int)x AtY:(int)y WithMarbleColor:(int)color;
- (void)rotateInDirection:(RotationDirection)dir;
- (void)clearBoard;

- (void)dealloc;

@property( nonatomic ) int cardinal;
@property( nonatomic ) CGPoint lastTouch;
@property( nonatomic ) BOOL isAnimating;

@end
