/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: anter
 *
 * Created on 04/28/2021
 */

#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * 
 */

//Function Prototypes
void getUnsShF();    //Factorial calculation for unsigned shorts
void getShF();       //Factorial calculation for shorts

void getIntF();       //Factorial calculation for integers 
void getUnsIntF();    //Factorial calculation for unsigned integers 

void getFloatF();     //Factorial calculation for floats

void getDoubleF();    //Factorial calculation for doubles 


int main(int argc, char** argv) {

    //getIntF();
    
    //getUnsIntF();
    
    //getUnsShF();
    
    //getShF();
    
    //getFloatF();
    
    getDoubleF();

    return 0;
}


//Function Definitions
void getIntF(){
    //Prompt user for a number to get factorial of
    cout << "Enter the value of n (must be a number):\n"; 
    
    //Variables, change type here if needed
    int n;          //Number to get factorial of
    int factorial = 1;  //Factorial, pretty self explanatory 
    
    //getting user input 
    cin >> n;
    
    //Now we can calculate the factorial of given number and see if it overflows?
    for (int i = 1; i <= n; i++){
        factorial *= i;
    }
    
    cout << "Factorial of " << n << " = " << factorial;
}

void getUnsIntF(){
    //Prompt user for a number to get factorial of
    cout << "Enter the value of n (must be a number):\n"; 
    
    //Variables, change type here if needed 
    unsigned int n;          //Number to get factorial of
    unsigned int factorial = 1;  //Factorial, pretty self explanatory 
    
    //getting user input 
    cin >> n;
    
    //Now we can calculate the factorial of given number and see if it overflows?
    for ( unsigned int i = 1; i <= n; i++){
        factorial *= i;
    }
    
    cout << "Factorial of " << n << " = " << factorial;
}

void getUnsShF(){
    //Prompt user for a number to get factorial of
    cout << "Enter the value of n (must be a number):\n"; 
    
    //Variables, change type here if needed 
    unsigned short n;          //Number to get factorial of
    unsigned short factorial = 1;  //Factorial, pretty self explanatory 
    
    //getting user input 
    cin >> n;
    
    //Now we can calculate the factorial of given number and see if it overflows?
    for (int i = 1; i <= n; i++){
        factorial *= i;
    }
    
    cout << "Factorial of " << n << " = " << factorial;
}

void getShF(){
    //Prompt user for a number to get factorial of
    cout << "Enter the value of n (must be a number):\n"; 
    
    //Variables, change type here if needed 
    short n;              //Number to get factorial of
    short factorial = 1;  //Factorial, pretty self explanatory 
    
    //getting user input 
    cin >> n;
    
    //Now we can calculate the factorial of given number and see if it overflows?
    for (int i = 1; i <= n; i++){
        factorial *= i;
    }
    
    cout << "Factorial of " << n << " = " << factorial;
}

void getFloatF(){
    //Prompt user for a number to get factorial of
    cout << "Enter the value of n (must be a number):\n"; 
    
    //Variables, change type here if needed 
    float n;              //Number to get factorial of
    float factorial = 1;  //Factorial, pretty self explanatory 
    
    //getting user input 
    cin >> n;
    
    //Now we can calculate the factorial of given number and see if it overflows?
    for (int i = 1; i <= n; i++){
        factorial *= i;
    }
    
    cout << "Factorial of " << n << " = " << factorial;
}

void getDoubleF(){
    //Prompt user for a number to get factorial of
    cout << "Enter the value of n (must be a number):\n"; 
    
    //Variables, change type here if needed 
    double n;              //Number to get factorial of
    double factorial = 1;  //Factorial, pretty self explanatory 
    
    //getting user input 
    cin >> n;
    
    //Now we can calculate the factorial of given number and see if it overflows?
    for (int i = 1; i <= n; i++){
        factorial *= i;
    }
    
    cout << "Factorial of " << n << " = " << factorial;
}

