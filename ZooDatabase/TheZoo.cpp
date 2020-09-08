#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <stdexcept>      // std::out_of_range
#include <cstdio>
#include <sstream>
#include <fstream>
#include <string.h>
#include "animal.cpp"
#include "mammal.cpp"
#include "oviparous.cpp"
#define FIELD_SIZE 7 // How many fields per line


using namespace std;


void AddAnimal(vector<animal*>& listAni, int animalCount) // add in CSV creating file and add date validation afterwards

{
    // ============================ AddAnimal varaibles 
    int animalType = 0;
    int trackingNumber = 0;
    string name{};
    int eggs = 0;
    int nurse = 0;
    string subType{};
    int addMore = 0;
    string menu = " Tracking Number, Animal Name, Animal Type, Type Label, Sub Type,  Number of Nurses(Babies), Number of Eggs";
   //==============Beginning of user input================================
    do {
        // getting user input for adding animal 
        cout << "Input Tracking Number#: " << endl;
        cin >> trackingNumber; // int 
        //=================User Input Check
        for (int i = 0; i < 100 && cin.fail(); i++)
        {
            cout << "ERROR: \"tracking number\" must be a number." << endl << endl;
            cin.clear(); // clear isostream
            cin.ignore(); //ingores previous  input 
            cout << "Input Tracking Number#: " << endl;
            cin >> trackingNumber;
        }
        //============= Name ======= 
        cout << "Input Name: " << endl;
        cin >> name; // string 
        //=================User Input Check
        for (int i = 0; i < 1; i++) {
            if (!(cin.good())){ //<---- the string validation does work quite correctly 
             
                cout << "Name can only be letters" << endl;
                cin.clear(); // clear isostream
                cin.ignore(); //ingores previous  input 
                cout << "Input Name: " << endl;
                cin >> name;
            }
        }

        cout << "Input Animal Type. Enter 1 for Oviparous or 2 for Mammal: " << endl;
        cin >> animalType; // int 
        //=================User Input Check
        for (int i = 0; i < 100 && cin.fail(); i++)
        {
            cout << "ERROR: \"animal type\" must be a number." << endl << endl;
            cin.clear(); // clear isostream
            cin.ignore(); //ingores previous  input 
            cout << "Input Animal Type. Enter 1 for Oviparous or 2 for Mammal: " << endl;
            cin >> animalType;
        }
        //======================== end

        if (animalType == 1) {
            //==================== getting user input for oviparous   
            cout << "Input Number of Eggs: " << endl;
            cin >> eggs;//int 
            //=================User Input Check
            for (int i = 0; i < 100 && cin.fail(); i++)
            {
                cout << "ERROR: \"tracking number\" must be a number." << endl << endl;
                cin.clear(); // clear isostream
                cin.ignore(); //ingores previous  input 
                cout << "Input Number of Eggs: " << endl;
                cin >> eggs;
            }

            cout << "Input Sub-Type: " << endl;
            cin >> subType;// string
             //=================User Input Check
            for (int i = 0; i < 1; i++) {
                if (!(cin.good())){//<---- the string validation does work quite correctly 
                    cout << "Sub type can only be letters" << endl;
                    cin.clear(); // clear isostream
                    cin.ignore(); //ingores previous  input 
                    cout << "Input Sub Type: " << endl;
                    cin >> subType;
                }
                
            }
           //=================User Input Check
            cout << endl;
            //========================== end 

            oviparous sadOvi = oviparous(eggs, subType, trackingNumber, name); // creating oviparous
            listAni.push_back((animal*)&sadOvi); // putting in vector
            ofstream outputRecord1; // creating and saving to zooRecord.csv
            ofstream outputRecord2;
            outputRecord1.open("ZooDataBaseCopy.sql", ios::in | ios::app);
            outputRecord2.open("ZooDataBase.sql", ios::out | ios::app);
            if (animalCount == 0) { // add menu if zooRecord does is zero
                outputRecord2 << menu << endl;
            }
            animalCount++;
            outputRecord1 << sadOvi; // add record to copy data
            outputRecord2 << sadOvi; // add mammal to zooRecord.cpp
            outputRecord1.close(); // closing file 
            outputRecord2.close(); // closing file 
     
            cout << endl;
            //========Seeing if user wants to add another animal========
            cout << "Success add and saving your animal to the file!" << endl;
            cout << "Would you like to add another animal? " << endl;
            cout << "Enter 1 for Yes or 0 for No" << endl;
            cin >> addMore;
            cout << endl;
            
            //================== end of oviparous ========================================  
        }

        else {
            //==================== getting user input for mammal 
            cout << "Input Number of Nurse(Babies): " << endl;
            cin >> nurse;
            for (int i = 0; i < 100 && cin.fail(); i++)
            {
                cout << "ERROR: \"tracking number\" must be a number." << endl << endl;
                cin.clear(); // clear isostream
                cin.ignore(); //ingores previous  input 
                cout << "Input Number of Nurse(Babies):" << endl;
                cin >> nurse;
            }

            cout << "Input Sub-Type: " << endl;
            cin >> subType;
            for (int i = 0; i < 1; i++) {
                if (!(cin.good())) {//<---- the string validation does work quite correctly 
                    cout << "Sub Type can only be letters" << endl;
                    cin.clear(); // clear isostream
                    cin.ignore(); //ingores previous  input 
                    cout << "Input Sub-Type: " << endl;
                    cin >> name;
                }
            }
            cout << endl;
            // ===================== end 
            mammal madMammal = mammal(nurse, subType, trackingNumber, name); // creating mammal
            listAni.push_back((animal*)&madMammal); // add mammal to vector
            ofstream outputRecord1; // creating and saving to zooRecord.csv
            ofstream outputRecord2;
            outputRecord1.open("ZooDataBase.ssmssqlproj", ios::out | ios::app);
            outputRecord2.open("ZooDataBase.sql", ios::out | ios::app);
            
            if (animalCount == 0) { // add menu if zooRecord does is zero
                outputRecord2 << menu << endl;
            }
            animalCount++;
            outputRecord1 << madMammal; // add record to copy data
            outputRecord2 << madMammal; // add mammal to zooRecord.cpp
            outputRecord1.close(); // closing file 
            outputRecord2.close(); // closing file 
            cout << endl;
            //========Seeing if user wants to add another animal========
            cout << "Success add and saving your animal to the file!" << endl;
            cout << "Would you like to add another animal? " << endl;
            cout << "Enter 1 for Yes or 0 for No" << endl;
            cin >> addMore;
            cout << endl;
            //==========================================================
        }
    } while (addMore != 0);
}

