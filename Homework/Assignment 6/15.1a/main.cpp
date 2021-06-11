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


#include "ProductionWorker.h"

using namespace std;


/*
 * 
 */
int main(int argc, char** argv) {
    
    ProductionWorker testEmp("Antero", 12345, "02/25/2077", 1, 21.65);
    
    cout << "The following information was stored for " << testEmp.GetName() << endl << endl;
    cout << "Name:              " << testEmp.GetName() << endl ;
    cout << "Number:            " << testEmp.GetNumber() << endl ;
    cout << "Date of Hire       " << testEmp.GetDate() << endl;
    cout << "Shift:             " << testEmp.GetShift() << endl;
    cout << "Hourly Rate:       " << testEmp.GetRate() << endl;
    return 0;
}

