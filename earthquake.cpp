#include "earthquake.h"
#include "global.h"

void setEventID(string eventID, earthquake &eq) {

	eq.eventID = eventID;

}

string getEventID(earthquake eq) {

	return eq.eventID;

}

void setDate(string date, earthquake &eq) {

	// the length of date must be 10
    if (date.length() == 10) {

    	// date format is mm/dd/yyyy
    	string month = date.substr(0, 2);
    	string day = date.substr(3, 2);
    	string year = date.substr(6, 4);

        setYear(year, eq);
        setMonth(month, eq);
        setDay(day,eq);

        // date format is mm/dd/year or mm-dd-year
        if ((date[2] != '/' || date[5] != '/') && (date[2] != '-' || date[5] != '-')) {
            printOutput(logFile, "Error: invalid date format of this earthquake!\n", true);
        }

        eq.date = date;
    } else {
        printOutput(logFile, "Error: invalid date of this earthquake!\n", true);
    }

}

string getDate(earthquake eq) {

	return eq.date;

}

void setTime(string time, earthquake &eq) {

	// the length of time must be 12
    if (time.length() == 12) {
        // time format is hh:mm:ss.fff
        string hour = time.substr(0, 2);
        string minute = time.substr(3, 2);
        string second = time.substr(6, 2);
        string millisecond = time.substr(9, 3);

        setHour(hour, eq);
        setMinute(minute, eq);
        setSecond(second, eq);
        setMillisecond(millisecond, eq);

        // check for delimer
        if (time[2] != ':' || time[5] != ':' || time[8] != '.') {
            printOutput(logFile, "Error: invalid time format of this earthquake!\n", true);
        }

        eq.time = time;
    } else {
        printOutput(logFile, "Error: invalid time of this earthquake!\n", true);
    }

}

string getTime(earthquake eq) {

	return eq.time;

}

void setHour(string hour, earthquake &eq) {

	if (!is_digits(hour)) {
		printOutput(logFile, "Error: invalid time hour of this earthquake!\n", true);
	} else {
		eq.hour = atoi(hour.c_str());

		if (eq.hour < 0 || eq.hour > 23) {
        	printOutput(logFile, "Error: invalid time hour of this earthquake!\n", true);
        }
	}

}

string getHour(earthquake eq) {

	return intToString(eq.hour);

}

void setMinute(string minute, earthquake &eq) {

	if (!is_digits(minute)) {
		printOutput(logFile, "Error: invalid time minute of this earthquake!\n", true);
	} else {
		eq.minute = atoi(minute.c_str());

		if (eq.minute < 0 || eq.minute > 59) {
        	printOutput(logFile, "Error: invalid time minute of this earthquake!\n", true);
        }
	}

}

string getMinute(earthquake eq) {

	return intToString(eq.minute);

}

void setSecond(string second, earthquake &eq) {

	if (!is_digits(second)) {
		printOutput(logFile, "Error: invalid time second of this earthquake!\n", true);
	} else {
		eq.second = atoi(second.c_str());

		if (eq.second < 0 || eq.second > 59) {
        	printOutput(logFile, "Error: invalid time second of this earthquake!\n", true);
        }
	}

}

string getSecond(earthquake eq) {

	return intToString(eq.second);

}

void setMillisecond(string millisecond, earthquake &eq) {

	if (!is_digits(millisecond)) {
		printOutput(logFile, "Error: invalid time millisecond of this earthquake!\n", true);
	} else {
		eq.millisecond = atoi(millisecond.c_str());

		if (eq.millisecond< 0) {
        	printOutput(logFile, "Error: invalid time millisecond of this earthquake!\n", true);
        }
	}

}

string getMillisecond(earthquake eq) {

	return intToString(eq.millisecond);

}

void setTimeZone(string timeZone, earthquake &eq) {

	// time zone must be three characters
    if (timeZone.length() != 3) {
        printOutput(logFile, "Error: invalid time zone of this earthquake!\n", true);
    } else {
    	eq.timeZone = timeZone;
    }

}

string getTimeZone(earthquake eq) {

	return eq.timeZone;

}

void setEarthquakeName(string earthquakeName, earthquake &eq) {

	eq.earthquakeName = earthquakeName;

}

string getEarthqaukeName(earthquake eq) {

	return eq.earthquakeName;
}

