//
//  Movie.m
//  EricBrewerProject2
//
//  Created by student on 2/28/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "Movie.h"

@implementation Movie

@synthesize ID = _id;
@synthesize TITLE = _title;
@synthesize YEAR = _year;
@synthesize IMDB_RATING = _imdb_rating;
@synthesize IMDB_URL = _imdb_url;
@synthesize POSTER_NAME = _poster_name;
@synthesize PLOT = _plot;
@synthesize GENRES = _genres;

- (NSString*)getGenreList{
    
    NSArray *allgenres = [_genres allObjects];
    NSString *genre_list = [allgenres objectAtIndex:0];
    for( int gen = 1; gen < [allgenres count]; gen++ ){
        genre_list = [genre_list stringByAppendingString:@", "];
        genre_list = [genre_list stringByAppendingString:[allgenres objectAtIndex:gen]];
    }
    
    return genre_list;
}

@end
