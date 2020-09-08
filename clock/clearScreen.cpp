#include <iostream>
#include <stdio.h>      /* printf */
#include <time.h>       /* time_t, time, ctime */
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)// this put this in since being localtime was setting giving my computer an warning/error

using namespace std;
//begining of class 
class clearScreen {
    int hours24;
    int hours12;
    int minutes;
    int seconds;

// clearScreen constructor
public: clearScreen() {
    hours24 = 0;
    hours12 = 0;
    minutes = 0;
    seconds = 0;

};
//---Mutator Functions
// adds a hour 
public: void addHour() {

    char buff[80];
    char* oneHour;
    char* twoHour;
    // displays the difference to user between for the 24 display
    cout<< ("\n")<< endl;
    getCurrentTime(1, buff);
    cout << "Orginal 24 Clock Equals: ";
    puts(buff);
    oneHour = strtok(buff, ":");
    this->hours24 = atoi(oneHour);
    this->hours24++;
    cout << "Now 24 Clock Equals: ";
    cout << this->hours24 << ":" << this->minutes << ":" << this->seconds<<endl;

    // displays the difference to user between for the 12 display
    getCurrentTime(2, buff);
    cout << "Orginal 12 Clock Equals: ";
    puts(buff);
    twoHour = strtok(buff, ":");
    this-> hours12 = atoi(twoHour);
    this-> hours12++;
    cout << "Now 12 Clock Equals: " << "PM";
    cout << this->hours12 << ":" << this->minutes << ":" << this->seconds << endl;
    cout << endl;


}
      //adds an minute
public: void addMinute() {
    char buff[80];
    char* oneMinute;
    char* oneSecond;
    char* oneHour;

    // displays 24 orignal time
    cout << ("\n") << endl;
    getCurrentTime(1, buff);
    cout << "Orginal 24 Clock Equals: ";
    puts(buff);
    // displays 12 orignal time 
    getCurrentTime(2, buff);
    cout << "Orginal 12 Clock Equals: ";
    puts(buff);
    oneHour = strtok(buff, ":");
    oneMinute = strtok(NULL, ":");
    oneSecond = strtok(NULL, ":");
    this-> minutes= atoi(oneMinute);
    this->minutes++; // adds a minute
    cout << " Now 24 Clock Equals: "; //displays the what 24 hour is now
    cout << this->hours24 << ":" << this->minutes << ":" << this->seconds << endl;
    cout << "Now 12 Clock Equals: "; // displays the what 12 hour is now
    cout << this->hours12 << ":" << this->minutes << ":" << this->seconds << endl;


}

      // adds an second
public: void addSecond() {
    char buff[80];
    char* oneSecond;
    char* oneHour;
    char* oneMinute;

    cout << ("\n") << endl;
    getCurrentTime(1, buff);
 
    cout << "Orginal 24 Clock Equals: ";// displays 24 orignal time
    puts(buff);
    getCurrentTime(2, buff);
    cout << "Orginal 12 Clock Equals: "; // displays 12 orignal time 
    puts(buff);
    oneHour = strtok(buff, ":");
    oneMinute = strtok(NULL, ":");
    oneSecond = strtok(NULL, ":");

    this-> seconds = atoi(oneSecond);
    this->seconds++;
    cout << "Now 24 Clock Equals: ";//displays the what 24 hour is now
    cout << this->hours24 << ":" << this->minutes << ":" << this->seconds << endl;
    cout << "Now 12 Clock Equals: "; // displays the what 12 hour is now
    cout << this->hours12 << ":" << this->minutes << ":" << this->seconds << endl;

}
      //prints both 24 hour and the 12 display
public: void twoDisplay() {
    
    char buff[80];
   

    //---------Printing out the two displays--------
    printf("\n");
    getCurrentTime(1,buff);
    printf("24 Clock Equals: ");
    puts(buff);
    getCurrentTime(2,buff);
    printf("12 Clock Equals: ");
    puts(buff);
    printf("\n");
}

    //-- Accessor Method----
      // gets the current time to so that addHour, addMinute, and addSecond to reference too
    public: char* getCurrentTime(int type, char buff[80]) {
        time_t rawtime;
        struct tm* timeinfo; // stores data of the current time inside of a structure timeinfo
        char buffer1[80];
        char buffer2[80];
        char buffer3[80];
        char* tempo; // tempo is closest variable/char* name I could think for time. I was running out of time variable names.
        time(&rawtime);
        timeinfo = localtime(&rawtime); // gets and store the current time
        
        if (type == 1) {
            strftime(buffer1, 80, "%R:%S", timeinfo); //when called in main to display current time for 24 Hour
            strcpy(buff,buffer1);
            strcpy(buffer3, buffer1);
            tempo = strtok(buffer3, ":");
            this->hours24 = atoi(tempo); 
        }
        //--------Setting hours---------------
        else if (type == 2) {
            strftime(buffer2, 80, "%r", timeinfo);// stores hour in hours 
            strcpy(buff,buffer2);
            strcpy(buffer3, buffer2);
            tempo = strtok(buffer3, ":");
            this->hours12 = atoi(tempo); // 
        }
       
        //----------------Setting Minutes--------------------------
        tempo = strtok(NULL, ":");
        this->minutes = atoi(tempo);
        //----------------Setting Seconds--------------------------
        tempo = strtok(NULL, ":");
        this->seconds = atoi(tempo);
        
        return buff;
     }
};