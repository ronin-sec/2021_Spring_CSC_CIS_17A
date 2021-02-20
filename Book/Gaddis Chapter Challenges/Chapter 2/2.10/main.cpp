/* 
 * File:        	main.cpp
 * Author:      	Antero Avalos
 * Date Created:    	02/18/21 4:52 pm
 * Date Finished:       02/18/21 4:57 pm
 * Purpose:     	Personal information
 */

//System Libraries
#include <iostream>  //I/O Library
#include <iomanip>   //I/O Manipulation

using namespace std;

int main(int argc, char** argv) {
    
    //Literals were used because of the Chapter contents. (Literals were covered)
    string name = "Random Name";
    string address = "777 GetLucky Ave., Los Angeles, CA, 77777";
    string phoneNum = "777-777-7777";
    string major = "Comp. Science";
    
    
    //display the above, each in a separate line, use only one cout statement
    cout << name << endl << address << endl << phoneNum << endl << major; 
    
    return 0;
}