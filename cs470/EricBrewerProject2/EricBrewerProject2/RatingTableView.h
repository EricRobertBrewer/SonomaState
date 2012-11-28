//
//  RatingTableView.h
//  EricBrewerProject2
//
//  Created by student on 3/6/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "DatabaseController.h"

#define NUM_RATINGS 5
typedef enum{ A,B,C,D,F } MovieRatings;
typedef enum{
    A_GRADE = 9,
    B_GRADE = 8,
    C_GRADE = 7,
    D_GRADE = 6,
    F_GRADE
} MovieGrades;

@interface RatingTableView : UITableViewController{
    
    NSArray *_all_movies;

    int _movies_with_grade[NUM_RATINGS];

    NSArray *_grade_index_names;
    NSArray *_grade_header_names;
    NSArray *_grade_footer_names;
}

- (id)initWithMovies:(NSArray *)movies;

@end
