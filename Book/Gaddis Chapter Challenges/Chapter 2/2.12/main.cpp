/* 
 * File:        	main.cpp
 * Author:      	Antero Avalos
 * Date Created:    	02/18/21 5:23 pm
 * Date Finished:       02/18/21 5:25 pm
 * Purpose:     	Triangle Pattern
 */

//System Libraries
#include <iostream>         //I/O Library
#include <iomanip>          //I/O Manipulation
#include <bits/stdc++.h>    //Used for string concatenation

using namespace std;

int main(int argc, char** argv) {
    
    //sloppy code, I was in a hurry to finish... 
    
    //Literals were used because of the Chapter contents. (Literals were covered)
    string one = "    *";
    string three = "   ***";
    string four = "  *****";
    string five = " *******";
    
    
    //display the above, each in a separate line, use only one cout statement
    cout << one << endl << three << endl << four << endl << five;
    cout << endl << four << endl << three << endl << one;
    return 0;
}