#include <iostream>
#include <string.h>
#include "animal.cpp"


using namespace std;
 
class mammal : public animal {// class inheracy from animal
    int mamNurse;
    string mamType;
    string aniName;
    int trackNum;


public: // mammal constructor
    mammal() {
        mamNurse = 0; // mammal nurse 
        mamType = " "; //mammal typpe
        aniName = " "; //name 
        trackNum = 0; // tracking Number
        animal::animal(this->trackNum, this->aniName, 2);
    } 
    // mammal constructor for setting values
    mammal(int nurse, string subType, int trackingNumber, string name) {
        mamNurse = nurse;
        mamType = subType;
        aniName = name;
        trackNum = trackingNumber;
        animal::animal(this->trackNum, this->aniName, 2);
    }
    mammal(const mammal& some) {

        trackNum = some.trackNum;
        aniName = some.aniName;
        mamNurse = some.mamNurse;
        mamType = some.mamType;
        animal::animal(this->trackNum, this->aniName, 2);
    };

    void setMamName(string theName) { //setting name
        animal::setName(theName);
    }

    string getMamName() {
        return animal::getName(); //getting name
    }

    void setMamTrackNum(int theNumber) { // setting tracking number
        animal::setTrackNum(theNumber);

    }

    int getMamTrackNum() { // setting tracking number
        return animal::getTrackNum();
    }
    void setMamType(string subType) { // setting mammal type
        mamType = subType;
    }
    string getMamType() { //mammal type
        return mamType;
    }

    void setMamNurse(int nurse) {// set mammal nurse
        mamNurse = nurse;

    }
    int getMamNurse() { // get mammal nurse
        return mamNurse;
    }


    friend ostream& operator<<(ostream& output, const mammal& M) {

        output << M.trackNum << ", " << M.aniName << ", " << 2 << ", " << "Mammal" <<
            ", " << M.mamType << ", " << M.mamNurse << ", " <<", \n";
        return output;
    }
};

//bat class 
class bat : public mammal {

public:
    bat() {

    }
};
//whale class
class whale : public mammal {

public:
    whale() {

    }
};
//sealion class
class SeaLion : public mammal {

public:
    SeaLion() {

    }
};