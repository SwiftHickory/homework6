#include "earthquake.h"

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
            errorMessageWithExit("Error: invalid date format of this earthquake!\n");
        }

        eq.date = date;
    } else {
        errorMessageWithExit("Error: invalid date of this earthquake!\n");
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

        //  hour, minute, second and millisecond should be numbers 
        if (!is_digits(hour + minute + second + millisecond)) {
            errorMessageWithExit("Error: invalid time of this earthquake!\n");
        }

        setHour(hour, eq);
        setMinute(minute, eq);
        setSecond(second, eq);
        setMillisecond(millisecond, eq);

        // check for delimer
        if (time[2] != ':' || time[5] != ':' || time[8] != '.') {
            errorMessageWithExit("Error: invalid time format of this earthquake!\n");
        }

        eq.time = time;
    } else {
        errorMessageWithExit("Error: invalid time of this earthquake!\n");
    }

}

string getTime(earthquake eq) {

	return eq.time;

}

void setHour(string hour, earthquake &eq) {

	if (!is_digits(hour)) {
		errorMessageWithExit("Error: invalid time hour of this earthquake!\n");
	} else {
		eq.hour = atoi(hour.c_str());

		if (eq.hour < 0 || eq.hour > 23) {
        	errorMessageWithExit("Error: invalid time hour of this earthquake!\n");
        }
	}

}

string getHour(earthquake eq) {

	return intToString(eq.hour);

}

void setMinute(string minute, earthquake &eq) {

	if (!is_digits(minute)) {
		errorMessageWithExit("Error: invalid time minute of this earthquake!\n");
	} else {
		eq.minute = atoi(minute.c_str());

		if (eq.minute < 0 || eq.minute > 59) {
        	errorMessageWithExit("Error: invalid time minute of this earthquake!\n");
        }
	}

}

string getMinute(earthquake eq) {

	return intToString(eq.minute);

}

void setSecond(string second, earthquake &eq) {

	if (!is_digits(second)) {
		errorMessageWithExit("Error: invalid time second of this earthquake!\n");
	} else {
		eq.second = atoi(second.c_str());

		if (eq.second < 0 || eq.second > 59) {
        	errorMessageWithExit("Error: invalid time second of this earthquake!\n");
        }
	}

}

string getSecond(earthquake eq) {

	return intToString(eq.second);

}

void setMillisecond(string millisecond, earthquake &eq) {

	if (!is_digits(millisecond)) {
		errorMessageWithExit("Error: invalid time millisecond of this earthquake!\n");
	} else {
		eq.millisecond = atoi(millisecond.c_str());

		if (eq.millisecond< 0) {
        	errorMessageWithExit("Error: invalid time millisecond of this earthquake!\n");
        }
	}

}

string getMillisecond(earthquake eq) {

	return intToString(eq.millisecond);

}

void setTimeZone(string timeZone, earthquake &eq) {

	// time zone must be three characters
    if (timeZone.length() != 3) {
        errorMessageWithExit("Error: invalid time zone of this earthquake!\n");
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

	return eq.earthqaukeName;
}

void setMonth(string month, earthquake &eq) {

	if (month == "01") {
		eq.month = January;
	}

    if (month == "02") {
    	eq.month = February;
    }

    if (month == "03") {
    	eq.month = March;
    }

    if (month == "04") {
    	eq.month = April;
    }

    if (month == "05") {
    	eq.month = May;
    }

    if (month == "06") {
    	eq.month = June;
    }

    if (month == "07") {
    	eq.month = July;
    }

    if (month == "08") {
    	eq.month = August;
    }

    if (month == "09") {
    	eq.month = September；
    }

    if (month == "10") {
    	eq.month = October;
    }

    if (month == "11") {
    	eq.month = November;
    }

    if (month == "12") {
    	eq.month = December;
    }
    
    errorMessageWithExit("Error: invalid month of this earthquake!\n");

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
        errorMessageWithExit("Error: invalid date day of this earthquake!\n");
     } else {
     	eq.day = atoi(day.c_str());
     	if (eq.day < 0 || eq.day > daysOfAMonth(eq.month, eq.year)) {
     		errorMessageWithExit("Error: invalid date day of this earthquake!\n");
     	}
     }

}

string getDay(earthquake eq) {

	return intToString(eq.day);

}

void setYear(string year, earthquake &eq) {

	// year should be numbers 
    if (!is_digits(year)) {
        errorMessageWithExit("Error: invalid date year of this earthquake!\n");
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
    }

    if (magnitudeType == "ms") {
        eq.magnitudeType = ms;
    }

    if (magnitudeType == "mb") {
        eq.magnitudeType = mb;
    }

    if (magnitudeType == "mw") {
        eq.magnitudeType = mw;
    }

    errorMessageWithExit("Error: invalid magnitude type of this earthquake!\n");

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

void setMagnitude(float magnitude, earthquake eq) {

	// magnitude must be a positive number
    if (magnitude <= 0) {
        errorMessageWithExit("Error: magnitude must be a positive number\n");
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