//
//  MovieSearchView.m
//  EricBrewerProject2
//
//  Created by student on 3/5/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "MovieSearchView.h"
#import "MovieTableView.h"

@implementation MovieSearchView

- (id)initWithMovies:(NSArray *)movies{
    
    self = [super init];
    if( self ){
        
        _all_movies = [movies retain];
        
        self.title = @"Search";
        self.tabBarItem.image = [UIImage imageNamed:@"181-hammer.png"];
    }
    
    return self;
}

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

#pragma mark - View lifecycle

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
    
}

- (IBAction)didTapSearch:(id)sender {
    
    NSString *query = [_query_text.text copy];
    
    if( !query || !query.length ){
        [query release];
        return;
    }
    
    NSString *selectedField;
    if( _category_select.selectedSegmentIndex == TITLE )
        selectedField = @"TITLE";
    else if( _category_select.selectedSegmentIndex == PLOT )
        selectedField = @"PLOT";
    else
        assert( 0 );
    
    NSPredicate *pred = [NSPredicate predicateWithFormat:@"%K contains[cd] %@", selectedField, query];
    NSArray *results = [_all_movies filteredArrayUsingPredicate:pred];
    [_query_text resignFirstResponder];
    
    MovieTableView *resultsTableView = [[MovieTableView alloc] initWithMovies:results];
    [self.navigationController pushViewController:resultsTableView animated:YES];
    
    [query release];
    [resultsTableView release];
}

- (void)viewDidUnload
{
    [_query_text release];
    _query_text = nil;
    [_category_select release];
    _category_select = nil;
    [_button release];
    _button = nil;
    [super viewDidUnload];
    // Release any retained subviews of the main view.
    // e.g. self.myOutlet = nil;
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    // Return YES for supported orientations
    return (interfaceOrientation == UIInterfaceOrientationPortrait);
}

- (void)dealloc {
    [_all_movies release];
    [_query_text release];
    [_category_select release];
    [_button release];
    [super dealloc];
}

@end
