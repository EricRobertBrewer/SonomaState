/*
brewereP3.cpp
Eric Brewer
10/30/08
Rivoire - CS115
Project 3: Election Night
  Potentially tracks the US Presidential
  elections as soon as they are announced. 
  Continually receives input from the user
  as to which candidate took the electoral 
  votes from any state. Announces a winner
  once one emerges or announces a tie 
  should one unfortunately happen.
Lines - 198
*/

#include <iostream>
#include <string>
#include "elections.h"
/* Contains:
   const int NUM_STATES = 51;
   const int TOTAL_NUM_VOTES = 528;
   const int MAJORITY_VOTES = 270;

   const string POSTAL_CODES[NUM_STATES] = {AL, AK, ...};
   const int STATE_NUMVOTES[NUM_STATES] = {9, 3, ...};
     These two arrays are parallel - the ith element of both arrays 
     correspond to a state and its number of electoral votes.
 */

const string STATE_NAMES[NUM_STATES] = 
  {
    "Alabama", "Alaska", "Arizona", "Arkansas", "California",
    "Colorado", "Connecticut", "Washington D.C.", "Delaware", "Florida", 
    "Georgia", "Hawaii", "Idaho", "Illinois", "Indiana", 
    "Iowa", "Kansas", "Kentucky", "Louisiana", "Maine", 
    "Maryland", "Massachusetts", "Michigan", "Minnesota", "Mississippi",
    "Missouri", "Montana", "Nebraska", "Nevada", "New Hampshire",
    "New Jersey", "New Mexico", "New York", "North Carolina", "North Dakota", 
    "Ohio", "Oklahoma", "Oregon", "Pennsylvania", "Rhode Island", 
    "South Carolina", "South Dakota", "Tennessee", "Texas", "Utah",
    "Vermont", "Virginia", "Washington", "West Virginia", "Wisconsin", "Wyoming" 
  };

using namespace std;

void MenuPrompt();
void UpdateVotes(int cand1[], int cand2[]);
void ShowResults(int cand1[], int cand2[], int size, int allVotes);
void ErrorMsg();
void InitArray(int array[], int size);
int TotalArray(int array[], int size);

int main()
{
  int inMenu = 0;                       // Menu input value,
  int votesObama[NUM_STATES];           
  int votesMcCain[NUM_STATES];          // Arrays for the state votes for each candidate.
  InitArray(votesObama, NUM_STATES);
  InitArray(votesMcCain, NUM_STATES);   // Initializes every element of both arrays to 0.

  do
    {
      MenuPrompt();
      cin.clear();
      cin >> inMenu;
      if (!cin.fail())
	{
	  if (inMenu == 1 || inMenu == 2 || inMenu == 3)
	    {
	      if (inMenu == 1)
		UpdateVotes(votesObama, votesMcCain);
	      if (inMenu == 2)
		ShowResults(votesObama, votesMcCain, NUM_STATES, TOTAL_NUM_VOTES);
	    }
	  else
	    ErrorMsg();
	}
      else
	ErrorMsg();
      if (TotalArray(votesObama, NUM_STATES) >= MAJORITY_VOTES)
	cout << "Obama has won!\n";
      if (TotalArray(votesMcCain, NUM_STATES) >= MAJORITY_VOTES)
	cout << "McCain has won!\n";
      if (TotalArray(votesObama, NUM_STATES) == (MAJORITY_VOTES - 1) 
	   && TotalArray(votesMcCain, NUM_STATES) == (MAJORITY_VOTES -1))
	cout << "The election is a tie! (How very unfortunate.)\n";
    } while (inMenu != 3);

	  cout << "Thank you for playing the politics game.\n";

  return 0;
}

void MenuPrompt() // Prints out a beautiful menu screen.
{
  cout << "==========================================\n\n"
       << "+----------------------------------------+\n"
       << "| !                                    ! |\n"
       << "|     US Presidential Elections '08      |\n"
       << "| !                                    ! |\n"
       << "+----------------------------------------+\n"
       << "| Enter your choice:                     |\n"
       << "|    1    Update results for a state     |\n"
       << "|    2    View current results           |\n"
       << "|    3    Quit                           |\n"
       << "+----------------------------------------+\n";
}

void UpdateVotes(int cand1[], int cand2[]) // The big one. Checks for invalid input in both the postal
{                                          //  code and the winner input. Updates both candidates' arrays.
  string inPostal = "XX";  // Two-letter postal code input.
  int index = 0;           // Extracts the loop counter and makes it usable later as array positions.
  bool stateFound = false; // Keeps track of if the user's postal code is valid.
  int inStateWinner = 0;   // Used for the winner of the state if the postal code checks true.
  cout << "#--- Update a State's Results ---#\n"
       << "Enter the state's two-letter postal code:\n";
  cin >> inPostal;
  cout << endl;
  if (!cin.fail())
    {
      for (int i = 0; i < NUM_STATES; i++)
	{
	  if (inPostal == POSTAL_CODES[i])
	    {
	      index = i;
	      stateFound = true;
	      cout << "#--- Update a State's Results ---#\n"
		   << STATE_NAMES[index] << " has " << STATE_NUMVOTES[index] << " electoral votes.\n"
		   << "Who won " << STATE_NAMES[index] << "?\n"
		   << "    1    Obama\n"
		   << "    2    McCain\n"
		   << "    3    Undecided\n";
	      cin >> inStateWinner;
	      if (!cin.fail())
		{
		  if (inStateWinner == 1)
		    {			
		      cand1[index] = 0;
		      cand2[index] = 0;
		      cand1[index] = STATE_NUMVOTES[index];
		      cout << "\n\n";
		    }
		  if (inStateWinner == 2)
		    {
		      cand1[index] = 0;
		      cand2[index] = 0;
		      cand2[index] = STATE_NUMVOTES[index];
		      cout << "\n\n";
		    }
		  if (inStateWinner == 3)
		    {
		      cout << "OK, take your time.\n\n";
		    }
		  if (inStateWinner != 1 && inStateWinner != 2 && inStateWinner != 3)
		    ErrorMsg();
		}
	      else
		ErrorMsg();
	    }
	}
      if (!stateFound)
	cout << "Your state was not found.\n\n";
    }
  else
    ErrorMsg();
}

void ShowResults(int cand1[], int cand2[], int size, int allVotes) // Displays the current results.
{
  cout << "#--- Current Results ---#\n"
       << "Obama (D):   " << TotalArray(cand1, size) << " votes\n"
       << "McCain (R):  " << TotalArray(cand2, size) << " votes\n"
       << "TBA:         " << (allVotes - TotalArray(cand1, size) - TotalArray(cand2, size)) 
       << " votes\n\n";
}

void ErrorMsg() // General error message. This could be used in anything.
{
  cout << "Invaild input. Try again.\n\n";
}

void InitArray(int array[], int size) // Very general array initializer. May be used for any size array.
{
  for (int i = 0; i < size; i++)
    {
      array[i] = 0;
    }
}

int TotalArray(int array[], int size) // Totals the numbers in an array of ints of any size.
{
  int total = 0;
  for (int i = 0; i < size; i++)
    {
      total += array[i];
    }
  return total;
}
