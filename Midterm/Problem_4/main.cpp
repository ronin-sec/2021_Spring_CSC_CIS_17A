
/* 
 * File:   main.cpp
 * Author: Antero
 *
 * Created on 04/28/2021
 */

//System Libraries 
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//Function Prototypes
void getNum(int &);       //Get 4 integer number from user
int * encrypt(int );      //Encrypts 4 integer number
int * decrypt(int );        //Decrypts 4 integer number 

void dispArr(int *);      //Display contents of array of pointers

//-------------------------------MAIN starts here-------------------------------
int main(int argc, char** argv) {
    cout << "Press Enter to Begin" << endl;
    int data = 0;

    int * ncryptd = nullptr;
    int * dcryptd = nullptr;

    cin.ignore();
    //Menu
    bool exit = false;
    
    do
    {
        cout << "\n\nWhat would you like to do?:\n"
             << "1.Encrypt.\n"
             << "2.Decrypt.\n"
             << "0.Exit.\n";

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout <<  "ENCRYPTER: \n\n";
            getNum(data);
            ncryptd = encrypt(data);
            cout << "Encrypted number: ";
            dispArr(ncryptd);

            break;
            
        case 2:
            cout <<  "DECRYPTER: \n\n";
            getNum(data);
            dcryptd = decrypt(data);
            cout << "Decrypted number: ";
            dispArr(dcryptd);
            break;

        case 0:
            exit = true;
            break;
        
        default:
            cout << "Choose a valid option! Try Again!\n";
            break;
        }

        
    } while (exit != true);
    
    cout << "Goodbye!" << endl;

    return 0;
}
//------------------------------MAIN ends here----------------------------------

//Function Definitions

//Gets input from user
void getNum(int &data){
    cout << "Enter the 4 digit integer: " << endl;

    int input;
    
    cin >> input;

    
    
    bool okInput = false;
    while(okInput != true){
        int temp1 = (input / 1000) % 10,
            temp2 = (input / 100) % 10,
            temp3 = (input / 10) % 10,
            temp4 = (input / 1) % 10;

        if(temp1 >= 8){
            cout << "Please use allowed integers (0,1,2,3,4,5,6,7)!!\n";
            cin >> input;
        }else if(temp2 >= 8){
            cout << "Please use allowed integers (0,1,2,3,4,5,6,7)!!\n";
            cin >> input;
        }else if(temp3 >= 8){
            cout << "Please use allowed integers (0,1,2,3,4,5,6,7)!!\n";
            cin >> input;
        }else if(temp4 >= 8){
            cout << "Please use allowed integers (0,1,2,3,4,5,6,7)!!\n";
            cin >> input;
        }else{
            data = input;
            okInput = true;
        }
    }       
}

//Encrypts integer provided by user
int * encrypt(int data){

    int * ncryptd = nullptr;
    
    //ENCRYPT-------------------------------------------------------------------
    //Split the given number into 4 ints
    int temp1 = (data / 1000) % 10,
        temp2 = (data / 100) % 10,
        temp3 = (data / 10) % 10,
        temp4 = (data / 1) % 10;
    //testing
    //cout << "Values from array stored in temp variables before encryption: \n";
    //cout << temp1 << " " << temp2 << " " <<  temp3 << " " <<  temp4 << endl;

    //(int + 5) % 8;
    temp1 = (temp1 + 5) % 8;
    temp2 = (temp2 + 5) % 8;
    temp3 = (temp3 + 5) % 8;
    temp4 = (temp4 + 5) % 8;
    
    //testing
    //cout << "Values from array stored in temp variables after encryption: \n";
    //cout << temp1 << " " << temp2 << " " <<  temp3 << " " <<  temp4 << endl;

    //swap 1st with 3rd, 2nd with 3rd
    ncryptd = new int[4];        

    ncryptd[0] = temp3;
    ncryptd[1] = temp4;
    ncryptd[2] = temp1;
    ncryptd[3] = temp2;

    //Sum all the numbers to create the new integer
    return ncryptd;
}

//Display contents of pointer array of ints
void dispArr(int * number){
    
    for (int i = 0; i < 4; i++)
    {
        cout << number[i];
    }
}

//Decrypts integer provided by user
int * decrypt(int data){

    int * dcryptd = nullptr;

    //Split the given number into 4 ints
    int temp1 = (data / 1000) % 10,
        temp2 = (data / 100) % 10,
        temp3 = (data / 10) % 10,
        temp4 = (data / 1) % 10;
    
    //testing
    //cout << "Values after the split: \n";
    //cout << temp1 << " " << temp2 << " " <<  temp3 << " " <<  temp4 << endl;

    //Restore the number to their orignal values
    temp1 = (temp1 + 8) - 5;
    temp2 = (temp2 + 8) - 5;
    temp3 = (temp3 + 8) - 5;
    temp4 = (temp4 + 8) - 5;

    //Swap the ints to original positions 
    dcryptd = new int[4];
    
    dcryptd[0] = temp3;
    dcryptd[1] = temp4;
    dcryptd[2] = temp1;
    dcryptd[3] = temp2;

    //this loop ensure that the values are not above 7... 
    for (int i = 0; i < 4; i++)
    {
        if(dcryptd[i] > 7){
            dcryptd[i] -= 8;
        }
    }

    return dcryptd;
}

