/* 
 * File:        	main.cpp
 * Author:      	Antero Avalos
 * Date Created:    	02/18/21 5:41 pm
 * Date Finished:       02/18/21 5:51 pm
 * Purpose:     	Basketball PLayer Height 
 */

//System Libraries
#include <iostream>         //I/O Library
#include <iomanip>          //I/O Manipulation

using namespace std;

//function takes an integer value and  converts to appropriate format
void Convert(int inch)
{
	int feet, inches;
	inches = inch %12;
	feet = inch/12;
	cout << "\n\t\tThe height in feet is " << feet << "\'" << inches << "\" " << endl;
}

int main(int argc, char** argv) {
    
    //Literals were used because of the Chapter contents. (Literals were covered)    
    int pHeight = 75;    //Player height
    
  
    //Display height in feet/inches
    Convert(pHeight);
    
    return 0;
}