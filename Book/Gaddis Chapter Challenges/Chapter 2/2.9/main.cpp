/* 
 * File:        	main.cpp
 * Author:      	Antero Avalos
 * Date Created:    	02/18/21 4:25 pm
 * Date Finished:       02/18/21 4:49 pm
 * Purpose:     	Flash Drive Price
 */

//System Libraries
#include <iostream>  //I/O Library
#include <iomanip>   //I/O Manipulation
using namespace std;

int main(int argc, char** argv) {
    
    //Literals were used because of the Chapter contents. (Literals were covered)
    
    double prodCost = 8.00;                 //Production costs of 1 unit
    double desProf = prodCost * 35 / 100;   //Desired profit, 35% of total cost
    double sPrice = desProf + prodCost;     //Suggested price
    
    //display the result 
    cout << "The suggested price of the USB drives is $" << fixed << setprecision(2) << sPrice << endl;
    
    return 0;
}