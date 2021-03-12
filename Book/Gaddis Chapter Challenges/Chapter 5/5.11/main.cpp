/* 
 * File:        	main.cpp
 * Author:      	Antero Avalos
 * Date Created:    	02/22/2021 2:30 pm
 * Date Finished:       02/22/2021 3:00 pm
 * Purpose:     	Membership Fee Increase
 *                      
 */

//System Libraries
#include <iostream>  //I/O Library
#include <iomanip>   //I/O Manipulation
using namespace std;

int main()
{
    //Variables
    float oldFee = 3000, 
           increase,
           newFee = oldFee + increase,
           temp;
    
    int year = 1;

    //table header
    cout << "The membership fee increase will be as follows: " << endl;
    cout << setw(30) << "Increase  for the Year" << setw(15) << "New Fee" << endl;
    
    //loop for table
    while (year <= 5)
    {
        cout << fixed << "Year " << year << ":" << setw(15)<< setprecision(2) << increase << "             " << setw(10) << newFee << endl;
        newFee = newFee + increase;
        oldFee = newFee;
        increase = oldFee * 0.03;
        year++;
    }
    return 0;
}