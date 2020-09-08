#include <iostream>
#include <string.h>
#include "animal.cpp"

using namespace std;

// inheracy from animal
class oviparous : public animal {
    int numberOfEggs;
    string oviType;
    string aniName;
    int trackNum;


public:
    oviparous() {// constructor for oviparous
        numberOfEggs = 0; // number of eggs 
        oviType = " "; // oviparous tyope
        aniName = " "; // animal name
        trackNum = 0; // animal tracking number
        animal::animal(this->trackNum, this->aniName, 1);
    }
    // setting oviparous variables
    oviparous(int eggs, string subType, int trackingNumber, string name) {
        trackNum = trackingNumber;
        aniName = name;
        numberOfEggs = eggs;
        oviType = subType;
        animal::animal(this->trackNum, this->aniName, 1);
    }
    oviparous(const oviparous& some) {

        trackNum = some.trackNum;
        aniName = some.aniName;
        numberOfEggs = some.numberOfEggs;
        oviType = some.oviType;
        animal::animal(this->trackNum, this->aniName, 1);
    };


    void setOviName(string theName) { // set oviparous name
        //animal::setName(theName);
        aniName = theName;
    }

    string getOviName() { // getting name
        //return animal::getName();
        return aniName;
    }

    void setOviTrackNum(int theNumber) { // set tracking number
        //animal::setTrackNum(theNumber);
        trackNum = theNumber;

    }

    int getOviTrackNum() { //getting tracking number
        //return animal::getTrackNum();
        return trackNum;
    }

    void setOviType(string subType) { //setting oviparous type
        oviType = subType;
    }
    string getOviType() { // getting oviparous type
        return oviType;
    }

    void setEggs(int eggs) { // setting eggs
        numberOfEggs = eggs;
    }
    int getEggs() { // getting eggs 
        return numberOfEggs;
    }


    friend ostream& operator<<(ostream& output, const oviparous& O) { // stream so that add animal can talk to oviparous
       
        output << O.trackNum << ", " << O.aniName << ", " << 1 << ", " <<
            "Oviparous" << ", " << O.oviType << ", " << "," << O.numberOfEggs << ", \n";
        return output;
    }
};
// crocodile class 
class crocodile : public oviparous {

public:
    crocodile() {

    }
};
// goose class 
class goose : public oviparous {

public:
    goose() {

    }
};
// pelican class
class pelican : public oviparous {

public:
    pelican() {

    }
};