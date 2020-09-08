#include <iostream>
#include <string.h>
#pragma once

using namespace std;

class animal {

    string aniName; // name 
    int trackNum; // tracking number
    int animalType; // animal type

public:
    animal() {

        trackNum = 0;
        aniName = "";
        animalType = 0;
    }
  // setting variables 
    animal(int trackingNumber, string name, int aniType) {
        trackNum = trackingNumber;
        aniName = name;
        animalType = aniType;
    }
    // setting the const variables so that they remain the same
    animal(const animal& some) {
        trackNum = some.trackNum;
        aniName = some.aniName;
        animalType = some.animalType;
    };

    void setName(string theName) { // set name 
        aniName = theName;
    }

    string getName() { // get name 
        return aniName;
    }

    void setTrackNum(int theNumber) { // set track number
        trackNum = theNumber;
    }

    int getTrackNum() { // get track number
        return trackNum;
    }
    int setanimalType(int aniType) { // set animal type 
        animalType = aniType;
    }
    int getanimalType() { // get animal type
        return animalType;
    }
    // stream so that animal can talk to add animal
    friend ostream& operator<<(ostream& output, const animal& A) {
        output << "Animal : " << A.aniName << A.trackNum << A.animalType << endl;
        return output;
    }
};