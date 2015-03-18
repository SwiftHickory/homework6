#include "myFunction.h"

const string logFileName = "yang.log";
ofstream logFile;

// function to open input file
void openInput(ifstream &inputFile, string fileName) {

    inputFile.open(fileName.c_str());

    // perform sanity check it
    if (!inputFile.is_open()) {
        errorMessageWithExit("Cannot open input file: " + fileName + "\n");
    }

}

// function to open output file
void openOutput(ofstream &outputFile, string fileName) {

    outputFile.open(fileName.c_str());

    // perform sanity check it
    if (!outputFile.is_open()) {
        if (fileName == logFileName) {
            // if we can open error file, just print out to terminal
            cout << "Cannot open log file: " << logFileName << endl;
        } else {
            errorMessageWithExit("Cannot open output file: " + fileName + "\n");
        }
    }

}

// check whether a string contains only digits
bool is_digits(string str) {

    for (int i = 0; i < str.length(); i++) {
        if (!isdigit(str[i])) {
            return false;
        }
    }

    return true;

}

// change all the letters in a string to lower case
string lowerString(string str) {

    for (int i = 0; i < str.length(); i++) {
        str[i] = tolower(str[i]);
    }

    return str;

}

// change all the letters in a string to upper case
string upperString(string str) {

    for (int i = 0; i < str.length(); i++) {
        str[i] = toupper(str[i]);
    }

    return str;

}

// convert a int string
string intToString(int num) {

    ostringstream numStream;
    numStream << num;

    return numStream.str();

}

// function to print error message to both terminal and error file
void errorMessage(const string &message) {

    // check whether the error file is opened
    if (!logFile.is_open()) {
        openOutput(logFile, logFileName);
    }

    printOutput(logFile, message);

}

// function to print error message to both terminal and error file and then exit the program
void errorMessageWithExit(const string &message) {

    errorMessage(message);

    exit(EXIT_FAILURE);

}

// print messeage to both terminal and a file
void printOutput(ofstream &outputFile, const string &message) {

    cout << message;
    outputFile << message;

}

// deal with some left things to exit program safely
void finishProgram() {

	// if open error file, close it
    if (logFile.is_open()) {
        logFile.close();
    }

}