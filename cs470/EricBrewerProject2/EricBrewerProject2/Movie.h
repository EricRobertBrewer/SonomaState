//
//  Movie.h
//  EricBrewerProject2
//
//  Created by student on 2/28/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Movie : NSObject{
    
    int _id;
    NSString *_title;
    int _year;
    double _imdb_rating;
    NSURL *_imdb_url;
    NSString *_poster_name;
    NSString *_plot;
    NSSet* _genres;
}

- (NSString*)getGenreList;

@property( nonatomic )int ID;
@property( nonatomic, retain )NSString *TITLE;
@property( nonatomic )int YEAR;
@property( nonatomic )double IMDB_RATING;
@property( nonatomic, retain )NSURL *IMDB_URL;
@property( nonatomic, retain )NSString *POSTER_NAME;
@property( nonatomic, retain )NSString *PLOT;
@property( nonatomic, retain )NSSet* GENRES;

@end
