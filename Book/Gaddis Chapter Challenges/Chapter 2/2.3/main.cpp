/* 
 * File:        	main.cpp
 * Author:      	Antero Avalos
 * Date Created:    	02/18/21 2:33. pm
 * Date Finished:       02/18/21 2:43 pm
 * Purpose:     	Sales Tax
 * 
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

int main(int argc, char** argv) {
    
    cout << "Sales Tax:  " << endl;
    
    cout << "Tax:                     6.5%" <<  endl;
    cout << "Purchase Amount:        $95.00" << endl; 
    
    double sTax, totalP; //Sales tax and total amount.
    sTax = 95 * 6.5 / 100;
    totalP = 95 + sTax;
    
    
    cout << "Calculated Sales Tax:   $" << sTax << endl;
    cout << "Total purchase amount:  $" << totalP << endl;
    return 0;
}