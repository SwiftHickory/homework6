/******************************************************************************
-   yang.cpp
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

struct entryType {
    networkCodeType networkCode;
    string stationCode;
    typeOfBandType typeOfBand;
    typeOfInstrumentType typeOfInstrument;
    string orientation; // one to three characters, case insensitive
};

#endif