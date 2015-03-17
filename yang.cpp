/******************************************************************************
-   yang.cpp
-   Prog Tools for Scits Engrs - CIVL 8903 Homework V
-
-   Homework Discription:
-   This assignment requires you to understand how to declare and manipulate a 
-   collections of objects using a arrays, enumerators, and structures. You
-   are expected to learn and to design and use functions in C++ using the ge-
-   neral style of the examples done in class, including declaration of param-
-   eters.
-
-   Author: Yang Yang
-
-   Github Repository: https://github.com/SwiftHickory/homework6.git
******************************************************************************/

#include <iostream>
#include <fstream>
#include <string>

#include "myFunction.h"

using namespace std;

// main function
int main() {

    ifstream inputFile;
    ofstream outputFile;
    string inputFileName;
    const string outputFileName = "yang.out";

    // prompt user for input file and open it
    cout << "Please Enter input file: ";
    cin >> inputFileName;
    openInput(inputFile, inputFileName);

    errorMessage("Opening file: " + inputFileName + "\n");
    errorMessage("Processing input...\n");

    headerProcessing(inputFile, outputFile, outputFileName);
    errorMessage("Header read correctly!\n");

    tableProcessing(inputFile, outputFile);
    errorMessage("Finished!\n");

    inputFile.close();
    outputFile.close();

    return 0;

}