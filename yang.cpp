/******************************************************************************
-   yang.cpp
-   Prog Tools for Scits Engrs - CIVL 8903 Homework VI
-
-   Homework Discription:
-   Redo of homework 5
-
-   Author: Yang Yang
-
-   Github Repository: https://github.com/SwiftHickory/homework6.git
******************************************************************************/

#include "station.h"

using namespace std;

const extern string logFileName = "yang.log";
extern ofstream logFile;

// main function
int main() {

    string inputFileName;
    const string outputFileName = "yang.out";
    ifstream inputFile;
    ofstream outputFile;
    earthquake eq;

    // prompt user for input file and open it
    cout << "Please Enter input file: ";
    cin >> inputFileName;
    openInput(inputFile, inputFileName);

    errorMessage("Opening file: " + inputFileName + "\n");
    errorMessage("Processing input...\n");

    headerProcessing(inputFile, outputFile, outputFileName, eq);
    errorMessage("Header read correctly!\n");

    tableProcessing(inputFile, outputFile, eq);
    errorMessage("Finished!\n");

    inputFile.close();
    outputFile.close();

    finishProgram();

    return 0;

}