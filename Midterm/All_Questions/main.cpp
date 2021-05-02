
/* 
 * File:   main.cpp
 * Author: Antero Avalos
 *
 * Created on 04/28/2021
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cmath>
using namespace std;

//User Libraries
#include "Customer.h"  //For Problem #1

#include "Employee.h"  //For Problem #2

#include "Primes.h"    //For Problem #6


//Function Prototypes for Problem #1 : Customer Bank Account
Customer *getCust();        //Creates and returns customer objects
int getAcct();              //Get account number
int chekLen(int);           //Validates user input for account number
float getChks(int);          //Gets the starting balance for the month
float getDeps(int);         //Gets the deposits for the month
void dspCust(Customer*);    //Display contents of a customer object
void problm1();             //Run problem 1


//Function Prototypes for Problem #2: Payroll/Check Application
int numEmpl();                      //Gets number of employees for payroll 
Employee * payRoll(int);            //Fill struct array with payroll data
void mkCheck(Employee [], int);     //Prints the check
string engVal(float );              //Creates a string that is used for the written dollar amount
int chekLen(float );                //Checks length of the gross pay, used by engVal
float getHrs();                     //gets hours and validates input 
float calcPay(float, float);        //calculates gross pay
float getRate();                    //gets the pay rate 
void problm2();                     //Run problem 2


//Function Prototypes for Problem #3: Stub mediam/mode/avg function problem
void problm3();            //Run problem 3

//Function Prototypes for Problem #4: Encrypt and Decrypt
void getNum(int &);         //Get 4 integer number from user
int * encrypt(int );        //Encrypts 4 integer number
int * decrypt(int );        //Decrypts 4 integer number 
void dispArr(int *);        //Display contents of array of pointers
void problm4();             //Run problem 4

//Function Prototypes for Problem #5: Finding the largest n factorial 
void problm5();             //Run problem 5

//Function Prototypes for Problem #6: Number Conversion
void problm6();             //Run problem 6

//Function Prototypes for Problem #7: Integer Prime Factoring
Primes *factor(int);            //Input an integer, return all prime factors
void prntPrm(Primes *);         //Output all prime factors
int * getPrimes(int , int &);   //
Primes addExps(int * , int );   //
void problm7();                 //Runs problem 7

int main(int argc, char** argv) {

    cout << " MIDTERM \n Antero Avalos \n CIS-17A-49287. " << endl;
    

    
    bool exit = false;
    int problem;

    do
    {
        cout << "\n\nSelect the problem you want to run: " << endl;
        cout << "1. Problem 1.\n"
             << "2. Problem 2.\n"
             << "3. Problem 3.\n"
             << "4. Problem 4.\n"
             << "5. Problem 5.\n"
             << "6. Problem 6.\n"
             << "7. Problem 7.\n"
             << "0. Exit.\n\n";

        cin >> problem;

        switch (problem)
        {
        case 1:
            problm1();
            break;

        case 2:
            problm2();
            break;

        case 3:
            problm3();
            break;

        case 4:
            problm4();
            break;

        case 5:
            problm5();
            break;

        case 6:
            
            problm6();
            break;

        case 7:
            
            problm7();
            break;
            
        case 0:

            exit = true;
        
        default:
            cout << "PLease chooose a problem from the list (1 - 7).\n";
            break;
        }


    } while (exit != true);
    
    cout << "Goodbye!" << endl;
    return 0;
}

//Function Definitions

//---------------------------PROBLEM 1 DEFINITIONS----------------------------------------
Customer *getCust(){
    //Create a struct pointer
    Customer *custInf =  new Customer;
    cin.ignore();
    const float odFee = 20.00; //Constant value for overdraw fee
    cout << "Enter the customer information as prompted.\n\n";
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
    int nChks = 0;
    cin >> nChks;
    custInf->spent = (nChks);
    //Total of deposits credited to customer's account
    cout << "How many deposits did you get this month?: ";
    int nDeps = 0;
    cin >> nDeps;
    custInf->dposits = getDeps(nDeps);
    //Calculate new balance
    float nuBal = custInf->initBal + custInf->dposits - custInf->spent;
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

//Get acount number, 
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

int chekLen(int acctNum){
    int len = 0;  
    do{
        len++;
        acctNum /= 10;
    }while(acctNum);

    return len;
}

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

void problm1(){

    Customer *custInf = nullptr;    //Structure pointer
            cout << "Welcome to Problem 1!\n";
        
            custInf = getCust();    //Gets user input and stores values into structure

            dspCust(custInf);       //displays contents of customer 

            delete custInf;         //deallocate memory

    return;

}

//---------------------------PROBLEM 2 DEFINITIONS----------------------------------------

int numEmpl(){
    int nWrkrs;
    
    cout << "Enter the number of employees you need checks for: ";
    cin >> nWrkrs;

    return nWrkrs;
}


Employee * payRoll(int arySize){
    Employee * payroll = new Employee[arySize];

    for (int i = 0; i < arySize; i++)
    {
        cin.ignore();
        cout << "Enter employee's name: ";
        getline(cin, payroll[i].name);
        payroll[i].workHrs = getHrs();
        payroll[i].payRate = getRate();
        float rate = payroll[i].payRate;
        float hours =  payroll[i].workHrs;
        payroll[i].grssPay = calcPay(rate, hours);

        mkCheck(payroll, i);
    }
    
    return payroll;
}

void mkCheck(Employee payroll[], int i){
    float gross = payroll[i].grssPay;

    string enValue = engVal(gross);
    cout << "-------------------------------------------------------------------------\n";
    cout << "Company One Co.\n"
         << "4800 Magnolia Ave, Riverside, CA 92506\n"
         << "Name:" << payroll[i].name << "     " << "Amount: $" << payroll[i].grssPay << "\n\n";

    cout << "Amount: "<< enValue;
    cout <<"\n\nSignature: ________________________________________________________\n";
    cout << "\n-------------------------------------------------------------------------\n\n\n";
}

//Generates the string to be used as "written dollar amount" on check.
string engVal(float grssPay){
    string wdAmnt = " "; //String, "written dollar amount".

    int numLen = chekLen(grssPay);
    
    float cents, dimes, singles, tens, hundrds, thsnds, tThsnds;
    
    tThsnds = fmod((grssPay / 10000),10);
    thsnds  = fmod((grssPay / 1000),10);
    hundrds = fmod((grssPay / 100),10);
    tens    = fmod((grssPay / 10),10);
    singles = fmod((grssPay / 1),10);
    dimes   = fmod((grssPay / .1),10);
    cents   = fmod((grssPay / .01),10);

    const int valSz = 10;
    string valArr[valSz] = {" ", "One ", "Two ", "Three ", "Four ", "Five ", "Six ", "Seven ", "Eight ", "Nine "};
    string decArr[valSz] = {"Cents ", "Dollars ", "Hundred ", "Thousand "};
    string tnsArr[valSz] = {" ", "teen", "Twenty-", "Thirty-", "Forty-", 
                            "Fifty-", "Sixty-", "Seventy-", "Eighty-", "Ninety-"};

    int thIndx = thsnds,
        hIndx = hundrds,
        tIndx = tens,
        sIndx = singles,
        dIndx = dimes,
        cIndx = round(cents);
            
    string * arr = nullptr;

    arr = new string[numLen]; 
    //If the number is above ten thousand-------------
    if(numLen >= 5){
        wdAmnt = "Amount is too high, please contact HR for more info!";}
    //If the number is below 9999.99------------------
    if(numLen == 4){        
        //Write the thousands
        arr[0] = valArr[thIndx] + decArr[3];
        //Write the hundreds
        if(hIndx == 0){
            arr[1] = " " + tnsArr[tIndx] + valArr[sIndx];
        }
        if(hIndx > 0){
            arr[1] = valArr[hIndx] + decArr[2];
        }
        //Write the tens
        if(tIndx == 0){
            arr[2] = " " + valArr[sIndx] + " dollars "; 
        }
        if(tIndx > 1){
            arr[2] = tnsArr[tIndx] + valArr[sIndx] + " dollars "; 
        }
        if(tIndx == 1){ //Evaluates for values 10-19
            if(sIndx == 0){
                arr[2] = " ten dollars ";  
            }
            if(sIndx == 1){
                arr[2] = " eleven dollars ";  
            }
            if(sIndx == 2){
                arr[2] = " twelve dollars ";  
            }
            if(sIndx == 3){
                arr[2] = " thirteen dollars ";  
            }
            if(sIndx > 3){
                arr[2] = " " + valArr[sIndx] + tnsArr[1] + " dollars ";
            }
        }
        //If there is no cent amount... just stop
        if(dIndx == 0 && cIndx == 0){
            arr[3] = ".";
        }
        else{
            //Write the cents
            if(dIndx == 0){
                arr[3] = "& " + valArr[cIndx] + " cents"; 
            }
            if(dIndx > 0){
                arr[3] = "& " + tnsArr[dIndx] + valArr[cIndx] + " cents"; 
            }
            if(dIndx == 1){ //Evaluates for values 10-19
                if(cIndx == 0){
                    arr[3] = "& ten cents";  
                }
                if(cIndx == 1){
                    arr[3] = "& eleven cents";  
                }
                if(cIndx == 2){
                    arr[3] = "& twelve cents";  
                }
                if(cIndx == 3){
                    arr[3] = "& thirteen cents";  
                }
                if(cIndx > 3){
                    arr[3] = "& " + valArr[cIndx] + tnsArr[1] + " cents.";
                }
            }
        }
        wdAmnt = arr[0]+ arr[1] + arr[2] + arr[3];
    }
    //If the number is below 999.99-------------------
    if(numLen == 3){
        //Write the hundreds
        if(hIndx == 0){
            arr[0] = " " + tnsArr[tIndx] + valArr[sIndx];
        }
        if(hIndx > 0){
            arr[0] = valArr[hIndx] + decArr[2];
        }
        //Write the tens
        if(tIndx == 0){
            arr[1] = " " + valArr[sIndx] + " dollars "; 
        }
        if(tIndx > 1){
            arr[1] = tnsArr[tIndx] + valArr[sIndx] + " dollars "; 
        }
        if(tIndx == 1){ //Evaluates for values 10-19
            if(sIndx == 0){
                arr[1] = " ten dollars ";  
            }
            if(sIndx == 1){
                arr[1] = " eleven dollars ";  
            }
            if(sIndx == 2){
                arr[1] = " twelve dollars ";  
            }
            if(sIndx == 3){
                arr[1] = " thirteen dollars ";  
            }
            if(sIndx > 3){
                arr[1] = " " + valArr[sIndx] + tnsArr[1] + " dollars ";
            }
        }
        //If there is no cent amount... just stop
        if(dIndx == 0 && cIndx == 0){
            arr[2] = ".";
        }
        else{
            //Write the cents
            if(dIndx == 0){
                arr[2] = "& " + valArr[cIndx] + " cents"; 
            }
            if(dIndx > 0){
                arr[2] = "& " + tnsArr[dIndx] + valArr[cIndx] + " cents"; 
            }
            if(dIndx == 1){ //Evaluates for values 10-19
                if(cIndx == 0){
                    arr[2] = "& ten cents";  
                }
                if(cIndx == 1){
                    arr[2] = "& eleven cents";  
                }
                if(cIndx == 2){
                    arr[2] = "& twelve cents";  
                }
                if(cIndx == 3){
                    arr[2] = "& thirteen cents";  
                }
                if(cIndx > 3){
                    arr[2] = "& " + valArr[cIndx] + tnsArr[1] + " cents.";
                }
            }
        }
        wdAmnt = arr[0]+ arr[1] + arr[2];
    }
    //If the number is below 99.99----------------------
    if(numLen == 2){
        //Write the tens
        if(tIndx > 1){
            arr[0] = tnsArr[tIndx] + valArr[sIndx] + " dollars "; 
        }
        if(tIndx == 1){ //Evaluates for values 10-19
            if(sIndx == 0){
                arr[0] = " ten dollars ";  
            }
            if(sIndx == 1){
                arr[0] = " eleven dollars ";  
            }
            if(sIndx == 2){
                arr[0] = " twelve dollars ";  
            }
            if(sIndx == 3){
                arr[0] = " thirteen dollars ";  
            }
            if(sIndx > 3){
                arr[0] = " " + valArr[sIndx] + tnsArr[1] + " dollars ";
            }
        }
        //If there is no cent amount... just stop
        if(dIndx == 0 && cIndx == 0){
            arr[1] = ".";
        }
        else{
            //Write the cents
            if(dIndx == 0){
                arr[1] = "& " + valArr[cIndx] + " cents"; 
            }
            if(dIndx > 0){
                arr[1] = "& " + tnsArr[dIndx] + valArr[cIndx] + " cents"; 
            }
            if(dIndx == 1){ //Evaluates for values 10-19
                if(cIndx == 0){
                    arr[1] = "& ten cents";  
                }
                if(cIndx == 1){
                    arr[1] = "& eleven cents";  
                }
                if(cIndx == 2){
                    arr[1] = "& twelve cents";  
                }
                if(cIndx == 3){
                    arr[1] = "& thirteen cents";  
                }
                if(cIndx > 3){
                    arr[1] = "& " + valArr[cIndx] + tnsArr[1] + " cents.";
                }
            }
        }
        wdAmnt = arr[0]+ arr[1];
    }
    //If the number is below 9.99-------------------------
    if(numLen == 1){
        //Write the singles
        arr[0] = valArr[sIndx] + " dollars ";
        
         //If there is no cent amount... just stop
        if(dIndx == 0 && cIndx == 0){
            arr[1] = ".";
        }
        else{
            //Write the cents
            if(dIndx == 0){
                arr[1] = "& " + valArr[cIndx] + " cents"; 
            }
            if(dIndx > 0){
                arr[1] = "& " + tnsArr[dIndx] + valArr[cIndx+1] + " cents"; 
            }
            if(dIndx == 1){ //Evaluates for values 10-19
                if(cIndx == 0){
                    arr[1] = "& ten cents";  
                }
                if(cIndx == 1){
                    arr[1] = "& eleven cents";  
                }
                if(cIndx == 2){
                    arr[1] = "& twelve cents";  
                }
                if(cIndx == 3){
                    arr[1] = "& thirteen cents";  
                }
                if(cIndx > 3){
                    arr[1] = "& " + valArr[cIndx] + tnsArr[1] + " cents.";
                }
            }
        }
        wdAmnt = arr[0] + arr[1];
    }
    

    return wdAmnt;
}

//Evaluates the length of the grosspay amount:
//Length is only evaluated to know how many thousands there are, if any
int chekLen(float acctNum){
    
    int toInt = acctNum;
    int len = 0;  
    do{
        len++;
        toInt /= 10;
    }while(toInt);

    return len;
}

float getHrs(){
    float hours;
    bool okHrs = false;

    while(okHrs != true){
        cout << "Hours worked: ";
        cin >> hours;
        if(hours <= 0){
            cout << "Amount of hours needs to be greater than zero!\n";
            okHrs = false;
        }
        else if(hours > 112){
            cout << "112 is the maximum amount of hours allowed! Try again.\n";
        }  
        else{
            okHrs = true;
        }
    }
    return hours;
}

float calcPay(float payrate, float hours){
    float pay;

    if(hours > 0 && hours <= 40){
        pay = hours * payrate;
    }
    if(hours > 40 && hours <= 50){
        pay = hours * (payrate*2);
    }
    if(hours > 50){
        pay = hours * (payrate*3);
    }

    return pay;
}

float getRate(){
    float rate;
    bool okRate = false;

    while(okRate != true){
        cout << "Employee's pay rate: ";
        cin >> rate;
        if(rate < 13.00){
            cout << "The minimum wage in Riverside California is $13.00/hour. Try again!\n";
            okRate = false;
        }else{
            okRate = true;
        }
    }    
    return rate;
}

void problm2(){
    cout << "This problem has a bug that causes the program to \n"
            "terminate after all the checks have been printed. \n\n";

    //Get number of employees
    int size = numEmpl();
    
    //Structure pointer do allocate array
    Employee * payroll;
    
    //This function creates an array and generates the checks,
    // functions inside validate input for negative values and 
    // adequate hours / payrate. 
    payroll = payRoll(size);

    //unallocate memory that was used for payroll 
    delete payroll;

    return;
}

//---------------------------PROBLEM 3 DEFINITIONS----------------------------------------
void problm3(){
    cout << "Problem 3 is Located in the 'Problem 3' Project.";

    return;
}

//---------------------------PROBLEM 4 DEFINITIONS----------------------------------------
//Gets input from user
void getNum(int &data){
    cout << "Enter the 4 digit integer: " << endl;

    int input;
    
    cin >> input;

    
    
    bool okInput = false;
    while(okInput != true){
        int temp1 = (input / 1000) % 10,
            temp2 = (input / 100) % 10,
            temp3 = (input / 10) % 10,
            temp4 = (input / 1) % 10;

        if(temp1 >= 8){
            cout << "Please use allowed integers (0,1,2,3,4,5,6,7)!!\n";
            cin >> input;
        }else if(temp2 >= 8){
            cout << "Please use allowed integers (0,1,2,3,4,5,6,7)!!\n";
            cin >> input;
        }else if(temp3 >= 8){
            cout << "Please use allowed integers (0,1,2,3,4,5,6,7)!!\n";
            cin >> input;
        }else if(temp4 >= 8){
            cout << "Please use allowed integers (0,1,2,3,4,5,6,7)!!\n";
            cin >> input;
        }else{
            data = input;
            okInput = true;
        }
    }       
}

//Encrypts integer provided by user
int * encrypt(int data){

    int * ncryptd = nullptr;
    
    //ENCRYPT-------------------------------------------------------------------
    //Split the given number into 4 ints
    int temp1 = (data / 1000) % 10,
        temp2 = (data / 100) % 10,
        temp3 = (data / 10) % 10,
        temp4 = (data / 1) % 10;
    //testing
    //cout << "Values from array stored in temp variables before encryption: \n";
    //cout << temp1 << " " << temp2 << " " <<  temp3 << " " <<  temp4 << endl;

    //(int + 5) % 8;
    temp1 = (temp1 + 5) % 8;
    temp2 = (temp2 + 5) % 8;
    temp3 = (temp3 + 5) % 8;
    temp4 = (temp4 + 5) % 8;
    
    //testing
    //cout << "Values from array stored in temp variables after encryption: \n";
    //cout << temp1 << " " << temp2 << " " <<  temp3 << " " <<  temp4 << endl;

    //swap 1st with 3rd, 2nd with 3rd
    ncryptd = new int[4];        

    ncryptd[0] = temp3;
    ncryptd[1] = temp4;
    ncryptd[2] = temp1;
    ncryptd[3] = temp2;

    //Sum all the numbers to create the new integer
    return ncryptd;
}

//Display contents of pointer array of ints
void dispArr(int * number){
    
    for (int i = 0; i < 4; i++)
    {
        cout << number[i];
    }
}

//Decrypts integer provided by user
int * decrypt(int data){

    int * dcryptd = nullptr;

    //Split the given number into 4 ints
    int temp1 = (data / 1000) % 10,
        temp2 = (data / 100) % 10,
        temp3 = (data / 10) % 10,
        temp4 = (data / 1) % 10;
    
    //testing
    //cout << "Values after the split: \n";
    //cout << temp1 << " " << temp2 << " " <<  temp3 << " " <<  temp4 << endl;

    //Restore the number to their orignal values
    temp1 = (temp1 + 8) - 5;
    temp2 = (temp2 + 8) - 5;
    temp3 = (temp3 + 8) - 5;
    temp4 = (temp4 + 8) - 5;

    //Swap the ints to original positions 
    dcryptd = new int[4];
    
    dcryptd[0] = temp3;
    dcryptd[1] = temp4;
    dcryptd[2] = temp1;
    dcryptd[3] = temp2;

    //this loop ensure that the values are not above 7... 
    for (int i = 0; i < 4; i++)
    {
        if(dcryptd[i] > 7){
            dcryptd[i] -= 8;
        }
    }

    return dcryptd;
}

void problm4(){
    cout << "Press Enter to Begin" << endl;
    int data = 0;

    int * ncryptd = nullptr;
    int * dcryptd = nullptr;

    cin.ignore();
    //Menu
    bool exit = false;
    
    do
    {
        cout << "\n\nWhat would you like to do?:\n"
             << "1.Encrypt.\n"
             << "2.Decrypt.\n"
             << "0.Exit.\n";

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout <<  "ENCRYPTER: \n\n";
            getNum(data);
            ncryptd = encrypt(data);
            cout << "Encrypted number: ";
            dispArr(ncryptd);

            break;
            
        case 2:
            cout <<  "DECRYPTER: \n\n";
            getNum(data);
            dcryptd = decrypt(data);
            cout << "Decrypted number: ";
            dispArr(dcryptd);
            break;

        case 0:
            exit = true;
            break;
        
        default:
            cout << "Choose a valid option! Try Again!\n";
            break;
        }

        
    } while (exit != true);
    
    cout << "Goodbye!" << endl;

    return;
}

//---------------------------PROBLEM 5 DEFINITIONS----------------------------------------

void problm5(){
    cout << "Welcome to Problem #5: ";

    cout << "The following are the largest n! that can be calculated per type: \n" << endl;
    
    cout << "char:              5, overflows at 6" << endl;
    cout << "unsigned char:     5, overflows at 6" << endl;
    cout << "short:             7, overflows at 8" << endl;
    cout << "unsigned short:    8, overflows at 9" << endl;
    cout << "int:               12, overflows at 13" << endl;
    cout << "unsigned int:      12, overflows at 13" << endl;
    cout << "float:             34, overflows at 35" << endl;
    cout << "double:            170, overflows at 171" << endl;
    
    
    
    
    
    
    return;
}

//---------------------------PROBLEM 6 DEFINITIONS----------------------------------------

void problm6(){

    cout << "Problem #6: Number Conversion Results.\n\n"
    
         << "(A)\n"
         << "a.1) Convert 2.875 base 10 to base 2, 8, 16: \n\n"

         << "\t Base2:  10.111 \n"
         << "\t Base8:  2.7 \n"
         << "\t Base16: 2.E \n\n"

         << "a.2) Convert 0.1796875 base 10 to base 2, 8, 16: \n\n"

         << "\t Base2:  0.00101110 \n"
         << "\t Base8:  0.134 \n"
         << "\t Base16: 0.2E \n\n"

         << "(B)\n"
         << "b.1) Convert -2.875 to NASA FORMAT 8 digit Hex\n\n"
         << "                   \n"
         << "                   \n"

         << "b.2) Convert -0.1796875 to NASA FORMAT 8 digit Hex\n\n"
         << "                   \n"
         << "                   \n"
         
         << "(C)\n"
         << "c.1) Convert 59999901 from 8 digit NASA format hex to decimal: \n\n"
         
         << "\t Decimal: 1.399999857 \n\n"

         << "c.2) Convert 59999902 from 8 digit NASA format hex to decimal: \n\n"

         << "\t Decimal: 2.799999714 \n\n"

         << "c.3) Convert 59999902 from 8 digit NASA format hex to decimal: \n\n"

         << "\t Decimal: -5.200000286 \n\n" ;

    return;
}

//---------------------------PROBLEM 7 DEFINITIONS----------------------------------------
Primes * factor(int number){    

    int nPrimes = 0;

    //Create array of ints that contains the primes of the number, no exponents 
    int * pArrNoExp = getPrimes(number, nPrimes);
    
    //Create array of Primes with the integer array 
    Primes arrWExp = addExps(pArrNoExp, nPrimes);

    Primes * result = &arrWExp;
    
    //return array of primes
    return result;
}   

void prntPrm(Primes *pArr){
    
    for (int i = 0; i < pArr->nPrimes ; i++)
    {
        cout << pArr->prime->prime << "^" << pArr->prime->power;
    }
    
    cout << "  x " ;
}        


int * getPrimes(int number, int &nPrimes){

    //declare int pointer for array of primes without exponents 
    int * primArr = new int[80];
    
    int i = 0;
    

    while (number % 2 == 0) 
    { 
        primArr[i] = 2; 
        number = number / 2; 
        i++;
    } 
  
    for (int j = 3; j <= sqrt(number); j = j + 2) 
    { 
        while (number % j == 0) 
        { 
            primArr[i] = j; 
            number = number / j;
            i++;
        } 
    } 
 
    if (number > 2){
        primArr[i] = number; 
    }
    
    int primCnt = i + 1;
    int * newArr = new int[primCnt];

    for(int i = 0; i < primCnt; i++){
        primArr[i] = newArr[i];
    }

    nPrimes = primCnt;
    return newArr;
}

Primes addExps(int * number, int nPrimes){

    Primes primes ;


    primes.nPrimes = nPrimes;

    Prime * pArray = new Prime[nPrimes];

    primes.prime = pArray;


    //Process contents of int array and send them with added exponents to Prime array 
    int currVal = number[0];
    int cvExp = 0; //Identifies the exponent of the current value

    
    for (int i = 0; i < nPrimes; i++)
    {
        for(int j = 0; j < nPrimes; j++){
            if(currVal == number[j+1]){
                cvExp++;
            }
            else{
                currVal = number[j];
            }
        }
        primes.prime->prime = currVal;
        primes.prime->power = cvExp;
    }
    
    delete pArray;

    return primes;    
}

void problm7(){
    cout << "Welcome to Problem #7: \n";
    cout << "This problem is incomplete, I was only able to create a function\n"
            " that returned the primes of a number without the exponents, \n"
            " then I tried developing a way to turn that into the desired output.\n"
            " I was unable to find the solution with the amount of time I had set aside for the problem...\n"
            " One more day focusing on this would've worked in my opinion...\n"
            " Will be revisiting during break to complete this in case it comes in handy... sorry!\n";


    int number;
    cout << "Enter number: " << endl;
    cin >> number;

    //Declare pointer of primes
    Primes * primeArr = nullptr;

    //Save the prime nums in pointer
    primeArr = factor(number);

    //Print array;
    prntPrm(primeArr);

    return;
}