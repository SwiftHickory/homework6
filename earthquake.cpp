#include "earthquake.h"

void setEventID(string &eventID_str) {

	return;

}

string getEventID(string eventID_str) {

	return eventID_str;

}

void setDate(string &date_str, string &date_str, int &year_int, months &month_enum, int &day_int) {

	// the length of date must be 10
    if (date_str.length() == 10) {

        setYear(year_str, year_int);
        setMonth(month_str, month_enum);
        setDay(day_str, day_int, month_enum, year_int);

        // month, day and year should be numbers 
        if (!is_digits(month + day + year)) {
            errorMessageWithExit("Error: invalid date of this earthquake!\n");
        }

        // date format is mm/dd/year or mm-dd-year
        if ((date[2] != '/' || date[5] != '/') && (date[2] != '-' || date[5] != '-')) {
            errorMessageWithExit("Error: invalid date format of this earthquake!\n");
        }
    } else {
        errorMessageWithExit("Error: invalid date of this earthquake!\n");
    }

}

string getDate(int &year_int, months &month_enum, int &day_int) {

	return getMonth(month_enum) + "-" + getDay(day_int) + "-" + getYear(year_int);

}

void setTime(string &time_str) {

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

        int hour_int = atoi(hour.c_str());
        int minute_int = atoi(minute.c_str());
        int second_int = atoi(second.c_str());

        // check the validity of time
        if ( hour_int < 0 || hour_int > 23) {
        	errorMessageWithExit("Error: invalid time hour of this earthquake!\n");
        }

        if ( minute_int < 0 || minute_int > 59) {
        	errorMessageWithExit("Error: invalid time minute of this earthquake!\n");
        }

        if ( second_int < 0 || second_int > 59) {
        	errorMessageWithExit("Error: invalid time second of this earthquake!\n");
        }

        // check for delimer
        if (time[2] != ':' || time[5] != ':' || time[8] != '.') {
            errorMessageWithExit("Error: invalid time format of this earthquake!\n");
        }
    } else {
        errorMessageWithExit("Error: invalid time of this earthquake!\n");
    }

}

string getTime(string time_str) {

	return time_str;

}

void setTimeZone(string &timeZone_str) {

	// time zone must be three characters
    if (timeZone_str.length() != 3) {
        errorMessageWithExit("Error: invalid time zone of this earthquake!\n");
    }

}

string getTimeZone(string timeZone_str) {

	return timeZone_str;

}

void setEarthquakeName(string &earthquakeName_str) {

	return;

}

string getEarthqaukeName(string earthqaukeName_str) {

	return earthqaukeName_str;
}

void setMonth(string date_str, months &month_enum) {

	string month_str = date_str.substr(0, 2);

	if (month_str == "01") {
		month_enum = January;
	}

    if (month_str == "02") {
    	month_enum = February;
    }

    if (month_str == "03") {
    	month_enum = March;
    }

    if (month_str == "04") {
    	month_enum = April;
    }

    if (month_str == "05") {
    	month_enum = May;
    }

    if (month_str == "06") {
    	month_enum = June;
    }

    if (month_str == "07") {
    	month_enum = July;
    }

    if (month_str == "08") {
    	month_enum = August;
    }

    if (month_str == "09") {
    	month_enum = September；
    }

    if (month_str == "10") {
    	month_enum = October;
    }

    if (month_str == "11") {
    	month_enum = November;
    }

    if (month_str == "12") {
    	month_enum = December;
    }
    
    errorMessageWithExit("Error: invalid month of this earthquake!\n");

}

string getMonth(months month_enum) {

	switch (month_enum) {
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

void setDay(string date_str, int &day_int, months month_enum, int year_int) {

	string day_str = date_str.substr(3, 2);

	// day should be numbers 
    if (!is_digits(day_str)) {
        errorMessageWithExit("Error: invalid date day of this earthquake!\n");
     } else {
     	day_int = atoi(year_str.c_str());
     	if (day_int < 0 || day_int > daysOfAMonth(month_enum, year_int)) {
     		errorMessageWithExit("Error: invalid date day of this earthquake!\n");
     	}
     }

}

string getDay(int data_int) {

	return intToString(day_int);

}

void setYear(string date_str, int &year_int) {

	string year_str = date_str.substr(6, 4);

	// year should be numbers 
    if (!is_digits(year_str)) {
        errorMessageWithExit("Error: invalid date year of this earthquake!\n");
     } else {
     	year_int = atoi(year_str.c_str());
     }

}

string getYear(int year_int) {

	return intToString(year_int);

}

void setEvlo(double &evlo) {

	return;

}

double getEvlo(double evlo) {

	return evlo;

}

void setEvla(double &evla) {

	return;

}

double getEvla(double evla) {

	return evla;

}

void setEvdp(double &evdp) {

	return;

}

double getEvdp(double evdp) {

	return evdp;

}

void setMagnitudeType(string magnitudeType_str, typeOfMagnitudeType &magnitudeType_enum) {

	// case insensitive so convert it to lower case first
    magnitudeType_str = lowerString(magnitudeType_str);

    if (magnitudeType_str == "ml") {
        magnitudeType_enum = ml;
    }

    if (magnitudeType_str == "ms") {
        magnitudeType_enum = ms;
    }

    if (magnitudeType_str == "mb") {
        magnitudeType_enum = mb;
    }

    if (magnitudeType_str == "mw") {
        magnitudeType_enum = mw;
    }

    errorMessageWithExit("Error: invalid magnitude type of this earthquake!\n");

}

string getMagnitudeType(typeOfMagnitudeType &magnitudeType_enum) {

	switch (magnitudeType_enum) {
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

void setMagnitude(float &magnitude) {

	// magnitude must be a positive number
    if (magnitude <= 0) {
        errorMessageWithExit("Error: magnitude must be a positive number\n");
    }

}

float getMagnitude(float magnitude) {

	return magnitude;

}

// return the numer of days in a month
int daysOfAMonth(months month_enum, int year_int) {

	switch (month_enum) {
		case January:
			return 31;
			break;
		case February:
			return year_int % 4 == 0 ? 28 :29;
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