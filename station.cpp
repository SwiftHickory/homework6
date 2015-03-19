#include "station.h"
#include "global.h"

bool setNetworkCode(string networkCode, station &st) {

	if (networkCode == "CE") {
        st.networkCode = CE;
        return true;
    }

    if (networkCode == "CI") {
        st.networkCode = CI;
        return true;
    }

    if (networkCode == "FA") {
        st.networkCode = FA;
        return true;
    }

    if (networkCode == "NP") {
        st.networkCode = NP;
        return true;
    }

    if (networkCode == "WR") {
        st.networkCode = WR;
        return true;
    }

    // otherwise it's a invalid network
    return false;

}

string getNetworkCode(station st) {

	switch (st.networkCode) {
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

bool setStationCode(string stationCode, station &st) {

	// station code must be 3 captital letters or 5 numeric characters
    if (stationCode.length() == 5 && is_digits(stationCode)) {
    	st.stationCode = stationCode;
        return true;
    }

    if (stationCode.length() == 3) {
        if (isupper(stationCode[0]) && isupper(stationCode[1]) && isupper(stationCode[2])) {
        	st.stationCode = stationCode;
            return true;
        }
    }

    return false;

}

string getStationCode(station st) {

	return st.stationCode;

}

bool setBandType(string bandType, station &st) {

	// case insensitive so convert it to lower case first
    bandType = lowerString(bandType);

    if (bandType == "long-period") {
        st.typeOfBand = longperiod;
        return true;
    }

    if (bandType == "short-period") {
        st.typeOfBand = shortperiod;
        return true;
    }

    if (bandType == "broadband") {
        st.typeOfBand = broadband;
        return true;
    }

    return false;

}

string getBandType(station st) {

	switch (st.typeOfBand) {
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

bool setInstrumentType(string instrumentType, station &st) {

	// case insensitive so convert it to lower case first
    instrumentType = lowerString(instrumentType);

    if (instrumentType == "high-gain") {
        st.typeOfInstrument = highgain;
        return true;
    }

    if (instrumentType == "low-gain") {
        st.typeOfInstrument = lowgain;
        return true;
    }

    if (instrumentType == "accelerometer") {
        st.typeOfInstrument = accelerometer;
        return true;
    }

    return false;

}

string getInstrumentType(station st) {

	switch (st.typeOfInstrument) {
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

bool setOrientation(string str, station &st) {

	// case insensitive so convert it to lower case first
    str = lowerString(str);

    if (str.length() < 4) {
        if (isdigit(str[0])) {
            for (int i = 0; i < str.length(); i++) {
                if (str[i] != '1' && str[i] != '2' && str[i] != '3') {
                    return false;
                }
            }

            st.orientation =  str;

            return true;
        } else if (islower(str[0])) {
            for (int i = 0; i < str.length(); i++) {
                if (str[i] != 'n' && str[i] != 'e' && str[i] != 'z') {
                    return false;
                }
            }

            st.orientation = str;

            return true;
        }
    }

    return false;

}

string getOrientation(station st) {

	return upperString(st.orientation);

}

// read table and then produce output
void tableProcessing(ifstream &inputFile, ofstream &outputFile, earthquake eq) {

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
            singalStream << getEventID(eq) << ".";
            singalStream << getNetworkCode(entry[i]) << ".";
            singalStream << getStationCode(entry[i]) << ".";
            singalStream << getBandType(entry[i]);
            singalStream << getInstrumentType(entry[i]);
            singalStream << orientation[j] << endl;

            outputFile << singalStream.str();
        }
    }

    printOutput(logFile, "Total invalid entries ignored: " + intToString(numberOfEntryRead - numberOfValidEntries) + "\n");
    printOutput(logFile, "Totoal valid entries read: " + intToString(numberOfValidEntries) + "\n");
    printOutput(logFile, "Total singal names produced: " + intToString(numberOfSignals) + "\n");

}

// read and processing one entry
bool processOneEntry(ifstream &inputFile, station &entry, int entryNumber, string networkCode) {

    string stationCode, typeOfInstrument, typeOfBand, orientation;
    bool isValidEntry = true;

    // convert networkCode to enum type
    if (!setNetworkCode(networkCode, entry)) {
        printOutput(logFile, "Entry # " + intToString(entryNumber) + " ignored. Invalid network.\n");
        isValidEntry = false;
    }

    // read station code
    inputFile >> stationCode;
    if (!setStationCode(stationCode, entry)) {
        printOutput(logFile, "Entry # " + intToString(entryNumber) + " ignored. Invalid station code.\n");
        isValidEntry = false;
    }

	// read type of band
    inputFile >> typeOfBand;
    if (!setBandType(typeOfBand, entry)) {
        printOutput(logFile, "Entry # " + intToString(entryNumber) + " ignored. Invalid band type.\n");
        isValidEntry = false;
    }

    // read type of instrument
    inputFile >> typeOfInstrument;
    if (!setInstrumentType(typeOfInstrument, entry)) {
        printOutput(logFile, "Entry # " + intToString(entryNumber) + " ignored. Invalid instrument type.\n");
        isValidEntry = false;
    }

    // read orientation
    inputFile >> orientation;
    if (!setOrientation(orientation, entry)) {
        printOutput(logFile, "Entry # " + intToString(entryNumber) + " ignored. Invalid orientation.\n");
        isValidEntry = false;
    }

    return isValidEntry;

}