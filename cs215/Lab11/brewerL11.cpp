/*
Eric Brewer
CS215
Lab 11
*/

#include <iostream>
#include <fstream>
#include "LList2.tmp"
#include "card.h"
using namespace std;

int main()
{
  LList2<card> deck;
  card flip;

  ifstream fin;
  fin.open("cards.in");
  while(fin >> flip)
    deck.InsertLast(flip);
  cout << "The cards: " << deck << endl;
  //Reads the cards from the input file to create a deck of cards

  LList2<card> upperHalf, lowerHalf;
  int count = 0;
  for(LList2<card>::Iterator i = deck.begin(); count < deck.Size()/2; ++i)
    {
      upperHalf.InsertLast(*i);
      ++count;
    }
  cout << "Upper Half: " << upperHalf << endl;
  count = 0;
  for(LList2<card>::Iterator i = deck.rbegin(); count < deck.Size()/2; --i)
    {
      lowerHalf.InsertFirst(*i);
      ++count;
    }
  cout << "Lower Half: " << lowerHalf << endl;
  //Uses the Iterator to traverse the full list of cards
  //Essentially splits the deck into two piles of the same size

  LList2<card> shufDeck;
  LList2<card>::Iterator j = upperHalf.begin();
  LList2<card>::Iterator k = lowerHalf.begin();
  while(k != lowerHalf.end())
    {
      shufDeck.InsertLast(*j++);
      shufDeck.InsertLast(*k++);
    }
  cout << "Shuffled Deck: " << shufDeck << endl;
  //Inserts into the shuffled list the first element in the upper stack,
  // then the top of the lower stack, the the second of each, and so on

  return 0;
}
