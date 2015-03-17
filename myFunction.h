#ifndef MYFUNCTION_H
#define MYFUNCTION_H

const string logFileName = "yang.log";
ofstream logFile;

// function to open input file
void openInput(ifstream &inputFile, string fileName);

// function to open output file
void openOutput(ofstream &outputFile, string fileName);

// read header can then produce output header
void headerProcessing(ifstream &inputFile, ofstream &outputFile, string outputFileName);

// read table and then produce output
void tableProcessing(ifstream &inputFile, ofstream &outputFile);

// read and processing one entry
bool processOneEntry(ifstream &inputFile, station &entry, int entryNumber, string networkCode);

// check whether a string contains only digits
bool is_digits(string str);

// change all the letters in a string to lower case
string lowerString(string str);

// convert a int to string
string intToString(int num);

// function to print error message to both terminal and error file
void errorMessage(const string &message);

// function to print error message to both terminal and error file and then exit the program
void errorMessageWithExit(const string &message);

// print messeage to both terminal and a file
void printOutput(ofstream &outputFile, const string &message);

// deal with some left things to exit program safely
void finishProgram();

#endif