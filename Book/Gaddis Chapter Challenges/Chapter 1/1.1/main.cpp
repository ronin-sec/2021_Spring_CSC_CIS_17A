/* 
 * File:        	main.cpp
 * Author:      	Antero Avalos
 * Date Created:    	02/17/21 12:19 pm
 * Date Finished:       02/17/21 12:23 pm
 * Purpose:     	Calculate candy bar sales
 * 
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

int main(int argc, char** argv) {
    // Variables
    double bars, barProf, totProf;

    //Get number of bars sold
    cout << "How many bars were sold?";
    cin >> bars;

    //Get profit per bar
    cout << "Margin per bar?"; 
    cin >> barProf; 

    //Calculate total profit
    totProf = bars * barProf;

    //Display result
    cout << "Total profit from bar sales was: $" << totProf << endl;
    
    return 0;
}