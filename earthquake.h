/******************************************************************************
-   earthquake.h
-   Prog Tools for Scits Engrs - CIVL 8903 Homework VI
-
-   File Discreption: struct type define of earthquake
-
-   Author: Yang Yang
-
-   Github Repository: https://github.com/SwiftHickory/homework6.git
******************************************************************************/

#ifndef EARTHQUAKE_H
#define EARTHQUAKE_H

#include "myFunction.h"

using namespace std;

// case insensitive
enum typeOfMagnitudeType {
    ml,
    ms,
    mb,
    mw
};

enum months {
	January,
	February,
	March,
	April,
	May,
	June,
	July,
	August,
	September,
	October,
	November,
	December
};

struct earthquake {
    string eventID;
    string date;
    string time;
    string timeZone;
    string earthquakeName;
    months month;
    int day;
    int year;
    int hour;
    int minute;
    int second;
    int millisecond;
    double evlo;
    double evla;
    double evdp;
    typeOfMagnitudeType magnitudeType;
    float magnitude;
};

void setEventID(string eventID, earthquake &eq);
string getEventID(earthquake eq);

void setDate(string date, earthquake &eq);
string getDate(earthquake eq);

void setTime(string time, earthquake &eq);
string getTime(earthquake eq);

void setHour(string hour, earthquake &eq);
string getHour(earthquake eq);

void setMinute(string minute, earthquake &eq);
string getMinute(earthquake eq);

void setSecond(string second, earthquake &eq);
string getSecond(earthquake eq);

void setMillisecond(string millisecond, earthquake &eq);
string getMillisecond(earthquake eq);

void setTimeZone(string timeZone, earthquake &eq);
string getTimeZone(earthquake eq);

void setEarthquakeName(string earthquakeName, earthquake &eq);
string getEarthqaukeName(earthquake eq);

void setMonth(string month, earthquake &eq);
string getMonth(earthquake eq);

void setDay(string day, earthquake &eq);
string getDay(earthquake eq);

void setYear(string year, earthquake &eq);
string getYear(earthquake eq);

void setEvlo(double evlo, earthquake &eq);
double getEvlo(earthquake eq);

void setEvla(double evla, earthquake &eq);
double getEvla(earthquake eq);

void setEvdp(double evdp, earthquake &eq);
double getEvdp(earthquake eq);

void setMagnitudeType(string magnitudeType, earthquake &eq);
string getMagnitudeType(earthquake eq);

void setMagnitude(float magnitude, earthquake &eq);
float getMagnitude(earthquake eq);

// return the numer of days in a month
int daysOfAMonth(months month, int year);

// read header can then produce output header
void headerProcessing(ifstream &inputFile, ofstream &outputFile, string outputFileName, earthquake &eq);

#endif