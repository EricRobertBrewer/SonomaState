//
//  DatabaseController.h
//


#import <Foundation/Foundation.h>
#import <sqlite3.h>
#import "Movie.h"

@interface DatabaseController : NSObject {
    
    NSString *dbpath;
	sqlite3 *database;
    
    NSArray *threadListCache;
    
    
    NSArray *getAllMovieCache;
    
}


- (NSArray *)getAllMovies;                                    // returns a NSArray of all Movie objects found in the database
- (NSArray *)getAllMoviesBeginningWithCharacter:(unichar)c;   
- (NSArray *)getAllDistinctGenre;                             // returns a NSArray of NSString's
- (NSArray *)getAllMoviesWithGenre:(NSString *)genre;         // returns a NSArray of Movie objects with the given genre
//- (NSArray *)getAllDistinctRating;                            // returns a NSArray of floats
//- (NSArray *)getAllMoviesWithDistinctRating:(double)rating;   // returns a NSArray of Movie objects with a rating 
- (void)openDatabase;
- (void)closeDatabase;

+ (DatabaseController *)sharedInstance;             // get a pointer to this singleton class


@end
