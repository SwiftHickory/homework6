/******************************************************************************
-   station.h
-   Prog Tools for Scits Engrs - CIVL 8903 Homework VI
-
-   File Discreption: struct type define of station
-
-   Author: Yang Yang
-
-   Github Repository: https://github.com/SwiftHickory/homework6.git
******************************************************************************/

#ifndef STATION_H
#define STATION_H

#include "earthquake.h"

using namespace std;

// case sensitive
enum networkCodeType {
    CE,
    CI,
    FA,
    NP,
    WR
};

// case insensitive
enum typeOfBandType {
    longperiod,  // L
    shortperiod,  // B
    broadband  // H
};

// case insensitive
enum typeOfInstrumentType {
    highgain,  // H
    lowgain,  // L
    accelerometer  // N
};

struct station {
    networkCodeType networkCode;
    string stationCode;
    typeOfBandType typeOfBand;
    typeOfInstrumentType typeOfInstrument;
    string orientation;  // one to three characters, case insensitive
};

bool setNetworkCode(string networkCode, station &st);
string getNetworkCode(station st);

bool setStationCode(string stationCode, station &st);
string getStationCode(station st);

bool setBandType(string bandType, station &st);
string getBandType(station st);

bool setInstrumentType(string instrumentType, station &st);
string getInstrumentType(station st);

bool setOrientation(string orientation, station &st);
string getOrientation(station st);

// read table and then produce output
void tableProcessing(ifstream &inputFile, ofstream &outputFile, earthquake eq);

// read and processing one entry
bool processOneEntry(ifstream &inputFile, station &entry, int entryNumber, string networkCode);

#endif