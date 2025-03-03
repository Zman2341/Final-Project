/*
 * Zack L.
   CS 210
   02/22/25
   */

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Header.h"
using namespace std;

// Function "Filler" for creating proper spacing and lines for DisplayMenuOption() and InputError()
string Filler(int count, char s)
{
	string output = "";
	for (int i = 0; i < count; ++i)
	{
		output = output + s;
	}
	return output;
}

// Function for displaying all menu options for the user to select
void DisplayMenuOption()
{
	cout << Filler(50, '*') << endl;
	cout << "Select the option you prefer, and enter 1-4." << endl;
	cout << "Option 1 - Enter a word" << endl;
	cout << "Option 2 - Print the list with numbers" << endl;
	cout << "Option 3 - Print the list in a Histogram" << endl;
	cout << "Option 4 - Exit the Program" << endl;
	cout << Filler(50, '*') << endl;
}

// Function for displaying an error message when the user doesn't enter one of the correct response options
void InputError()
{
	cout << Filler(50, '*') << endl;
	cout << "*** Error! Please make a Valid Selection '1-4' ***" << endl;  // 50 spaces
	cout << Filler(50, '*') << endl;
}

// Main function
int main()
{
	// Declaring the variables and class being used
	Groceries inventory;
	int selection = 0;
	bool exitProgram = false;
	
	// Constructor to create the new class
	inventory.Grocery();

	// Create all the files for the new class item
	inventory.InventoryItem();
	
	// loop for running the Main menu display messages
	while (exitProgram != true)
	{
		// Display function to show all available options
		DisplayMenuOption();
		cout << "Your selection:";
		cin >> selection;
		cout << Filler(50, '#') << endl << endl;

		// looping the function until the user makes a selection of 4
		// and displaying an error message when a proper input response is not recieved
		switch (selection)
		{
		case 1: 
			inventory.MenuOption1();
			break;

		case 2: 
			inventory.MenuOption2();
			break;

		case 3: 
			inventory.MenuOption3();
			break;

		case 4: 
			exitProgram = true;
			break;
		
		default: 
			InputError();
		}
	}
	// Displaying the exit message
	cout << "Shutting program down.";
	
	return 0;
}
