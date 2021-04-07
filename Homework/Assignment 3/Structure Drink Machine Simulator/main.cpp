/* 
 * File:   Structure Drink Machine Simulator
 * Author: Antero Avalos
 * Created on 04/05/2021
 * Purpose:  Homework
 */

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string>
#include <string.h>
using namespace std;

//Structure Declarations
struct Drink{
    string name;        //Name of the drink
    int price;        //Price 
    int availableNum;   //Quantity available 
};

//Function Prototypes
void dispMenu(Drink []);
void dispArray(char[], int);

int main(){
    const int ARR_SZ = 5; //Array size
    //struct array for sodas
    struct Drink drinkArr[ARR_SZ] = {   {"Cola", 75, 20}, 
                                        {"Root Beer", 75, 20},
                                        {"Lemon-Lime", 75, 20},
                                        {"Grape Soda", 80, 20},
                                        {"Cream Soda", 80, 20}};
                                        
    
    //Loop until user quits 
    int revenue = 0;
    bool dispense  = true;
    //tried here, ignore doesnt work
    do
    {
        dispMenu(drinkArr);
        string input;        
        getline(cin, input);
        char selection[80];
        for (int i = 0; i < input.length(); i++)
        {
            selection[i] = input[i];  
        }
        int len = input.length();
        /*
        cout << "Testin contents of selection: \n";
        for (int i = 0; i < input.size(); i++)
        {
            cout << selection[i];
        }
        cout << endl;
        */
        //----------------------Everything good till here

        int payment = 0;
        int change = 0;
        char quit[] = "Quit";
        
        

        //Check if the user has quit
        if(strncmp(selection, quit, len) == 0){
            dispense = false;
            break;
        }
        //If not quitting the program, get payment 

        cin >> payment;
        revenue += payment;


        //Then we iterate through drinkArr to find the drink user wants
        for(int i = 0; i < ARR_SZ; i++){
            //Store name of current drink in char array to compare with user selection
            string n = drinkArr[i].name;
            char currName[80];
            for (int i = 0; i < n.length(); i++){
                currName[i] = n[i]; 
            }
            //If the selection matches the current drink name
            // do the following:
            if(strncmp(selection, currName, len) == 0){
                //cout << "found" << endl;
                drinkArr[i].availableNum--;
                change = payment - drinkArr[i].price;
                break;
            }
        }
        revenue -= change;
        cout << change << endl;
        cin.ignore();
    } while (dispense != false);

    //cin.sync();
    
    cout << revenue << endl;

    return 0;   
}

//Function Definitions 
void dispMenu(Drink drinkArr[]){
    cout
        <<  drinkArr[0].name << "       " << drinkArr[0].price << "  " << drinkArr[0].availableNum << '\n'
        <<  drinkArr[1].name << "  " << drinkArr[1].price << "  " << drinkArr[1].availableNum << '\n'
        <<  drinkArr[2].name << " " << drinkArr[2].price << "  " << drinkArr[2].availableNum << '\n'
        <<  drinkArr[3].name << " " << drinkArr[3].price << "  " << drinkArr[3].availableNum << '\n'
        <<  drinkArr[4].name << " " << drinkArr[4].price << "  " << drinkArr[4].availableNum << '\n'
        << "Quit" << endl;
}


void dispArray(char str[], int size){
    for (int i = 0; i < size; i++)
    {
        cout << str[i];
    }
    cout << endl;
}