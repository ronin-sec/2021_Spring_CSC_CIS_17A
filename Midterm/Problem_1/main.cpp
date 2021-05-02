/*
1)  Develop an application using structures for a customer
that will determine if he/she has exceeded his/her checking 
account balance. For each customer, the following 
facts are available:

a. Name
b. Address
c. Account number (Five digits only, i.e. test for this)
d. Balance at the beginning of the month 
e. Total of all checks written by this customer this month 
     Loop until customer is through entering checks.
f. Total of all deposits credited to this customer's account this 
     month.  Loop until customer is through entering deposits.

Dynamically create the structure.
The program should input each of these facts from input dialogs,
store in a structure, calculate the new balance, 
display the new balance and debit the account $20 if overdrawn. 
Also, if overdrawn, tell the customer the additional $20 fee 
has been accessed and what the balance would be with this fee included.
Make sure to output the contents of the structure.
*/

/* 
 * File:   main.cpp
 * Author: Antero
 *
 * Created on 04/28/2021
 */
//System Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//User Libraries
#include "Customer.h"

//Function Prototypes
Customer *getCust();        //Creates and returns customer objects
int getAcct();              //Get account number
int chekLen(int);           //Validates user input for account number
float getChks(int);          //Gets account balance
float getDeps(int);         //Gets deposit amount 
void dspCust(Customer*);    //Display contents of a customer object

//---------------------------------------MAIN starts here--------------------------------------
int main(int argc, char** argv) {
    
    Customer *custInf = nullptr;    //Structure pointer
    cout << "Welcome to Problem 1: Press Enter to continue!\n";
    cin.ignore();
    custInf = getCust();    //Gets user input and stores values into structure

    dspCust(custInf);       //displays constents of customer 

    delete custInf;         //deallocate memory
    return 0;
}
//---------------------------------------MAIN ends here--------------------------------------


//---------------------------------------FUNCTION DEFINITIONS--------------------------------

//Creates the structure from given information, utilizes some of the functions below
Customer *getCust(){
    //Create a struct pointer
    Customer *custInf =  new Customer;

    const float odFee = 20.00; //Constant value for overdraw fee
    cout << "Enter the customer information as prompted.\n";
    //Get name of customer
    cout << "Name of the customer: ";
    string nameIn = " ";
    getline(cin, nameIn);
    custInf->name = nameIn;
    //Customer Address
    cout << "Customer Address: ";
    string addrsIn;
    getline(cin, addrsIn);
    custInf->address = addrsIn;
    //Account number
    cout << "Account Number: ";
    custInf->acctNum = getAcct();
    //Starting balance for the month
    cout << "What was the starting balance this month?: ";
    float mBalIn = 0; //monthly balance variable
    cin >> mBalIn;
    custInf->initBal = mBalIn;
    //Total of checks written by customer this month
    cout << "How many checks did you write this month?: ";
    int nChks = 0; //number of checks variable
    cin >> nChks;
    custInf->spent = getChks(nChks);
    //Total of deposits credited to customer's account
    cout << "How many deposits did you get this month?: ";
    int nDeps = 0; //number of deposits variable 
    cin >> nDeps;
    custInf->dposits = getDeps(nDeps);
    //Calculate new balance
    float nuBal = custInf->initBal + custInf->dposits - custInf->spent; //balance variable 
    custInf->newBal = nuBal;

    //Check new balance for overdrawn balance, if account is overdrawn; 20$ charge is applied
    if(custInf->newBal < 0){
        custInf->newBal = nuBal - odFee;
        custInf->odChrge = true;
    }else{
        custInf->odChrge = false;
    }

    return custInf;
}

//Get account number
int getAcct(){
    int len = 0, 
        acctNum = 0;
    
    cin >> acctNum;
    len = chekLen(acctNum);

    if(len == 5){
        return acctNum;
    }else{
        while (len != 5)
        {
            cout << "Account # must be 5 digits, no more, no less!\n"
                 << "Enter account number: ";
            cin >> acctNum;
            len = chekLen(acctNum);
        }
        return acctNum;
    }
}

//Check the length of account number
int chekLen(int acctNum){
    int len = 0;  
    do{
        len++;
        acctNum /= 10;
    }while(acctNum);

    return len;
}

//Get account balance amount 
float getChks(int nChks){
    float chckArr[nChks];
    float sum;
    for (int i = 0; i < nChks; i++)
    {
        cout << "Enter amount of check #" << i+1 <<" :";
        cin >> chckArr[i]; 
        sum += chckArr[i];
    }
    return sum;   
}

float getDeps(int nDeps){
    float depsArr[nDeps];
    float sum;
    for (int i = 0; i < nDeps; i++)
    {
        cout << "\nEnter amount of deposit #" << i+1 <<" :";
        cin >> depsArr[i]; 
        sum += depsArr[i];
    }
    return sum;
}

void dspCust(Customer *customr){
    cout << "\n\n";
    cout << "Customer Name:            " << customr->name << endl
         << "Customer Address:         " << customr->address << endl
         << "Account Number:           " << customr->acctNum << endl
         << fixed << setprecision(2)
         << "Month starting balance:  $" << customr->initBal << endl
         << "Amount spent from checks:$" << customr->spent << endl
         << "Amount deposited:        $" << customr->dposits << endl
         << "Updated account balance: $" << customr->newBal << endl;

    if(customr->odChrge == true){
        cout << "Your account balance reflects a $20.00 charge for an "
             << "overdraw fee. Contact us if you think this was a mistake." << endl;
    }

    return;
}

