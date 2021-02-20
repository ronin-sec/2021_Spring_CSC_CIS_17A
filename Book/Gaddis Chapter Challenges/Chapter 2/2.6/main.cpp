/* 
 * File:        	main.cpp
 * Author:      	Antero Avalos
 * Date Created:    	02/18/21 3:40 pm
 * Date Finished:       02/18/21 3:53 pm
 * Purpose:     	Distance per tank of gas 
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

int main(int argc, char** argv) {
    
    //Literals were used because of the Chapter contents. (Literals were covered)
    
    double tankSz = 20;     //Size of vehicle tank (in gallons)
    double townMPG = 23.5;  //Town/street MPG 
    double hwyMPG = 28.9;   //Highway MPG
    
    double dptT = townMPG * tankSz; //distance per tank in town
    double dptH = hwyMPG * tankSz;  //distance per tank in highway
    
    //display the result 
    cout << "Below is the miles per tank for your vehicle: " << endl << endl;
    cout << "Street:        " << dptT << " miles." << endl;
    cout << "Highway:       " << dptH << " miles." << endl;
    
    
    
    return 0;
}