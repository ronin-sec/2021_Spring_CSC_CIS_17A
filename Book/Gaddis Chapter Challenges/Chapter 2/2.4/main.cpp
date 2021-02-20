/* 
 * File:        	main.cpp
 * Author:      	Antero Avalos
 * Date Created:    	02/18/21 3:01 pm
 * Date Finished:       02/18/21 3:08 pm
 * Purpose:     	Restaurant bill 
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

int main(int argc, char** argv) {
    
    double mCharge = 44.50; //Meal charge literal, can be made variable anytime lol
    double tax = mCharge * 6.75 / 100;  //Tax, 6.75%
    double tip = mCharge * 15.0 / 100;  //Tip, 15% 
    double total = mCharge + tax + tip; //Total bill
    
    cout << "Bill: " << endl << endl;
    cout << "Meal Charge:       $" <<  mCharge << endl; 
    cout << "Tax:               $" << tax << endl;
    cout << "Tip:               $" << tip << endl << endl; 
    
    cout << "Total:             $" << total << endl;
    
    return 0;
}