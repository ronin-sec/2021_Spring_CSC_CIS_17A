/* 
 * File:        	main.cpp
 * Author:      	Antero Avalos
 * Date Created:    	02/20/2021 11:33 am
 * Date Finished:       02/20/2021 12:00 pm
 * Purpose:     	Asks user to input how many cookies they ate,
 *                      then calculates how many calories were  consumed.
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;


int main(int argc, char** argv) {
    //Variables
    short tCookie = 30;     //total number of cookies in a box
    short calsBox =  240;   //total number of calories per box 
    short tServ = 10;       //number of cookie servings per box
    short eCookie;          //Amount of cookies that user has eaten, input 
    
    
    //Get user input (number of cookies devoured)
    cout << "How many cookies did you eat?: " << endl;
    cin >> eCookie; 
    
    //Input validation, there are only 30 cookies in a box
    if(eCookie <= 30){
        //Display Inputs/Outputs
        short calsAte = eCookie * (calsBox / tCookie);  //Calories consumed, depends on n cookies eaten
        cout << "You consumed " << calsAte << " calories by eating those " << eCookie << " cookies.";
    }else{
        cout << "There are only 30 cookies in a box. Please enter a number <= 30." << endl;
    };
    
    //Exit the Program - Cleanup
    return 0;
}