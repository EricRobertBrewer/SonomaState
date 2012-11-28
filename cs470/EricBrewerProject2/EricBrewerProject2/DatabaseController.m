//
//  DatabaseController.m
//

#import "DatabaseController.h"

static DatabaseController *sharedInstance = nil;

#define DB_NAME @"moviedb.sqlite"

@implementation DatabaseController

- (id)init {
    
    if ((self = [super init]) == nil) return nil;
    
    NSLog(@"DatabaseController init()");
    
    dbpath = [[[NSBundle mainBundle] pathForResource:@"moviedb" ofType:@"sqlite"] retain];
    NSLog(@"DatabaseController dbpath = %@", dbpath);

    database = nil;
    [self openDatabase]; // open the database on init
    
    return self;
}


- (void)openDatabase {
    
    assert(dbpath);
    
    BOOL dbexists = [[NSFileManager defaultManager] fileExistsAtPath:dbpath];
    if (!dbexists) {
        NSLog(@"Database file not found at path = %@. App cannot continue", dbpath);
        exit(EXIT_FAILURE);
    }
    
    if (!database) {
        if (sqlite3_open([dbpath UTF8String], &database) != SQLITE_OK) {
            NSLog(@"[DB ERROR] failed open DB!");
            exit(EXIT_FAILURE);
        } 
    }
    
    assert(database);
        
}


- (void)closeDatabase {
    if (database) {
        sqlite3_close(database);
        database = nil;
    }
    assert(!database);
}


- (NSSet *)getGenresForMovie:(Movie *)movie {
    
    assert(movie);
    assert(movie.ID);
    
    [self openDatabase];
    
//    NSLog(@"[DATABSE] getGenresForMovie(%@)", movie);
    
    NSMutableSet *genres = [[NSMutableSet alloc] init];
    
    const char *sql = [[NSString stringWithFormat:@"SELECT `genre` FROM `genres` WHERE `movieid` = %d;", movie.ID] cStringUsingEncoding:NSUTF8StringEncoding];
    sqlite3_stmt *stmt = nil;
    
    if (sqlite3_prepare_v2(database, sql, -1, &stmt, NULL) == SQLITE_OK) {	// prepare binary query
        while(sqlite3_step(stmt) == SQLITE_ROW) {	// step through all rows of the result set
     
            NSString *genre = [NSString stringWithCString:(char *)sqlite3_column_text(stmt, 0) encoding:NSUTF8StringEncoding];
            [genres addObject:genre];
            
        }
    }
    
    return [genres autorelease];
}


- (NSArray *)getAllMovies {
    
    if (getAllMovieCache) {
        // we have a cache already built! just return that
        NSLog(@"[DATABSE] getAllMovies() cache hit!");
        return getAllMovieCache;
    }

    NSLog(@"[DATABASE] getAllMovies(), this might be a little slow!");
    
    
    [self openDatabase];
    
    NSMutableArray *movies = [[NSMutableArray alloc] init];
    
    const char *sql = "SELECT * FROM `movies` ORDER BY `TITLE`;";
    sqlite3_stmt *stmt = nil;
    
    if (sqlite3_prepare_v2(database, sql, -1, &stmt, NULL) == SQLITE_OK) {	// prepare binary query
        while(sqlite3_step(stmt) == SQLITE_ROW) {	// step through all rows of the result set
            
            Movie *newMovie = [[Movie alloc] init];
            
            int idx = 0;
            
            newMovie.ID             = sqlite3_column_int(stmt, idx++);
            newMovie.TITLE          = [NSString stringWithCString:(char *)sqlite3_column_text(stmt, idx++) encoding:NSUTF8StringEncoding];
            newMovie.YEAR           = sqlite3_column_int(stmt, idx++);
            newMovie.IMDB_RATING    = (float)sqlite3_column_double(stmt, idx++);
            newMovie.IMDB_URL       = [NSString stringWithCString:(char *)sqlite3_column_text(stmt, idx++) encoding:NSUTF8StringEncoding];
            newMovie.POSTER_NAME    = [NSString stringWithCString:(char *)sqlite3_column_text(stmt, idx++) encoding:NSUTF8StringEncoding];
            newMovie.PLOT           = [NSString stringWithCString:(char *)sqlite3_column_text(stmt, idx++) encoding:NSUTF8StringEncoding];
            newMovie.GENRES         = [self getGenresForMovie:newMovie];
            
            [movies addObject:newMovie];
            [newMovie release];  // release because we alloced
            
        }
    } else {
        NSLog(@"Database appears to be empty! This is a fatal error.");
        exit(EXIT_FAILURE);
    }
    
    NSLog(@"getAllMovies() returning %d movies", movies.count);

    // cache this result if we can!
    if (!getAllMovieCache && movies.count) getAllMovieCache = [[NSArray arrayWithArray:movies] retain];
    
    return [movies autorelease];  // auto release as we alloced and now are no longer responsible
    
}


