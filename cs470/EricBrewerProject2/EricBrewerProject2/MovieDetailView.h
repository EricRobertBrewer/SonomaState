//
//  MovieDetailView.h
//  EricBrewerProject2
//
//  Created by student on 2/28/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "Movie.h"

@interface MovieDetailView : UIViewController <NSURLConnectionDelegate, NSURLConnectionDataDelegate>{
    
    Movie *_movie;

    NSMutableData *_poster_data;
    UIActivityIndicatorView *_spinner;
    IBOutlet UIImageView *_poster;
    IBOutlet UILabel *_movie_name;
    IBOutlet UILabel *_year;
    IBOutlet UILabel *_rating;
    IBOutlet UILabel *_genres;
    IBOutlet UIWebView *_plot;
}

- (id)initWithMovie:(Movie*)movie;

@end
