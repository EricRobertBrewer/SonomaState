//
//  GenreTableView.h
//  EricBrewerProject2
//
//  Created by student on 3/6/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "DatabaseController.h"

@interface GenreTableView : UITableViewController{
    
    NSArray *_all_distinct_genres;
    NSMutableArray *_all_movies_with_genre;
}

- (id)initWithDistinctGenres:(NSArray *)genres moviesWithGenre:(NSMutableArray *)movies;

@end
