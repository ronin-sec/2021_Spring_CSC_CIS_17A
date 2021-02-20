/* 
 * File:        	main.cpp
 * Author:      	Antero Avalos
 * Date Created:    	02/18/21 2:17 pm
 * Date Finished:       02/18/21 2:22 pm
 * Purpose:     	Sum of Two Numbers
 * 
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

int main(int argc, char** argv) {
    int num1, num2, total; //To score both numbers 
    
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second umber: ";
    cin >> num2;
    
    total = num1 + num2; 
    cout << "Sum of those numbers is: " << total << endl;
    
    return 0;
}