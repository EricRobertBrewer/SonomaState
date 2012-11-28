/*
Eric Brewer
10/14/08
Rivoire
Project 2 - A simulation of an ice cream store.
 This project mostly manipulates file i/o commands
 as well as basic C++ function calls, function 
 declarations, etc. Much of the work done in the 
 project is done by the cooperation of both elements.
Lines - 127
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

void Menu(string todaysFlavor);
void CurrentInv(int numStart, int numSold);
int BuyScoops(int numStart, int numSold, float cost);
void PrintReport(int numStart, int numSold, float cost);

int main()
{
  float price = 0.0;
  string flavor = "no flavor";
  int scoopsStart = 0;
  int scoopsSold = 0;

  ifstream inFile;
  inFile.open("inventory.txt");
  if (inFile.fail())
    {
      cout << "Error: Inventory file not found.\n";
      return 0;
    }
  inFile >> price;
  inFile.ignore();
  getline(inFile, flavor);
  inFile >> scoopsStart;
  inFile.close();  
  //cout << price << endl;
  //cout << flavor << endl;
  //cout << scoopsStart << endl;

  string selection = "c";
  do
    {
      Menu(flavor);
      cin.clear();  // This is a key line. It discards the previous input to actually look at some new characters.
      cin >> selection;
      cout << endl;
      if (!cin.fail())
	{
	  if (selection != "i" && selection != "b" && selection != "r")
	    cout << "Error: Invalid menu selection.\n";
	  if (selection == "i")
	    CurrentInv(scoopsStart, scoopsSold);
	  if (selection == "b")
	    scoopsSold += BuyScoops(scoopsStart, scoopsSold, price);
	}
      else
	cout << "Error: Invalid menu selection.\n";
      cout << "+--------------------------------+\n";
    } while (selection != "r");
  
  PrintReport(scoopsStart, scoopsSold, price);
  
  return 0;
}

void Menu(string todaysFlavor)  // Displays the menu screen.
{
  cout << "Welcome to Eric's ice cream store!\n\n"
       << "Press i to print the current inventory.\n\n"
       << "Press b to buy some ice cream.\n"
       << "  The flavor of the day is " << todaysFlavor << ".\n\n"
       << "Press r to print a report and exit.\n";
}

void CurrentInv(int numStart, int numSold)  // Prints how many scoops I have left.
{
  cout << "Current inventory: " << (numStart - numSold) << " scoops left.\n";
}

int BuyScoops(int numStart, int numSold, float cost)  // This function only returns how many scoops just sold to a customer.
{
  cout << "How many scoops, sir or madame?\n";
  int scoopsInTransit = 0;
  cin >> scoopsInTransit;
  if (!cin.fail())  // As long as the input didn't fail...
    {
      if (scoopsInTransit <= (numStart - numSold))  // As long as I enough scoops left to satisfy their order...
	{
	  if (scoopsInTransit < 0)  // And as long as their order isn't negative...
	    {
	      cout << "Error: Invalid scoops request.\n";
	      return 0;
	    }
	  else  // I will confirm their order and update my scoop count.
	    {
	      cout << "Thank you, that'll be $" << fixed << setprecision(2) << (scoopsInTransit * cost) << ".\n";
	      return scoopsInTransit;
	    }
	}
      else
	{
	  cout << "Error: I don't have enough scoops...\n";
	  return 0;
	}
    }
  else 
    {
      cout << "Error: Invalid scoops request.\n";
      return 0;
    }
}

void PrintReport(int numStart, int numSold, float cost)  // Creates a readable report file.
{
  ofstream outFile;
  outFile.open("report.txt");
  if (!outFile.fail())
    {
      cout << "Creating file report.txt ...\n";
      outFile << "Revenue: $" << fixed << setprecision(2) << (numSold * cost) << endl;
      outFile << "Scoops remaining: " << (numStart - numSold) << endl;
    }
  else
    cout << "Error: Could not create report file.\n";
  outFile.close();
}
