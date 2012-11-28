//
//  MovieTableView.h
//  EricBrewerProject2
//
//  Created by student on 2/28/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "DatabaseController.h"

@interface MovieTableView : UITableViewController{
    
    NSArray *_alphabet;
    NSMutableArray *_all_movies_with_letter;
}

- (id)initWithMovies:(NSArray *)movies;

@end

