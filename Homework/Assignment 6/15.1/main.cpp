/** File:   main.cpp
 * Author: Antero Avalos
 *
 * Created on May 30, 2021

 15.1 Employee and ProductionWorker Classes

* Design a class named Employee . The class should keep the following information in
    
    • Employee name
    • Employee number
    • Hire date

Write one or more constructors and the appropriate accessor and mutator functions
for the class.
 
Next, write a class named ProductionWorker that is derived from the Employee class.

The ProductionWorker class should have member variables to hold the following
information:

• Shift (an integer)
• Hourly pay rate (a double )

The workday is divided into two shifts: day and night. The shift variable will hold an
integer value representing the shift that the employee works. The day shift is shift 1, and
the night shift is shift 2. Write one or more constructors and the appropriate accessor
and mutator functions for the class. Demonstrate the classes by writing a program that
uses a ProductionWorker object.
*/

#include <cstdlib>
#include <iostream>

#include "Employee.h"
#include "ProductionWorker.h"

using namespace std;


/*
 * 
 */
int main(int argc, char** argv) {
    
    cout << "Test for ProductionWorker Class: \n\n" << endl;     
    
    
    //Get employee information using methods from both classes
    cout << "  Enter name of employee: "; //Prompt user for name 
    string name; 
    cin >> name;
    //testEmp.setName(name); //set name
    
    cout << "\nEnter their emp. number: "; //Prompt user for employee #
    int num;
    cin >> num;
    //testEmp.setNumber(num);//set number
            
    cout << "\nEnter date of hire(Ex. 01/01/2020):  "; //Prompt for d.o.h
    string date;
    cin >> date;
    //testEmp.setDate(date);//set date
    
    cout << "\nEnter the shift they work(day or night): "; //Prompt for shift
    string shift; 
    cin >> shift;
    //set shift accordingly
    if(shift == "day"){
        testEmp.setShift(1); 
    }else if(shift == "night"){
        testEmp.setShift(2);
    }else{
        cout << "Invalid shift." << endl; 
    }

    cout << "\nEnter the hourly pay rate for " << name << " :";
    double r8; 
    cin >> r8;
    //testEmp.setRate(r8);    
    
    ProductionWorker testEmp(); //Declaring production worker object

    //-------------------------------------------------------------------------
    //Display information stored in ProductionWorker object testEmp 
    string stName = testEmp.getName();
    int stNum = testEmp.getNumber();
    string stDate = testEmp.getDate();
    int stShift =  testEmp.getShift();
    double stHourly = testEmp.getRate();
    
    cout << "The following information was stored for " << name << endl << endl;
    cout << "Name:              " << stName << endl ;
    cout << "Number:            " << stNum << endl ;
    cout << "Date of Hire       " << stDate << endl;
    cout << "Shift:             " << stShift << endl;
    cout << "Hourly Rate:       " << stHourly << endl;
    return 0;
}

