#include "station.h"

bool setNetworkCode(string network_str, networkCodeType &network_enum) {

	if (network_str == "CE") {
        network_enum = CE;
        return true;
    }

    if (network_str == "CI") {
        network_enum = CI;
        return true;
    }

    if (network_str == "FA") {
        network_enum = FA;
        return true;
    }

    if (network_str == "NP") {
        network_enum = NP;
        return true;
    }

    if (network_str == "WR") {
        network_enum = WR;
        return true;
    }

    // otherwise it's a invalid network
    return false;

}

string getNetworkCode(networkCodeType network_enum) {

	switch (network_enum) {
        case CE:
            return "CE";
            break;
        case CI:
            return "CI";
            break;
        case FA:
            return "FA";
            break;
        case NP:
            return "NP";
            break;
        case WR:
            return "WR";
            break;
    }

}

bool setStationCode(string station_str) {

	// station code must be 3 captital letters or 5 numeric characters
    if (str.length() == 5 && is_digits(str)) {
        return true;
    }

    if (str.length() == 3) {
        if (isupper(str[0]) && isupper(str[1]) && isupper(str[2])) {
            return true;
        }
    }

    return false;

}

string getStationCode(string station_str) {

	return station_str;

}

bool setBandType(string bandType_str, typeOfBandType &bandType_enum) {

	// case insensitive so convert it to lower case first
    bandType_str = lowerString(bandType_str);

    if (bandType_str == "long-period") {
        bandType_enum = longperiod;
        return true;
    }

    if (bandType_str == "short-period") {
        bandType_enum = shortperiod;
        return true;
    }

    if (bandType_str == "broadband") {
        bandType_enum = broadband;
        return true;
    }

    return false;

}

string getBandType(typeOfBandType bandType_enum) {

	switch (bandType_enum) {
        case longperiod:
            return "L";
            break;
        case shortperiod:
            return "B";
            break;
        case broadband:
            return "H";
            break;
    }

}

bool setInstrumentType(string instrumentType_str, typeOfInstrumentType &instrumentType_enum) {

	// case insensitive so convert it to lower case first
    instrumentType_str = lowerString(instrumentType_str);

    if (instrumentType_str == "high-gain") {
        instrumentType_enum = highgain;
        return true;
    }

    if (instrumentType_str == "low-gain") {
        instrumentType_enum = lowgain;
        return true;
    }

    if (instrumentType_str == "accelerometer") {
        instrumentType_enum = accelerometer;
        return true;
    }

    return false;

}

string getInstrumentType(typeOfInstrumentType instrumentType_enum) {

	switch (instrumentType_enum) {
        case highgain:
            return "H";
            break;
        case lowgain:
            return "L";
            break;
        case accelerometer:
            return "N";
            break;
    }

}

bool setOrientation(string str) {

	// case insensitive so convert it to lower case first
    str = lowerString(str);

    if (str.length() < 4) {
        if (isdigit(str[0])) {
            for (int i = 0; i < str.length(); i++) {
                if (str[i] != '1' && str[i] != '2' && str[i] != '3') {
                    return false;
                }
            }

            return true;
        } else if (islower(str[0])) {
            for (int i = 0; i < str.length(); i++) {
                if (str[i] != 'n' && str[i] != 'e' && str[i] != 'z') {
                    return false;
                }
            }

            return true;
        }
    }

    return false;

}

string getOrientation(string orientation_str) {

	return orientation_str;

}