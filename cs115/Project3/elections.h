/* **************************************************************
 * elections.h
 *
 * CS 115 Proj. 3
 *
 * This file contains two arrays: POSTAL_CODES and STATE_NUMVOTES.
 * It also defines the integer constants NUM_STATES, TOTAL_NUM_VOTES,
 *    and MAJORITY_VOTES.
 * You may use these three variables in your program.
 *
 * For any "i", the "ith" entry in POSTAL_CODES and STATE_NUMVOTES
 * refers to the same state.
 *
 * ************************************************************* */
using namespace std;

const int NUM_STATES = 51;  // 50 states + DC
const int TOTAL_NUM_VOTES = 538; // The total number of votes in the electoral college
const int MAJORITY_VOTES  = 270; // The minimum number of electoral votes needed to win 

/* Array of 2-letter postal codes */
const string POSTAL_CODES[NUM_STATES] =
   { "AL", "AK", "AZ", "AR", "CA", 
     "CO", "CT", "DC", "DE", "FL",
     "GA", "HI", "ID", "IL", "IN",
     "IA", "KS", "KY", "LA", "ME", 
     "MD", "MA", "MI", "MN", "MS", 
     "MO", "MT", "NE", "NV", "NH", 
     "NJ", "NM", "NY", "NC", "ND",
     "OH", "OK", "OR", "PA", "RI",
     "SC", "SD", "TN", "TX", "UT",
     "VT", "VA", "WA", "WV", "WI", "WY" 
   };

/* Array of electoral vote counts for each state */
const int STATE_NUMVOTES[NUM_STATES] = 
   {  9,  3, 10,  6, 55,      // AL to CA
      9,  7,  3,  3, 27,      // CO to FL
     15,  4,  4, 21, 11,      // GA to IN
      7,  6,  8,  9,  4,      // IA to KS
     10, 12, 17, 10,  6,      // MD to MS
     11,  3,  5,  5,  4,      // MO to NH
     15,  5, 31, 15,  3,      // NJ to ND
     20,  7,  7, 21,  4,      // OH to RI
      8,  3, 11, 34,  5,      // SC to UT
      3, 13, 11,  5, 10, 3
   };

