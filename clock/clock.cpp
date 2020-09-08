
#include <iostream>
#include <stdio.h>      /* printf */
#include "clearScreen.cpp" //calling clearScreen 

using namespace std;

      int main()
      {
          int userChoice = 0;
          clearScreen* var1 = new clearScreen; // calls clearScreen and creates new variable var1

          // display menu for user selection
          do {
              cout << "----------------------------" << endl;
              cout <<"---------Display Menu-------"<< endl;
              cout << "----------------------------" << endl;
              cout << "---------Show Clock = 1-------" << endl;
              cout << "----------Add Hour = 2 -------" << endl;
              cout << "-------- Add Minute = 3 -----" << endl;
              cout << "---------Add Second = 4 ---- " << endl;
              cout << "---------Exit = 5 ---------- " << endl;
              cout << "-----Choose menu selection---" << endl;
              cin >> userChoice;

              if (userChoice == 1) {
                  var1->twoDisplay();
             }
              else if(userChoice == 2) {
                  var1->addHour();
              }
              else if (userChoice == 3) {
                  var1->addMinute();
              }
              else if (userChoice == 4) {
                  var1->addSecond();
              }

          } while (userChoice != 5);

          return 0;
      };