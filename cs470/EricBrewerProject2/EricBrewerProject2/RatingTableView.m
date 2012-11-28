//
//  RatingTableView.m
//  EricBrewerProject2
//
//  Created by student on 3/6/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "RatingTableView.h"
#import "MovieDetailView.h"

@implementation RatingTableView

- (void)dealloc{
    
    [_all_movies release];
    [_grade_index_names release];
    [_grade_header_names release];
    [_grade_footer_names release];
    
    [super dealloc];
}

- (id)initWithStyle:(UITableViewStyle)style
{
    self = [super initWithStyle:style];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (id)initWithMovies:(NSArray *)movies{
    
    self = [super init];
    if( self ){
        
        // Sort the database of movies by IMDB_RATING
        NSSortDescriptor *sort = [[NSSortDescriptor alloc] initWithKey:@"IMDB_RATING" ascending:NO];
        _all_movies = [[movies sortedArrayUsingDescriptors:[NSArray arrayWithObject:sort]] retain];
        [sort release];
        
        // Build a c-style data structure of how many movies exist with each given grade
        for( int i = 0; i < NUM_RATINGS; i++ )
            _movies_with_grade[i] = 0;
        for( Movie *m in _all_movies )
            if( m.IMDB_RATING >= A_GRADE )
                _movies_with_grade[A]++;
            else if( m.IMDB_RATING >= B_GRADE )
                _movies_with_grade[B]++;
            else if( m.IMDB_RATING >= C_GRADE )
                _movies_with_grade[C]++;
            else if( m.IMDB_RATING >= D_GRADE )
                _movies_with_grade[D]++;
            else
                _movies_with_grade[F]++;
        
        // Just for table prettiness (or ugliness)
        _grade_index_names = [[NSArray alloc] initWithObjects:@"A", @"B", @"C", @"D", @"F", nil];
        _grade_header_names = [[NSArray alloc] initWithObjects:@"A < 10.0", @"B < 9.0", @"C < 8.0", @"D < 7.0", @"F < 6.0", nil];
        _grade_footer_names = [[NSArray alloc] initWithObjects:@"A > 9.0", @"B > 8.0", @"C > 7.0", @"D > 6.0", @"F > 0.0", nil];
        
        self.title = @"By Rating";
        self.tabBarItem.image = [UIImage imageNamed:@"134-viking.png"];
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

    // Uncomment the following line to preserve selection between presentations.
    // self.clearsSelectionOnViewWillAppear = NO;
 
    // Uncomment the following line to display an Edit button in the navigation bar for this view controller.
    // self.navigationItem.rightBarButtonItem = self.editButtonItem;
}

- (void)viewDidUnload
{
    [super viewDidUnload];
    // Release any retained subviews of the main view.
    // e.g. self.myOutlet = nil;
}

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
}

- (void)viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:animated];
}

- (void)viewWillDisappear:(BOOL)animated
{
    [super viewWillDisappear:animated];
}

- (void)viewDidDisappear:(BOOL)animated
{
    [super viewDidDisappear:animated];
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    // Return YES for supported orientations
    return (interfaceOrientation == UIInterfaceOrientationPortrait);
}

#pragma mark - Table view data source

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    // Return the number of sections.
    return NUM_RATINGS;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    // Return the number of rows in the section.

    return _movies_with_grade[section];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString *CellIdentifier = @"Cell";
    
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:CellIdentifier];
    if (cell == nil) {
        cell = [[[UITableViewCell alloc] initWithStyle:UITableViewCellStyleSubtitle reuseIdentifier:CellIdentifier] autorelease];
    }
    
    // Configure the cell...
    
    int cushion = 0;
    for( int i = 0; i < indexPath.section; i++ )
        cushion += _movies_with_grade[i];
    
    Movie *movie = [_all_movies objectAtIndex:cushion + indexPath.row];
    cell.textLabel.text = movie.TITLE;
    cell.detailTextLabel.text = [NSString stringWithFormat:@"%.1f", movie.IMDB_RATING];
    
    return cell;
}

- (NSArray *)sectionIndexTitlesForTableView:(UITableView *)tableView{
    
    return _grade_index_names;
}

- (NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section{
    
    return [_grade_header_names objectAtIndex:section];
}

- (NSString *)tableView:(UITableView *)tableView titleForFooterInSection:(NSInteger)section{
    
    return [_grade_footer_names objectAtIndex:section];
}

/*
// Override to support conditional editing of the table view.
- (BOOL)tableView:(UITableView *)tableView canEditRowAtIndexPath:(NSIndexPath *)indexPath
{
    // Return NO if you do not want the specified item to be editable.
    return YES;
}
*/

/*
// Override to support editing the table view.
- (void)tableView:(UITableView *)tableView commitEditingStyle:(UITableViewCellEditingStyle)editingStyle forRowAtIndexPath:(NSIndexPath *)indexPath
{
    if (editingStyle == UITableViewCellEditingStyleDelete) {
        // Delete the row from the data source
        [tableView deleteRowsAtIndexPaths:[NSArray arrayWithObject:indexPath] withRowAnimation:UITableViewRowAnimationFade];
    }   
    else if (editingStyle == UITableViewCellEditingStyleInsert) {
        // Create a new instance of the appropriate class, insert it into the array, and add a new row to the table view
    }   
}
*/

/*
// Override to support rearranging the table view.
- (void)tableView:(UITableView *)tableView moveRowAtIndexPath:(NSIndexPath *)fromIndexPath toIndexPath:(NSIndexPath *)toIndexPath
{
}
*/

/*
// Override to support conditional rearranging of the table view.
- (BOOL)tableView:(UITableView *)tableView canMoveRowAtIndexPath:(NSIndexPath *)indexPath
{
    // Return NO if you do not want the item to be re-orderable.
    return YES;
}
*/

#pragma mark - Table view delegate

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    // Navigation logic may go here. Create and push another view controller.
    /*
     <#DetailViewController#> *detailViewController = [[<#DetailViewController#> alloc] initWithNibName:@"<#Nib name#>" bundle:nil];
     // ...
     // Pass the selected object to the new view controller.
     [self.navigationController pushViewController:detailViewController animated:YES];
     [detailViewController release];
     */
    
    int cushion = 0;
    for( int i = 0; i < indexPath.section; i++ )
        cushion += _movies_with_grade[i];
    
    Movie *movie = [_all_movies objectAtIndex:cushion + indexPath.row];
    MovieDetailView *detailView = [[MovieDetailView alloc] initWithMovie:movie];
    
    [self.navigationController pushViewController:detailView animated:YES];
    
    [detailView release];
}

@end
