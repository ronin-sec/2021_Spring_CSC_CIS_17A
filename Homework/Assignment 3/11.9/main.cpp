/* 
 * File:   11.9 Speakers’ Bureau
 * Author: Antero Avalos
 * Created on 04/05/2021
 * Purpose:  Homework
 */

#include <iostream>
#include <iomanip> 
#include <math.h>
#include <string.h>
#include <string>
using namespace std;

//struct declaration 
//Holds information about a particular speaker 
struct Speaker {
    string name;        //Speaker name
    string phoneNum;    //Telephone number 
    string topic;       //Speaking Topic
    int fee;            //Fee required/payed
};

//function prototypes
void dispMenu();                           //display menu 
void addSpeak(Speaker [], int);            //add speaker
void modSpeak(Speaker [], int, int);           //modify speaker data 
void dispSpeak(Speaker [], string, int);       //display single speaker data
void dispAll(Speaker [], int);            //display all speaker data
void modMember(Speaker [], int, int );   //modify member from speaker object

int main(){
    //Initialize array for speaker data
    const int arrMax = 10;
    struct Speaker speakArr[10] = { {" ", " ", " ",  0}, {" ", " ", " ",  0}, {" ", " ", " ",  0},
                                    {" ", " ", " ",  0}, {" ", " ", " ",  0}, {" ", " ", " ",  0},
                                    {" ", " ", " ",  0}, {" ", " ", " ",  0} };

    //Display menu of options
    bool quit  = false;
    int spkCnt = 0; //Keeps track of how many speakers have been added to array 
    cout << "Welcome to Speaker Database!\n";
    do
    {
        int menuChoice = 9999;
        dispMenu(); //display menu 

        cin >> menuChoice; //get menu choice from user

        if(menuChoice ==  0){ //If choice is 0, quit program
            quit = true;
            break;
        }else if(menuChoice == 1){ //Else if choice == 1. add speaker 
            if(spkCnt < 10){ //Can only add speaker if array has space
                addSpeak(speakArr, spkCnt);
                spkCnt++;
            }
            else{
                cout << "You reached the max number of speakers. Contact Organizer.\n" ; 
            }
        }else if(menuChoice == 2){
            modSpeak(speakArr, arrMax, spkCnt);
        }else if(menuChoice == 3){
            cout << "Enter name of speaker you would like to display\n";
            string spkrName = " "; 
            cin.ignore();
            getline(cin, spkrName);
            dispSpeak(speakArr, spkrName, spkCnt);
        }else if(menuChoice == 4){
            dispAll(speakArr, spkCnt);
        }else{
            cout << "Please select a menu option (Use #s E.X: 1, 2, 3, 4, 0)." << endl;
        }

    } while (quit != true);
    

}

//function definitions
void dispMenu(){
    cout 
             << "What would you like to do? (Enter selection #, E.X: 1, 2, 3, 4, 0): \n\n"
             << "1. Add Speaker.\n"
             << "2. Modify Speaker Info.\n"
             << "3. Display Single Speaker Info.\n"
             << "4. Display All Speaker's Info.\n"
             << "0. Quit.\n\n";
}

void addSpeak(Speaker speakArr[], int spkCount){
    string name = "",
           phone = "",
           topic = "";
    float fee = 0;
    
    cin.ignore();
    cout << "Enter speaker data as prompted: \n";
    cout << "Name of Speaker: \n";
    getline(cin, name);
    cout << "Contact number : ";
    getline(cin, phone);
    cout << "Speaking Topic : ";
    getline(cin, topic);
    cout << "Fee Required: ";
    cin >> fee;

    speakArr[spkCount].name = name;
    speakArr[spkCount].phoneNum = phone;
    speakArr[spkCount].topic = topic;
    speakArr[spkCount].fee = fee;

}

void modSpeak(Speaker spkrArr[], int arrMax, int spkCnt){
    //Variables to store values for member modification 
    string nameIn = "", 
           phoneIn = "",
           topicIn = "";
    float feeIn = 0;

    //Get a speaker name from user
    cout << "Enter name of speaker you'd like to modify info about: ";
    cin.ignore();
    getline(cin, nameIn);

    //copy name input into char array for strcmp, thats all this looop does
    int len = nameIn.length();
    char nameInput[80];
    for (int i = 0; i < len; i++){
        nameInput[i] = nameIn[i];
    }

    //begin iterating the speaker array in search of speaker to mod
    char currName[80];
    for (int i = 0; i < arrMax; i++){
        //copy current speaker name into char array for strncmp
        string n = spkrArr[i].name;
        for (int j = 0; j < len; j++){
            currName[j] = n[j]; 
        }

        //do strcmp to find speaker
        if(strncmp(currName, nameInput, len) == 0){
            cout << "What information would you like to change: " << endl;

            dispSpeak(spkrArr, nameIn, spkCnt);

            cout << "(Enter selection #, E.X: 1, 2, 3, 4)" << endl;

            int selection = 0;
            cin >> selection; 

            modMember(spkrArr, i, selection);

            break;
        }
    }
}

void dispAll(Speaker spkrArr[], int spkrCount){
    cout << "All speakers: " << endl;
    for (int i = 0; i < spkrCount; i++)
    {
        string currName = spkrArr[i].name;
        dispSpeak(spkrArr, currName, spkrCount);
    }
    
} 

void dispSpeak(Speaker spkrArr[], string spkrName, int spkrCount){

    for (int i = 0; i < spkrCount; i++)
    {
        string currName = spkrArr[i].name;
        int len = spkrName.length();
        //Need to convert both strings to char arrays in order
        //to use strcmp... sheesh
        char currN[80];
        char spkrN[80];
        for (int i = 0; i < len; i++)
        {
            currN[i] = currName[i];
            spkrN[i] = spkrName[i];
        }

        if(strncmp(spkrN, currN, len) == 0){
        cout << "This is the current information available for " 
        << spkrArr[i].name << ".\n";

        cout << "1.Name of Speaker: " << spkrArr[i].name << endl
             << "2.Contact number : " << spkrArr[i].phoneNum << endl
             << "3.Speaking Topic : " << spkrArr[i] .topic << endl
             << "4.Fee Required   : $" << spkrArr[i].fee << endl;
        }
    }
    

        
}


void modMember(Speaker spkArr[], int index, int memberSelection){
    string input = "";
    float feeIn = 0;

    if(memberSelection == 1){ //Mod name 
        getline(cin, input);
        spkArr[index].name = input;
    }else if(memberSelection == 2){ //Mod phone number
        getline(cin, input);
        spkArr[index].phoneNum = input;
    }else if(memberSelection == 3){//Mod speaknig topic
        getline(cin, input);
        spkArr[index].topic = input;
    }else if(memberSelection ==  4){//Mod speaker fee
        cin >> feeIn; 
        spkArr[index].fee = feeIn;
    }else{                   //Error message if the selection is inadequate
        cout << "No corresponding data exists!" << endl;
    }
}