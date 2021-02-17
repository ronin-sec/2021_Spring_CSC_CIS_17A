/* 
 * File:        	main.cpp
 * Author:      	Antero Avalos
 * Date Created:    	02/17/21 12:23 pm
 * Date Finished:       02/17/21 12:30 pm
 * Purpose:     	Flower Garden Size
 * 
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

int main(int argc, char** argv) {
    // Variables
    double len, width, sqFeet;

    //Get garden length
    cout << "Enter length of garden (in ft.): ";
    cin >> len;

    //Get garden width
    cout << "Enter garden width (in ft.):" ; 
    cin >> width; 

    //Calculate square footage
    sqFeet = len * width;

    //Display result
    cout << "Garden square footage is: " << sqFeet << "'" << endl;
    
    return 0;
}