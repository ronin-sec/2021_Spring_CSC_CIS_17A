/* 
 * File:        	main.cpp
 * Author:      	Antero Avalos
 * Date Created:    	02/18/21 3:58 pm
 * Date Finished:       02/18/21 4:02 pm
 * Purpose:     	Number of acres
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

int main(int argc, char** argv) {
    
    //Literals were used because of the Chapter contents. (Literals were covered)
    
    double acre = 43450;            //square feet per acre
    double tract = 869 * 360;       //given size of tract of land 
    double nAcres = tract / acre;   //number of acres in given tract
    
    //display the result 
    cout << "There is " << nAcres << " acres in a tract of land that measures 869' by 360'." << endl;
    
    return 0;
}