/* 
 * File:        	main.cpp
 * Author:              Antero Avalos
 * Date Created:        02/17/21 12:02 PM
 * Date Finished:       02/17/21 12:07 PM
 * Purpose:     	Calculates a little league team's expense on balls
 * 
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;


int main(int argc, char** argv) {
   // Variables
   double balls, bCost, totalExp;
   
   //Get number of balls purchased
   cout << "How many balls were purchased?";
   cin >> balls;
    
   //Get cost per ball
   cout << "Cost per bar?"; 
   cin >> bCost; 
   
   //Calculate total cost
   totalExp = balls * bCost;
   
   //Display result
   cout << "Total amount spent on balls was: $" << totalExp << endl;
   
   return 0;
}