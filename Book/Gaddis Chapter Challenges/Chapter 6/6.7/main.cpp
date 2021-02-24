/* 
 * File:        	main.cpp
 * Author:      	Antero Avalos
 * Date Created:    	02/22/2021 3:00 pm
 * Date Finished:       02/22/2021 3:30 pm
 * Purpose:     	Most Fuel Efficient Car
 *                      
 */

//System Libraries
#include <iostream>  //I/O Library
#include <iomanip>   //I/O Manipulation
using namespace std;

//Function Prototypes
float calcMPG(float distanceDriven, float gallonsUsed);


int main()
{       
    //Variables 
    float distanceDriven = 500,
           gallonsUsed1,
           gallonsUsed2,
           gallonsUsed3,
           MPG1,
           MPG2,
           MPG3;

    string car1,
           car2,
           car3;

    float stopAsking =  false;
    
    int i = 1;

    cout << "Please enter make of first vehicle: " << endl;
    getline(cin, car1);
    cout << "Enter gallons used: " << endl;
    cin >> gallonsUsed1;
    MPG1 = calcMPG(distanceDriven, gallonsUsed1);
    cin.ignore();


    cout << "Please enter make of second vehicle: " << endl;
    getline(cin, car2);
    cout << "Enter gallons used: " << endl;
    cin >> gallonsUsed2;
    MPG2 = calcMPG(distanceDriven, gallonsUsed2);
    cin.ignore();



    cout << "Please enter make of third vehicle: " << endl;
    getline(cin, car3);
    cout << "Enter gallons used: " << endl;
    cin >> gallonsUsed3;
    MPG3 = calcMPG(distanceDriven, gallonsUsed2);
    cin.ignore();


    if (MPG1 > MPG2 && MPG1 > MPG3)
    {
        cout << car1 << " is the most efficient with an MPG of " << MPG1 << " miles per gallon." << endl;
    }
    else if (MPG2 > MPG1 && MPG2 > MPG3)
    {
        cout << car2 << " is the most efficient with an MPG of " << MPG2 << " miles per gallon." << endl;
    }
    else
    {
        cout << car3 << " is the most efficient with an MPG of " << MPG3 << " miles per gallon." << endl;
    }

	return 0;
}

//function definitions

/**
 * @brief calculates MPG using distance driven and gallons used
 * 
 * @param distanceDriven distance driven in miles
 * @param gallonsUsed gallons of gasoline used by vehicle
 * @return double = MPG 
 */
float calcMPG(float distanceDriven, float gallonsUsed)
{
    float MPG =  distanceDriven / gallonsUsed;
    return MPG;
}