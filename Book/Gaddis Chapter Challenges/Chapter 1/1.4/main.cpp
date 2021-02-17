/* 
 * File:        	main.cpp
 * Author:      	Antero Avalos
 * Date Created:    	02/17/21 12:30 pm
 * Date Finished:       02/17/21 12:34 pm
 * Purpose:     	Flower Garden Cost
 * 
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

int main(int argc, char** argv) {
    // Variables
    double soil, fSeeds, totCost;

    //Get total cost of soil
    cout << "Enter the total cost of soil: $";
    cin >> soil;

    //GEt total cost of flower seeds
    cout << "Enter total cost of flower seeds: $" ; 
    cin >> fSeeds; 

    //Calculate total cost of flower garden
    totCost = soil + fSeeds;

    //Display result
    cout << "Garden square footage is: $" << totCost << endl;
    
    return 0;
}