void RemoveAnimal(vector<animal*>& listAni)// Function not working bad memory allocation.
{
    
    //https://stackoverflow.com/questions/26576714/deleting-specific-line-from-file // followed from this template on stack overflow. I was having a hard time figuring out on my own. 
    string trackNumber;
    string excute;
    string replacement = "deleted";

    ifstream inputRecord1; // creating and saving to zooRecord.csv
    ifstream inputRecord2;
    inputRecord1.open("ZooDataBaseCopy.sql", ios::in | ios::app);
    ofstream temp;
    temp.open("temp.sql");
    
    try {
        cout << "What is the tracking number you like to remove?" << endl; // tried to get it to find the string to print out the user selection with getline, but it came back with 
                                                                            //bad memory allocation. I this my attepmt to debug it. 
        cin >> trackNumber;
        inputRecord1.clear();
        temp.clear();
        inputRecord1.ignore(numeric_limits<streamsize>::max(), '\n');
        while (getline(inputRecord1, excute)) // iterate through copy file
        {
            if (excute != trackNumber)// test condition
            {
                inputRecord2.open("ZooDataBase.sql", ios::in | ios::app);// open main file
                while (getline(inputRecord2, replacement)) {

                    inputRecord2.ignore(numeric_limits<streamsize>::max(), '\n'); // ingore length limits of stream
                    size_t found = replacement.find(trackNumber); // find the tracking number
                    const void* address = static_cast<const void*>(&found);
                    std::stringstream ss;
                    ss << address;
                    std::string foundVal = ss.str();
                    if (foundVal != "12")
                        cout << "first 'needle' found at: " << foundVal << '\n';
                    else {
                        cout << "Not found" << endl;
                    }
                }
                //excute.replace(found, excute.length, replacement); // !!!!!!!!!!!!!!!! COMMITTED OUT FUNCTIONS TO DELETE USER CHOICE 
                //temp << replacement << endl;
            }
            else {
                cout << "Already deleted" << endl;
            }
        }
    }
    catch (const std::out_of_range& grr){
        std::cerr << "Out of Range error: " << grr.what() << '\n';
        
    }
        
        temp.close();
        inputRecord1.close(); // closing file 
        inputRecord2.close(); // closing file  
        //rename("ZooDataBase.sql", "discard.sql");
       // rename("temp.sql", "ZooDataBase.sql");
        //remove("discard.sql");
        cout << endl << endl << endl;
}


