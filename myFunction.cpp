#include <iostream>
#include <cctype>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>

#include "myFunction.h"
#include "earthquake.h"
#include "station.h"

using namespace std;

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

// read header from input file
void headerProcessing(ifstream &inputFile, ofstream &outputFile, string outputFileName) {

    string eventID, date, time, timeZone, earthquakeName;
    double evlo, evla, evdp;
    string magnitudeType;
    float magnitude;
    earthquake eq;

    // first line is event ID
    getline(inputFile, eventID);
    setEventID(eventID, eq);

    // second line is date time and time zone
    inputFile >> date >> time >> timeZone;
    setDate(date, eq);
    setTime(time, eq);
    setTimeZone(timeZone, eq);

    // third line is earthquake name
    // avoid the enter key of last line
    getline(inputFile, earthquakeName);
    getline(inputFile, earthquakeName);
    setEarthquakeName(earthquakeName, eq);

    // forth line is events information
    inputFile >> evlo >> evla >> evdp >> magnitudeType >> magnitude;
    setEvlo(evlo, eq);
    setEvla(evla, eq);
    setEvdp(evdp, eq);
    setMagnitudeType(magnitudeType, eq);
    setMagnitude(magnitude, eq);

    // if all the infomation are correct, then write output header
    openOutput(outputFile, outputFileName);

    outputFile << "# " << getDay(eq) << " " << getMonth(eq) << " " << getYear(eq) << " ";
    outputFile << getTime(eq) << " " << getTimeZone(eq) << " " << getMagnitudeType(eq) << " " << getMagnitude(eq) << " ";
    outputFile << getEarthquakeName(eq) << " [" << getEventID(eq) << "] (";
    outputFile << getEvlo(eq) << ", " << getEvla(eq) << ", " << getEvdp(eq) << ")" << endl;

}

// read table and then produce output
void tableProcessing(ifstream &inputFile, ofstream &outputFile) {

    int numberOfValidEntries = 0;
    int numberOfEntryRead = 0;
    int numberOfSignals = 0;
    string networkCode;
    bool isValidEntry = true;
    static const int maximumValidEntries = 300;
    station entry[maximumValidEntries];

    // read the file to the end of the file or reach maximum valid entry number
    while (inputFile >> networkCode && numberOfValidEntries < maximumValidEntries) {
        numberOfEntryRead++;

        if (processOneEntry(inputFile, entry[numberOfValidEntries], numberOfEntryRead, networkCode)) {
            numberOfSignals += entry[numberOfValidEntries].orientation.length();
            numberOfValidEntries++;;
        }
    }

    outputFile << numberOfSignals << endl;
    
    // print all the signals to output file
    for (int i = 0; i < numberOfValidEntries; i++) {
    	string orientation = getOrientation(entry[i]);

        for (int j = 0; j < orientation.length(); j++) {
            stringstream singalStream;
            singalStream << getNetworkCode(entry[i]) << ".";
            singalStream << getStationCode(entry[i]) << ".";
            singalStream << getBandType(entry[i]);
            singalStream << getInstrumentType(entry[i]);
            singalStream << orientation[j] << endl;

            outputFile << singalStream.str();
        }
    }

    errorMessage("Total invalid entries ignored: " + toString(numberOfEntryRead - numberOfValidEntries) + "\n");
    errorMessage("Totoal valid entries read: " + toString(numberOfValidEntries) + "\n");
    errorMessage("Total singal names produced: " + toString(numberOfSignals) + "\n");

}

// read and processing one entry
bool processOneEntry(ifstream &inputFile, station &entry, int entryNumber, string networkCode) {

    string stationCode, typeOfInstrument, typeOfBand, orientation;
    bool isValidEntry = true;

    // convert networkCode to enum type
    if (!setNetworkCode(networkCode, entry)) {
        errorMessage("Entry # " + toString(entryNumber) + " ignored. Invalid network.\n");
        isValidEntry = false;
    }

    // read station code
    inputFile >> stationCode;
    if (!setStationCode(stationCode, entry)) {
        errorMessage("Entry # " + toString(entryNumber) + " ignored. Invalid station code.\n");
        isValidEntry = false;
    }

    // read type of instrument
    inputFile >> typeOfInstrument;
    if (!setInstrumentType(typeOfInstrument, entry)) {
        errorMessage("Entry # " + toString(entryNumber) + " ignored. Invalid band type.\n");
        isValidEntry = false;
    }

    // read type of band
    inputFile >> typeOfBand;
    if (!setBandType(typeOfBand, entry)) {
        errorMessage("Entry # " + toString(entryNumber) + " ignored. Invalid instrument type.\n");
        isValidEntry = false;
    }

    // read orientation
    inputFile >> orientation;
    if (!setOrientation(orientation, entry)) {
        errorMessage("Entry # " + toString(entryNumber) + " ignored. Invalid orientation.\n");
        isValidEntry = false;
    }

    return isValidEntry;

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