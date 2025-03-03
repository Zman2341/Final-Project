/*
 * Zack L.
   CS 210
   02/22/25
   */

#include "Header.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>			
#include <string>
using namespace std;

// Constructor
void Groceries::Grocery()
{
	fileInput = "Project_Three_Input_File.txt";
	// Assigning input file
	fileOutput = "frequency.dat";
	name = "";
	quantity = 0;
}

// Inputting values to the Constructor
void Groceries::Grocery(string Input, string Output)
{
	fileInput = Input;
	fileOutput = Output;
	name = "";
	quantity = 0;
}

// Printing menu option one
void Groceries::MenuOption1()
{
	bool exit = false;

	while (!exit) {
		cout << "Please enter a word to search for or [q] to quit... ";
		cin >> name;
		
		// Verifying valid user response
		try {
			// checking user response
			for (char a : name)
			{
				if (!isalpha(a))
				{
					throw invalid_argument("Not a valid string. Must enter letters");
				}
			}
			// Once determined it is a valid word we search the map
			// If the given word is found in the map
			if (grocContainer.find(name) != grocContainer.end())
			{
				cout << "Found! There are " << grocContainer[name] << " " << name << "." << endl;
			}
			// If the given word was NOT found in the map
			else
			{
				throw invalid_argument("Could not find any " + name);
			}
		}

		// Displaying an error message
		catch(invalid_argument& e)
		{
			cout << "**ERROR** - " << e.what() << endl;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');;
			cin.clear();
		}

		// option for user to exit
		if (name == "q")
		{
			exit = true;
		}
		cout << endl;
	}
}

// Printing menu option two
void Groceries::MenuOption2()
{
	// Drawing lines accross the displayed data for the user to find the assigned numbers more easily
	for (auto iterate = grocContainer.begin(); iterate != grocContainer.end(); ++ iterate)
	{
		cout << left << setw(30) << iterate->first << setfill('.') << iterate->second << endl;
	}
	cout << endl;
}

// Printing menu option three
void Groceries::MenuOption3()
{
	//Loop for verifying if each word in the map is followed by the correct number of star symbols
	for (auto iterate = grocContainer.begin(); iterate != grocContainer.end(); ++iterate)
	{
		// Printing the item name
		cout << iterate->first << " ";
		// Printing a star symbol for every iteration on the map
		for (int i = 0; i < iterate->second; ++ i)
		{
			cout << "*";
		}
		cout << endl;
	}
	cout << endl;
}

//
// For reading data from the input file and outputing it to the new file
void Groceries::InventoryItem()
{
	string tempName;
	ifstream inFS;
	// File Input
	ofstream outFS;
	// File Output

	// Openning both the Input and Output files
	inFS.open(fileInput);
	outFS.open(fileOutput);

	// An error message is displayed if the input file is unable to be openned
	if (!inFS.is_open())
	{
		cout << "Could not open file " << fileInput << endl;
		return;
	}

	// An error message is displayed if the output file is unable to be openned
	if (!outFS.is_open())
	{
		cout << "Could not open file " << fileOutput << endl;
		return;
	}

	// Data read from Input file stored to a map temporarily
	while (!inFS.fail())
	{
		getline(inFS, name);
		while (getline(inFS, name))
		{
			inFS >> tempName;
			// Adding another tick for each time the name is found
			if (grocContainer.count(tempName))
			{
				grocContainer[tempName] += 1;
			}

			// Otherwie if the first instance the name is found in the map
			else
			{
				grocContainer.insert(pair<string, int>(tempName, 1));
			} 
		}
	}
	
	// Loop that goes through each item in the map and sends to the Output file
	for (auto itr = grocContainer.begin(); itr != grocContainer.end(); ++itr)
	{
		outFS << itr->first << " " << itr->second << endl;
	}

	// Closing the Input file
	inFS.close();
	// Closing the Output File
	outFS.close();
}
