/* 
 * File:        	main.cpp
 * Author:      	Antero Avalos
 * Date Created:    	02/18/21 2:24 pm
 * Date Finished:       02/18/21 2:33 pm
 * Purpose:     	Sales Prediction
 * 
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

int main(int argc, char** argv) {
    int sales;  //Sales amount and result from calculation
    
    cout << "Enter sales for East Division for this year: "; //Get sales amount
    cin >> sales; 
    
    int eightP = sales * 58 / 100; //Calculates 58 percent of the entered sales amount
    
    cout << "The expected sales of the East Coast division should be " << eightP << "." << endl;
    return 0;
}