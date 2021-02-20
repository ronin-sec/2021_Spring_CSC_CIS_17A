/* 
 * File:        	main.cpp
 * Author:      	Antero Avalos
 * Date Created:    	02/18/21 3:27 pm
 * Date Finished:       02/18/21 3:28 pm
 * Purpose:     	Miles per gallon
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

int main(int argc, char** argv) {
    
    //Literals were used because of the Chapter contents. (Literals were covered)
    
    double tankSize = 16; //Tank size given in challenge description
    double milesBR = 312; //Miles before refueling, also in challenge description
    
    double mpg = milesBR / tankSize; //MPG calculated and assigned
    
    //Display result on screen:
    cout << "The miles per gallon of a vehicle that has the following characteristics: \n"
            "Miles before  refueling:       " << milesBR << endl << 
            "Tank size:                     " << tankSize << endl <<
            "MPG:                           " << mpg << endl;

    return 0;
}