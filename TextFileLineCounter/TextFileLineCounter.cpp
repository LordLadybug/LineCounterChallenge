// ConsoleApplication2.cpp : Defines the entry point for the console application.
//Line counting program that takes in a text file and outputs the number of lines in the file

#include "stdafx.h"
#include <iostream>
#include <fstream>

using namespace std;

//Test file generator
void FileGenerator(std::string filename, std::string testText);

//Line counting function
int count(std::string filename);

int main()
{
	string Filename;	//text file we will read with count

	/*RUNNING TESTS*/
	/*TEST 1: Empty text file (Expected line count: 0) */
	//create and save an empty file
	Filename.assign("EmptyFile.txt");
	FileGenerator(Filename, ""); //make sure "" actually gives an empty string
	//Then run line counter and compare to expected line count
	int EmptyLineCount = count(Filename);
	cout<<"Empty Text File\n Number of Lines: "<<EmptyLineCount;
	if (EmptyLineCount != 0) perror("Expected Line Count: 0");
	
	/*TEST 2: Text file with one line of text (Expected line count: 1) */
	Filename.assign("OneLine.txt");
	FileGenerator(Filename, "aa");
	int OneLineCount = count(Filename);
	cout << "Text File with One Line\n Number of Lines: " << OneLineCount;
	if (OneLineCount != 1) perror("Expected Line Count: 1");

	/*TEST 3: Empty line, followed by two text lines separated by two empty lines
		(Expected line count: 5) */
	Filename.assign("TwoLineWithSpaces.txt");
	FileGenerator(Filename, "\n aa \n\n aa");
	int LinesWithSpacesCount = count(Filename);
	cout << "Three empty lines, two filled lines\n Number of Lines: " << LinesWithSpacesCount;
	if (LinesWithSpacesCount != 5) perror("Expected Line Count: 5");

	/*TEST 4: Take a user-generated file, and output the line count*/
	//input name of file and organize into string
	Filename.clear();
	cout << "Enter filename:\n";
	cin.getline(Filename, sizeof(Filename));
	cin.ignore();
	int LineCount = count(Filename);
	cout << LineCount;
	cin.get();
	return 0;
}


void FileGenerator(std::string filename, std::string testText) {
	ofstream TextFileDesired(filename, ios_base::out);	//created to manipulate files with name Filename
	TextFileDesired.clear();
	TextFileDesired.open(filename);
	//if no such file already exists, save text file disk here
	if (!TextFileDesired.is_open()) {
		TextFileDesired << testText;
	}
	TextFileDesired.close();
}

int count(std::string filename) {
	ifstream TextFileDesiree(filename, ios_base::in);	//created to manipulate files with name Filename//Load file

	int LineCounter = 0;
	while (!TextFileDesiree.eof()) {
		//If reaching end of file (denoted by a special character?) then close file and end loop
		//	....
		//Read a line, then increment counter by 1
		std::string Throwaway;
		std::basic_istream::getline(Throwaway, TextFileDesiree);
		LineCounter += 1;
	}
	TextFileDesiree.close();
	return LineCounter;
}