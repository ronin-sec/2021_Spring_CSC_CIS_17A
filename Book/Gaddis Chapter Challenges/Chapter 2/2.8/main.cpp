/* 
 * File:        	main.cpp
 * Author:      	Antero Avalos
 * Date Created:    	02/18/21 4:09 pm
 * Date Finished:       02/18/21 4:20 pm
 * Purpose:     	Land Calculation
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

int main(int argc, char** argv) {
    
    //Literals were used because of the Chapter contents. (Literals were covered)
    
    double acre = 43560;        //Square feet in an acre of land
    double sqMeter = 10.7639;   //Square feet in a square meter
    double lot =  12;           //given lot size in acres 
    
    double nSqFeet = acre * lot;        //number of sq. feet in lot
    double nSqMetr = acre / sqMeter;    //number of sq.meters in lot   
    
    //display the result 
    cout << "There is " <<  nSqFeet << " square feet and " << nSqMetr << " square meters in a 12 acre lot." << endl;
    
    return 0;
}