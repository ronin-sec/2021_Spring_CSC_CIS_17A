/*
7. Sentence Filter
 * 
A program that processes an input file and produces an output file is called a filter. Write
a program that asks the user for two file names. The first file will be opened for input and
the second file will be opened for output. (It will be assumed that the first file contains
sentences that end with a period.) The program will read the contents of the first file and
change all the letters other than the first letter of sentences to lowercase. First letter of
sentences should be made uppercase. The revised contents should be stored in the second
file.  
*/

/* 
 * File:   main.cpp
 * Author: anter
 *
 * Created on May 1, 2021
 */

//System Libraries 
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <cctype>
#include <string>

using namespace std;

int main(int argc, char** argv) {
    //Variables 
    string unformatted, //Holds the name of formatted file
            formatted,  //Holds name of formated 
            lineTxt;   //Holds line contents
    
    char keyPress; //Holds key press 
    int readPos, writPos; //used to store read and write positions 
    
    
    //Get files names from user 
    cout << "Enter the name of the file with unformatted text: ";
    cin >> unformatted;
    
    cout << "Now enter the name of the file you wish to save the formatted text in: ";
    cin >> formatted; 
    
    //open the unformatted file for reading
    fstream inpFile(unformatted, ios::in);
    
    //Check for file presence/existence
    if(!inpFile){
        cout << "File not found!!\n"; //Display error if not found 
        return 0;                     //Terminate program if file missing 
    }
    
    //open the file that will store formatted output for writing
    fstream outFile(formatted, ios::out);
    
    inpFile.clear(); //clear all error flags that may be found in input file
    inpFile.seekg(0, ios::beg); //set read pos to first byte of file
    outFile.seekp(0, ios::beg); //set write pos to first byte of file
    readPos = inpFile.tellg();  
    
    while(!inpFile.fail()){
        
        writPos = inpFile.tellg();
        getline(inpFile, lineTxt); 
        for (int i = 0; i < lineTxt.length(); i++){
            if(readPos == writPos){
                
                if(isalpha(lineTxt[0])){
                    lineTxt[0] = toupper(lineTxt[0]);
                }
                if(isspace(lineTxt[0])){
                    lineTxt[1] = toupper(lineTxt[1]);
                }
            }
            else if(lineTxt[i] == '.')
            {
                
                if(isalpha(lineTxt[i]))
                {
                    lineTxt[i] = toupper(lineTxt[i]);
                }
                if (isspace(lineTxt[i+1]))
                {
                    lineTxt[i + 2] = toupper(lineTxt[i + 2]);
                    i += 2;
                }
            }
            else
            
                lineTxt[i] = tolower(lineTxt[i]);
            
                
        }
        
        outFile << lineTxt << endl;
        
    }
    
    inpFile.close();
    outFile.close();
    return 0; 
}

