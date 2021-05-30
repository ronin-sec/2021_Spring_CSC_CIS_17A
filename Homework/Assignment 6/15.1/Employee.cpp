//Implementation of the employee class, contains the definition of all
//class functions/methods.

#include "Employee.h"
using namespace std; 


//**************************************************************
// Constructors for the Employee class.                        *
//**************************************************************
//Default Constructor
Employee::Employee(){
    name = "";
    number = 12345;
    date = "01/01/2000";
}    

//Parameterized Constructor
Employee::Employee(string n, int num, string dat){
    n = name; 
    num = number;
    dat = date;
}


//****************************************************************
// Mutator functions for member variables of the Employee class  *
//****************************************************************
void Employee::setName(string n){
    n = name; 
}

void Employee::setNumber(int num){
    num = number;
}

void Employee::setDate(string dat){
    dat  = date; 
}

//****************************************************************
// Accessor functions for member variables of the Employee class *
//****************************************************************
string Employee::getName() const{
    return name;
}

int Employee::getNumber() const{
    return number;
}

string Employee::getDate() const{
    return date;
}