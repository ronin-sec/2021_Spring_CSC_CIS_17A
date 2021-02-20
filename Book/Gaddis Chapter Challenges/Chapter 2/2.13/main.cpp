/* 
 * File:        	main.cpp
 * Author:      	Antero Avalos
 * Date Created:    	02/18/21 5:27 pm
 * Date Finished:       02/18/21 5:40 pm
 * Purpose:     	Pay Period Gross Pay
 */

//System Libraries
#include <iostream>         //I/O Library
#include <iomanip>          //I/O Manipulation
#include <bits/stdc++.h>    //Used for string concatenation

using namespace std;

int main(int argc, char** argv) {
    
    //Literals were used because of the Chapter contents. (Literals were covered)
    int salary = 36000; //Employee annual salary
    int twicePM = 24;   //Number of checks that are payed if employee pay is done twice a month 
    int biWeek = 26;    //Number of checks that are payed if employee pay is bi-weekly
    
    int gPayBW = salary / biWeek;   //Gross pay if biweekly checks are payed
    int gPayTPM = salary / twicePM; //Gross pay if checks are payed twice a month
    
    //Display gross pay per check on both modalities of pay: 
    cout << "Gross pay if employee is payed twice a month is :      $" <<  gPayTPM << endl;
    cout << "Gross pay if employee is payed bi-weekly is :          $" <<  gPayBW << endl;
    
    
    return 0;
}