//============Converting a string to an int===============
// Convert string to int
int convertStringToInt(const std::string& input)
{
    std::stringstream ss(input);
    int retval;
    ss >> retval;
    return retval;
}
//========================================================
 //================Loading the file data===================

void LoadDataFromFile(vector<animal*>& listAni) // Loads and pharses data from the sql file.
    {

             // Parse input and store it in our structure
                int size = 0;
                int animalType = 0;
                string type;
                int trackingNumber = 0;
                string trackN;
                string name = " ";
                int eggs = 0;
                string eg;
                int nurse = 0;
                string nur;
                string subType = " ";
                string myData;
                string tempString;
                ifstream outputRecord;
                outputRecord.open("ZooDataBase.sql");
      
                int p = 0;
                size_t pos = 0, pos2 = 0; // Temporary position holder


                while(getline(outputRecord, myData)) {

                    size++;

                    for (int i = 0; i < size; ++i) {// How many items to insert

                        for (int j = 0; j < FIELD_SIZE; ++j) // How many fields
                        {

                            if (j < FIELD_SIZE - 1)
                            {

                                pos2 = myData.find(",", pos + 1);
                                if (pos2 == std::string::npos || pos2 > myData.find('\n', pos)) // Don't run over the next line
                                {
                                    pos = myData.find('\n', pos); // Next line
                                    cout << pos;
                                    break; // Error - invalid line format
                                }

                                switch (j) {
                                case 0: trackN = myData.substr(pos, pos2 - pos);
                                    trackingNumber = convertStringToInt(trackN);
                                    break;
                                case 1:name = myData.substr(pos, pos2 - pos);
                                    break;
                                case 2: type = myData.substr(pos, pos2 - pos);
                                    animalType = convertStringToInt(type);
                                    break;
                                case 3:
                                    break;
                                case 4:subType = myData.substr(pos, pos2 - pos);
                                    break;
                                case 5:nur = myData.substr(pos, pos2 - pos);
                                    nurse = convertStringToInt(nur);
                                    break;
                                case 6:eg = myData.substr(pos, pos2 - pos);
                                    eggs = convertStringToInt(eg);
                                    break;
                                }
                                pos = pos2 + 1;
                            }
                            else { // All data collected - parse our ints and store it in our structure
                                pos2 = myData.find('~', pos); // End of line
                                pos = pos2 + 1; // Advance position
                            }
                            if (animalType == 1) {
                                oviparous sadOvi = oviparous(eggs, subType, trackingNumber, name);
                                listAni.push_back((animal*)&sadOvi);
                                cout << sadOvi;

                            }
                            else {
                                mammal madMammal = mammal(nurse, subType, trackingNumber, name);
                                listAni.push_back((animal*)&madMammal);
                                cout << madMammal;
                            }
                        }
                    }
                }// end of while loop
                outputRecord.close();
         
} // end of LoadDataFile
    // ============================ End of loading file=====================

    // ============================ Searching file for Animal==========================

void SearchForAnimal(vector<animal*> &listAni, int argc, char** argv) // Searches for animal doesn't work. Memory allocation error. The try and catch was my attmept to debug. 
{ 
    /*
    //http://www.cplusplus.com/forum/beginner/14975/ 

    try {
        // Search for animal 
        const char* textmatch = argv[1];
        const char* filename = argv[2];
        const char* CHAR;
        string trackNumber;
        string excute;
        string s;
        string t;
        //opening sql database
        ifstream inputRecord1; // creating and saving to zooRecord.csv
        inputRecord1.open("ZooDataBaseCopy.sql", ios::in | ios::app);

        cout << "What is the tracking number you like to remove?" << endl; // tried to get it to find the string to print out the user selection with getline, but it came back with 
                                                                            //bad memory allocation. I this my attepmt to debug it. 
        cin >> trackNumber;
        inputRecord1.clear();
        inputRecord1.ignore(numeric_limits<streamsize>::max(), '\n');
        while (getline(inputRecord1, excute)) // iterate through copy file
        {
            if (excute != trackNumber)// test condition
            {
                ifstream f(filename);
                  if (!f){
                       cerr << "Could not open file " << filename << endl;
                     
                    }
                   // Read the entire file into memory
                  while (getline(f, t)) {
                      s += t + '\n';
                      f.close();


                      // For each match, print line number and column number
                      for (string::size_type index = s.find(text2match, 0);
                          index != string::npos;
                          index = s.find(text2match, index + 1))
                  
                      {
                        string::size_type line = count(s.begin(), s.begin() + index, '\n') + 1;
                        string::size_type column = index - s.rfind('\n', index);

                        cout << CHAR(10) << right << line << " : " << " : " << " : " << " : " << " : " << " : " << left << column << endl;                          
                      }
                      catch (const std::out_of_range& grr) {
                          std::cerr << "Out of Range error: " << grr.what() << '\n';

                      }
                      */
       }
