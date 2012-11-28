// Lab 8 Part 1 application program
// Author: Dr. Watts
// Data: Spring 2005
// Description: This program is designed to test the AList class.

#include <iostream>
#include <fstream>
#include "AList.h"

using namespace std;

int main (int argc, char * argv[])
{
// Test for existence of file name argument
	if (argc < 2)
	{
		cerr << "Usage: " << argv[0] << " <file-name>\n";
		exit (1);
	}

// Test to see if file was opened
	ifstream ins (argv[1]);
	if (ins.fail ())
	{
		cerr << "No file " << argv[1] << " found\n";
		exit (2);
	}
	
	AList AL;
	char action;
	int value;

	while (ins >> action)
	    switch (action)
	    {
		case 'C' : cout << AL.Capacity() << endl;
			   break;
		case 'D' : ins >> value;
			   if (AL.Delete (value))
				cout << value << " deleted from list\n";
			   else
				cout << value << " not deleted from list\n";
			   break;
		case 'I' : ins >> value;
			   if (AL.Insert (value))
				cout << value << " inserted in list\n";
			   else
				cout << value << " not inserted in list\n";
			   break;
		case 'U' : cout << AL.Used() << endl;
			   break;
		case 'W' : cout << AL << endl;
			   break;
		default :  cout << action << " is not a valid option\n";
	    }
	return 0;
}
