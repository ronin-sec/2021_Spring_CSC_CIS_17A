/* 2. File Display Program
Write a program that asks the user for the name of a file. The program should display the
contents of the file on the screen. If the file’s contents won’t fit on a single screen, the program
should display 24 lines of output at a time, and then pause. Each time the program
pauses, it should wait for the user to strike a key before the next 24 lines are displayed.
 * 
 * File:   main.cpp
 * Author: Antero Avalos
 *
 * Created on May 1, 2021, 6:19 PM
 */

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;


int main(int argc, char** argv) {
    //Variables
    string fileName, line;
    char keyPress;
    int lineCt = 0;
    
    //Get file name from user
    cout << "Enter name of file: ";
    cin >> fileName;
    
 
    //Open file using input mode flag 
    fstream file(fileName, ios::in);
    
    //if file not present
    if (!file){
        cout << "File not found!!\n"; //Output error message 
        return 0;
    }
    //while loop gets contents per line and stores in "line" var 
    while(getline(file, line)){
        lineCt++;       //Line counter to keep track of the 24 line max 
        cout << line << endl;
        if(lineCt % 24 == 0){ //If max reached 
            cin.ignore();
            cin.get(keyPress); //wait for key press and output next 24 lines 
        }
    }            
    
    //End of program 
    return 0;
}

