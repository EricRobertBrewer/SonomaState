//
//  MovieDetailView.m
//  EricBrewerProject2
//
//  Created by student on 2/28/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "MovieDetailView.h"

@implementation MovieDetailView

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

- (id)initWithMovie:(Movie*)movie{
    
    _movie = [movie retain];
    
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.

    self.title = _movie.TITLE;
    
    NSString *pname = @"http://yourmovierating.com/movie_pictures/";
    pname = [pname stringByAppendingString:_movie.POSTER_NAME];
    pname = [pname stringByAppendingString:@".jpg"];
    NSURL *purl = [NSURL URLWithString:pname];
    NSURLRequest *preq = [NSURLRequest requestWithURL:purl];
    __unused NSURLConnection *pconn = [NSURLConnection connectionWithRequest:preq delegate:self];
    
    _spinner = [[UIActivityIndicatorView alloc] initWithActivityIndicatorStyle:UIActivityIndicatorViewStyleGray];
    [_spinner setHidesWhenStopped:YES];
    _spinner.center = _poster.center;
    [self.view addSubview:_spinner];
        
    _movie_name.text = _movie.TITLE;
    
    _year.text = [NSString stringWithFormat:@"(%i)", _movie.YEAR];
    
    _rating.text = [NSString stringWithFormat:@"Rating: %.1f", _movie.IMDB_RATING];
    
    _genres.text = [_movie getGenreList];
    
    [_plot loadHTMLString:_movie.PLOT baseURL:nil];
}

- (void)connection:(NSURLConnection *)connection didReceiveResponse:(NSURLResponse *)response{
    
    if( _poster_data ){
        [_poster_data release];
        _poster_data = nil;
    }
    
    _poster_data = [[NSMutableData alloc] init];
    
    [_spinner startAnimating];
}

- (void)connection:(NSURLConnection *)connection didReceiveData:(NSData *)data{
    
    [_poster_data appendData:data];
}

- (void)connectionDidFinishLoading:(NSURLConnection *)connection{
    
    _poster.image = [UIImage imageWithData:_poster_data];
    [_poster_data release];
    _poster_data = nil;
    
    [_spinner stopAnimating];
}

- (void)viewDidUnload
{
    [_poster release];
    _poster = nil;
    [_movie_name release];
    _movie_name = nil;
    [_year release];
    _year = nil;
    [_rating release];
    _rating = nil;
    [_genres release];
    _genres = nil;
    [_plot release];
    _plot = nil;
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
    [_movie release];
    [_poster release];
    [_movie_name release];
    [_year release];
    [_rating release];
    [_genres release];
    [_plot release];
    [super dealloc];
}
@end
