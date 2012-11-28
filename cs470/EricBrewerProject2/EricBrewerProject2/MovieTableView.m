//
//  MovieTableView.m
//  EricBrewerProject2
//
//  Created by student on 2/28/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "MovieTableView.h"
#import "MovieDetailView.h"

@implementation MovieTableView

- (void)dealloc{
    
    [_alphabet release];
    [_all_movies_with_letter release];
    
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

        // Make sections based on first letter in movie title
        _alphabet = [[NSArray alloc] initWithObjects:@"A",@"B",@"C",@"D",@"E",@"F",@"G",@"H",@"I",
                                               @"J",@"K",@"L",@"M",@"N",@"O",@"P",@"Q",@"R",
                                               @"S",@"T",@"U",@"V",@"W",@"X",@"Y",@"Z",@"#",nil];
        _all_movies_with_letter = [NSMutableArray new];
        for( int i = 0; i < [_alphabet count] - 1; i++ ){
            NSMutableArray *moviesWithLetter = [NSMutableArray new];
            for( Movie *mov in movies )
                if( [mov.TITLE characterAtIndex:0] == [[_alphabet objectAtIndex:i] characterAtIndex:0] )
                    [moviesWithLetter addObject:mov];
            [_all_movies_with_letter addObject:moviesWithLetter];
            [moviesWithLetter release];
        }
        // Janky, but capture movies that begin with a special character
        NSString *specialChars = @"0123456789()";
        NSMutableArray *moviesWithSpecialChar = [NSMutableArray new];
        for( Movie *mov in movies )
            for( int i = 0; i < specialChars.length; i++ )
                if( [mov.TITLE characterAtIndex:0] == [specialChars characterAtIndex:i] )
                    [moviesWithSpecialChar addObject:mov];
        [_all_movies_with_letter addObject:moviesWithSpecialChar];
        [moviesWithSpecialChar release];
        
        self.title = @"By Title";
        self.tabBarItem.image = [UIImage imageNamed:@"106-sliders.png"];
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
    
    return [_alphabet count];
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    // Return the number of rows in the section.

    return [[_all_movies_with_letter objectAtIndex:section] count];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString *CellIdentifier = @"Cell";
    
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:CellIdentifier];
    if (cell == nil) {
        cell = [[[UITableViewCell alloc] initWithStyle:UITableViewCellStyleSubtitle reuseIdentifier:CellIdentifier] autorelease];
    }
    
    // Configure the cell...
    
    Movie *movie = [[_all_movies_with_letter objectAtIndex:indexPath.section] objectAtIndex:indexPath.row];
    cell.textLabel.text = movie.TITLE;    
    cell.detailTextLabel.text = [movie getGenreList];
    
    return cell;
}

- (NSArray *)sectionIndexTitlesForTableView:(UITableView *)tableView{
    
    return _alphabet;
}

- (NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section{
    
    if( [[_all_movies_with_letter objectAtIndex:section] count] )
        return [_alphabet objectAtIndex:section];
    
    return @"";
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

    Movie *movie = [[_all_movies_with_letter objectAtIndex:indexPath.section] objectAtIndex:indexPath.row];
    MovieDetailView *detailView = [[MovieDetailView alloc] initWithMovie:movie];
    [self.navigationController pushViewController:detailView animated:YES];
    [detailView release];
}

@end