// ==================== Printing the zooRecord File===============
void DisplayAnimalData() { // PRINT OUT FILE. This works, but it isnt pretty on the output. 

    string myData;
    ifstream outputRecord("zooRecord.sql");
    int i = 0;
    int e = 0;
    char* holdData[500];
    int len;
    cout << endl;
    while (getline(outputRecord, myData)) {

        len = myData.length();
        holdData[e] = new char[len + 1];

        for (std::string::iterator it = myData.begin(); it != myData.end(); ++it) {
            holdData[e][i] = *it;
            cout << holdData[e][i];
            i++;

            if ((const char*)holdData[e][i] == "\n") {
                e++;
            }
        }

        cout << "\n";
    }
    cout << endl;
    cout << endl;
    outputRecord.close();
}
//======================= end of print out zooRecord========================

//====Holding the Data from the zooRecord to be set and store in  LoadDataFromFile=======


//====================User choice menu======================================================
void DisplayMenu(vector<animal*>& listAni, int animalCount) // Had print out function in the menu
{
    int userChoice = 0;
    do {

        cout << "============================================================" << endl;
        cout << "-------------------Wildlife Zoo Main Menu-------------------" << endl;
        cout << endl;
        cout << "                    Print File        [1]" << endl;
        cout << "                    Load Data         [2]" << endl;
        cout << "                 Add and Save Record  [3]" << endl;
        cout << "                    Delete Record     [4]" << endl;
        cout << "                    Search for Animal [5]" << endl;
        cout << "                    To Exit           [6]" << endl;
        cin >> userChoice;


        for (int i = 0; i < 100; i++)
        {
            if (userChoice > 6 || cin.fail()) {

                cout << "ERROR: \"your input \" must be a number and less than 7." << endl;
                cin.clear(); // clear isostream
                cin.ignore(); //ingores previous  input 

                cout << "============================================================" << endl;
                cout << "-------------------Wildlife Zoo Main Menu-------------------" << endl;
                cout << endl;
                cout << "                    Print File        [1]" << endl;
                cout << "                    Load Data         [2]" << endl;
                cout << "                 Add and Save Record  [3]" << endl;
                cout << "                    Delete Record     [4]" << endl;
                cout << "                    Search for Animal [5]" << endl;
                cout << "                    To Exit           [6]" << endl;
                cin >> userChoice;

            }
            else if (userChoice < 6 && userChoice > 0) {
                switch (userChoice) {
                case 1: //load animal data
                    DisplayAnimalData();
                    break;
                case 2: //generate data
                    LoadDataFromFile(listAni);
                    break;
                case 3:
                    AddAnimal(listAni, animalCount);
                    break;
                case 4: // delete record
                    RemoveAnimal(listAni);
                    break;
                case 5:
                    //SearchForAnimal();
                    break;
                }

                cout << "============================================================" << endl;
                cout << "-------------------Wildlife Zoo Main Menu-------------------" << endl;
                cout << endl;
                cout << "                    Print File        [1]" << endl;
                cout << "                    Load Data         [2]" << endl;
                cout << "                 Add and Save Record  [3]" << endl;
                cout << "                    Delete Record     [4]" << endl;
                cout << "                    Search for Animal [5]" << endl;
                cout << "                    To Exit           [6]" << endl;
                cin >> userChoice;

            }
        }

    } while (userChoice != 6);
}
//====================== end of user menu=========
//======================= main function===========
int main(int argc, char** argv)
{
    int animalCount = 0;
    vector<animal*> listAni;
    DisplayMenu(listAni, animalCount);

    return 0;
}