/*
 * Zack L.
   CS 210
   02/22/25
   */

#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <map>	
#ifndef HEADER_H
#define HEADER_H
using namespace std;

//Declaring the class Groceries
class Groceries
{
private:
	// Neccessary declarations for receiving file data
	string fileInput;
	string fileOutput;
	string name;
	int quantity;
	map<string, int> grocContainer;
	

public:
	// Constructor
	void Grocery();
	// Inputting values into the constructor
	void Grocery(string fileInput, string fileOutput);

	// Function for printing menu option 1
	void MenuOption1();
	// Function for printing menu option 2
	void MenuOption2();
	//Function for printing menu option 3
	void MenuOption3();
	
	// Function for taking inputs and reading information
	void InventoryItem();
	
};
#endif