void setMonth(string month, earthquake &eq) {

	if (month == "01") {
		eq.month = January;
		return;
	}

    if (month == "02") {
    	eq.month = February;
    	return;
    }

    if (month == "03") {
    	eq.month = March;
    	return;
    }

    if (month == "04") {
    	eq.month = April;
    	return;
    }

    if (month == "05") {
    	eq.month = May;
    	return;
    }

    if (month == "06") {
    	eq.month = June;
    	return;
    }

    if (month == "07") {
    	eq.month = July;
    	return;
    }

    if (month == "08") {
    	eq.month = August;
    	return;
    }

    if (month == "09") {
    	eq.month = September;
    	return;
    }

    if (month == "10") {
    	eq.month = October;
    	return;
    }

    if (month == "11") {
    	eq.month = November;
    	return;
    }

    if (month == "12") {
    	eq.month = December;
    	return;
    }
    
    printOutput(logFile, "Error: invalid month of this earthquake!\n", true);

}

string getMonth(earthquake eq) {

	switch (eq.month) {
		case January:
			return "January";
			break;
		case February:
			return "February";
			break;
		case March:
			return "March";
			break;
		case April:
			return "April";
			break;
		case May:
			return "May";
			break;
		case June:
			return "June";
			break;
		case July:
			return "July";
			break;
		case August:
			return "August";
			break;
		case September:
			return "September";
			break;
		case October:
			return "October";
			break;
		case November:
			return "November";
			break;
		case December:
			return "December";
			break;
	}

}

void setDay(string day, earthquake &eq) {

	// day should be numbers 
    if (!is_digits(day)) {
        printOutput(logFile, "Error: invalid date day of this earthquake!\n", true);
     } else {
     	eq.day = atoi(day.c_str());
     	if (eq.day < 0 || eq.day > daysOfAMonth(eq.month, eq.year)) {
     		printOutput(logFile, "Error: invalid date day of this earthquake!\n", true);
     	}
     }

}

string getDay(earthquake eq) {

	string day = intToString(eq.day);

    if (day.length() == 1) {
        day = "0" + day;
    }

    return day;

}

void setYear(string year, earthquake &eq) {

	// year should be numbers 
    if (!is_digits(year)) {
        printOutput(logFile, "Error: invalid date year of this earthquake!\n", true);
     } else {
     	eq.year = atoi(year.c_str());
     }

}

string getYear(earthquake eq) {

	return intToString(eq.year);

}

void setEvlo(double evlo, earthquake &eq) {

	eq.evlo = evlo;

}

double getEvlo(earthquake eq) {

	return eq.evlo;

}

void setEvla(double evla, earthquake &eq) {

	eq.evla = evla;

}

double getEvla(earthquake eq) {

	return eq.evla;

}

void setEvdp(double evdp, earthquake &eq) {

	eq.evdp = evdp;

}

double getEvdp(earthquake eq) {

	return eq.evdp;

}

void setMagnitudeType(string magnitudeType, earthquake &eq) {

	// case insensitive so convert it to lower case first
    magnitudeType = lowerString(magnitudeType);

    if (magnitudeType == "ml") {
        eq.magnitudeType = ml;
        return;
    }

    if (magnitudeType == "ms") {
        eq.magnitudeType = ms;
        return;
    }

    if (magnitudeType == "mb") {
        eq.magnitudeType = mb;
        return;
    }

    if (magnitudeType == "mw") {
        eq.magnitudeType = mw;
        return;
    }

    printOutput(logFile, "Error: invalid magnitude type of this earthquake!\n", true);

}

string getMagnitudeType(earthquake eq) {

	switch (eq.magnitudeType) {
        case ml:
            return "Ml";
            break;
        case ms:
            return "Ms";
            break;
        case mb:
            return "Mb";
            break;
        case mw:
            return "Mw";
            break;
    }

}

void setMagnitude(float magnitude, earthquake &eq) {

	// magnitude must be a positive number
    if (magnitude <= 0) {
        printOutput(logFile, "Error: magnitude must be a positive number\n", true);
    } else {
    	eq.magnitude = magnitude;
    }

}

float getMagnitude(earthquake eq) {

	return eq.magnitude;

}

// return the numer of days in a month
int daysOfAMonth(months month, int year) {

	switch (month) {
		case January:
			return 31;
			break;
		case February:
			return year % 4 == 0 ? 28 :29;
			break;
		case March:
			return 31;
			break;
		case April:
			return 30;
			break;
		case May:
			return 31;
			break;
		case June:
			return 30;
			break;
		case July:
			return 31;
			break;
		case August:
			return 31;
			break;
		case September:
			return 30;
			break;
		case October:
			return 31;
			break;
		case November:
			return 30;
			break;
		case December:
			return 31;
			break;
	}

}

// read header from input file
void headerProcessing(ifstream &inputFile, ofstream &outputFile, string outputFileName, earthquake &eq) {

    string eventID, date, time, timeZone, earthquakeName;
    double evlo, evla, evdp;
    string magnitudeType;
    float magnitude;

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
    outputFile << getEarthqaukeName(eq) << " [" << getEventID(eq) << "] (";
    outputFile << getEvlo(eq) << ", " << getEvla(eq) << ", " << getEvdp(eq) << ")" << endl;

}