- (NSArray *)getAllMoviesBeginningWithCharacter:(unichar)c{
    
    NSMutableArray *movies = [[NSMutableArray alloc] init];
    
    NSArray *allMovies = [self getAllMovies];
    
    for( Movie *mov in allMovies )
        if( [mov.TITLE characterAtIndex:0] == c )
            [movies addObject:mov];
    
    return [movies autorelease];
}


- (NSArray *)getAllDistinctGenre {
    
    [self openDatabase];
    
    NSLog(@"[DATABSE] getAllDistinctGenre()");
    
    NSMutableArray *genres = [[NSMutableArray alloc] init];
    
    const char *sql = "SELECT DISTINCT `genre` FROM `genres` ORDER BY `genre`;";
    sqlite3_stmt *stmt = nil;
    
    if (sqlite3_prepare_v2(database, sql, -1, &stmt, NULL) == SQLITE_OK) {	// prepare binary query
        while(sqlite3_step(stmt) == SQLITE_ROW) {	// step through all rows of the result set
            
            NSString *genre = [NSString stringWithCString:(char *)sqlite3_column_text(stmt, 0) encoding:NSUTF8StringEncoding];
            [genres addObject:genre];
            
        }
    } else {
        NSLog(@"Database appears to be empty! This is a fatal error.");
        exit(EXIT_FAILURE);
    }
    
    NSLog(@"getAllDistinctGenre() returning %d genres", genres.count);
    
    return [genres autorelease];  // auto release as we alloced and now are no longer responsible
    
}


- (NSArray *)getAllMoviesWithGenre:(NSString *)genre {
    
    assert(genre);
    
    NSMutableArray *movies = [[NSMutableArray alloc] init];
    
    NSArray *allMovies = [self getAllMovies];
    
    for (Movie *mov in allMovies) {
        // does this movies genres set contain the genre we are looking for?
        if ([mov.GENRES containsObject:genre]) {
            [movies addObject:mov];
        }
    }
    
    
    return [movies autorelease];
}

// -------------------------------------------------------------------------------------------------------
// Singleton stuff -- no need to ever modify code below here, it is correct.
// -------------------------------------------------------------------------------------------------------


+ (DatabaseController *)sharedInstance {
	@synchronized(self) {
		if (sharedInstance == nil) {
			sharedInstance = [[DatabaseController alloc] init];
		}
	}
	return sharedInstance;
}


+ (id)allocWithZone:(NSZone *)zone {
	@synchronized(self) {
		if (sharedInstance == nil) {
			sharedInstance = [super allocWithZone:zone];
			return sharedInstance; // assignment and return on first allocation
		}
	}
	return nil; // on subsequent allocation attempts return nil
}

- (id)copyWithZone:(NSZone *)zone {
	return self;
}


- (id)retain {
	return self;
}


- (unsigned)retainCount {
	return UINT_MAX; // denotes an object that cannot be released
}


- (oneway void)release {
	//do nothing
}


- (id)autorelease {
	return self;
}


@end
