//
//  AppDelegate.h
//  PentagoProject1
//
//  Created by Eric Brewer on 2/10/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PentagoRootViewController.h"

@interface AppDelegate : UIResponder <UIApplicationDelegate>{
    
    PentagoRootViewController *rootViewController;
}

@property (strong, nonatomic) UIWindow *window;

- (PentagoRootViewController*)getRootViewController;
    
@end
