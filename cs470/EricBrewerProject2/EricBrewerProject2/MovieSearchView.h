//
//  MovieSearchView.h
//  EricBrewerProject2
//
//  Created by student on 3/5/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef enum{
    TITLE,
    PLOT
} SegControlButtons;

@interface MovieSearchView : UIViewController{
    
    NSArray *_all_movies;
    
    IBOutlet UITextField *_query_text;
    IBOutlet UISegmentedControl *_category_select;
    IBOutlet UIButton *_button;
}

- (id)initWithMovies:(NSArray *)movies;
- (IBAction)didTapSearch:(id)sender;

@end
