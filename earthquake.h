#ifndef EARTHQUAKE_H
#define EARTHQUAKE_H

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
    typeOfMagnitudeType magnitudeType_enum;
    float magnitude;
};

void setEventID(string &eventID_str);
string getEventID(string eventID_str);

void setDate(string &date_str, int &year_int, months &month_enum, int &day_int);
string getDate(int &year_int, months &month_enum, int &day_int);

void setTime(string &time_str);
string getTime(string time_str);

void setTimeZone(string &timeZone_str);
string getTimeZone(string timeZone_str);

void setEarthquakeName(string &earthquakeName_str);
string getEarthqaukeName(string earthqaukeName_str);

void setMonth(string month_str, months &month_enum);
string getMonth(months month_enum);

void setDay(string day_str, int &day_int);
string getDay(int day_int);

void setYear(string year_str, int &year_int);
string getYear(int year_int);

void setEvlo(double &evlo);
double getEvlo(double evlo);

void setEvla(double &evla);
double getEvla(double evla);

void setEvdp(double &evdp);
double getEvdp(double evdp);

void setMagnitudeType(string magnitudeType_str, typeOfMagnitudeType &magnitudeType_enum);
string getMagnitudeType(typeOfMagnitudeType &magnitudeType_enum);

void setMagnitude(float &magnitude);
float getMagnitude(float magnitude);

// return the numer of days in a month
int daysOfAMonth(months month_enum, int year_int);

#endif