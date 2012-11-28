//
//  AppDelegate.m
//  EricBrewerProject2
//
//  Created by student on 2/28/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "AppDelegate.h"
#import "MovieTableView.h"
#import "GenreTableView.h"
#import "RatingTableView.h"
#import "MovieSearchView.h"

@implementation AppDelegate

@synthesize window = _window;

- (void)dealloc
{
    [_window release];
    [super dealloc];
}

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    self.window = [[[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]] autorelease];
    // Override point for customization after application launch.
    self.window.backgroundColor = [UIColor whiteColor];
    [self.window makeKeyAndVisible];
    
    DatabaseController *dbc = [DatabaseController sharedInstance];
    NSArray *allMovies = [dbc getAllMovies];
    NSArray *allDistinctGenres = [dbc getAllDistinctGenre];
    NSMutableArray *allMoviesWithGenre = [NSMutableArray new];
    for( NSString *str in allDistinctGenres ){
        NSArray *arr = [dbc getAllMoviesWithGenre:str];
        [allMoviesWithGenre addObject:arr];
    }
        
    MovieTableView *movieTableViewTitle = [[MovieTableView alloc] initWithMovies:allMovies];
    GenreTableView *movieTableViewGenre = [[GenreTableView alloc] initWithDistinctGenres:allDistinctGenres moviesWithGenre:allMoviesWithGenre];
    RatingTableView *movieTableViewRating = [[RatingTableView alloc] initWithMovies:allMovies];
    MovieSearchView *movieSearchView = [[MovieSearchView alloc] initWithMovies:allMovies];
                                            
    UINavigationController *navControllerTitle = [[UINavigationController alloc] initWithRootViewController:movieTableViewTitle];
    UINavigationController *navControllerGenre = [[UINavigationController alloc] initWithRootViewController:movieTableViewGenre];
    UINavigationController *navControllerRating = [[UINavigationController alloc] initWithRootViewController:movieTableViewRating];
    UINavigationController *navControllerSearch = [[UINavigationController alloc] initWithRootViewController:movieSearchView];
    
    UITabBarController *tabBarController = [[UITabBarController alloc] init];
    tabBarController.viewControllers = [NSArray arrayWithObjects:navControllerTitle, navControllerGenre, navControllerRating, navControllerSearch, nil];

    self.window.rootViewController = tabBarController;

    [allMoviesWithGenre release];
    
    [movieTableViewTitle release];
    [movieTableViewGenre release];
    [movieTableViewRating release];
    [movieSearchView release];
    
    [navControllerTitle release];
    [navControllerGenre release];
    [navControllerRating release];
    [navControllerSearch release];
    
    [tabBarController release];
    
    return YES;
}

- (void)applicationWillResignActive:(UIApplication *)application
{
    /*
     Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
     Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
     */
}

- (void)applicationDidEnterBackground:(UIApplication *)application
{
    /*
     Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later. 
     If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
     */
}

- (void)applicationWillEnterForeground:(UIApplication *)application
{
    /*
     Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
     */
}

- (void)applicationDidBecomeActive:(UIApplication *)application
{
    /*
     Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
     */
}

- (void)applicationWillTerminate:(UIApplication *)application
{
    /*
     Called when the application is about to terminate.
     Save data if appropriate.
     See also applicationDidEnterBackground:.
     */
}

@end
