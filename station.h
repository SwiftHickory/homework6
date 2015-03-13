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

bool setNetworkCode(string network_str, networkCodeType &network_enum);
string getNetworkCode(networkCodeType network_enum);

bool setStationCode(string station_str);
string getStationCode(string station_str);

bool setBandType(string bandType_str, typeOfBandType &bandType_enum);
string getBandType(typeOfBandType bandType_enum);

bool setInstrumentType(string instrumentType_str, typeOfInstrumentType &instrumentType_enum);
string getInstrumentType(typeOfInstrumentType instrumentType_enum);

bool setOrientation(string orientation_str);
string getOrientation(string orientation_str);

#endif