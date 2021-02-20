/* 
 * File:        	main.cpp
 * Author:      	Antero Avalos
 * Date Created:    	02/20/2021 12:07 pm
 * Date Finished:       02/20/2021 12:34 pm
 * Purpose:     	Adjusts ingredient quantities using a given number of cookies
 *                      
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;


int main(int argc, char** argv) {
    //Variables
    float sugar = 1.5; //Cups needed to produce 48 cookies
    short butter = 1;  //cups needed to produce 48 cookies
    float flour = 2.75;//cups needed to produce 48 cookies
    float oneCkie = 48;//Used to divide the above amounts, then multiply to get the adequate amounts of ingredients 
    short cWanted;     //Number of cookies the user wants to make 
    
    
    //Get user input 
    cout << "How many cookies would you like to make today? : " << endl;
    cin >> cWanted;
            
    //Display results
    cout << "You need the following amounts to make " <<  cWanted << " cookies :" << endl << endl;
    cout << flour  / oneCkie * cWanted << " cups of flour." << endl;
    cout << butter / oneCkie * cWanted << " cups of butter." << endl;
    cout << sugar  / oneCkie * cWanted << " cups of sugar." << endl;
    
    //Exit the Program - Cleanup
    return 0;
}