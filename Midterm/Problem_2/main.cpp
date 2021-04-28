/*
2)  Develop an application using an array of structures that will 
determine the gross pay for any number of employees input. The company pays 
"straight-time" for the first 40 hours worked, double time for 
all hours worked in excess of 40 hours but less than 50 hours, 
and triple time for any hours worked over 50 hours.

The program should be able to loop and input the employee's name, 
hours worked, and the rate of pay.  Once this has been done then output
this information including the gross pay in the form of a paycheck.
The process starts all over 
again until you input an invalid rate of pay or hours worked.  This
means a negative rate of pay or negative number of hours worked is
not acceptable.

Print it out like an actual paycheck with English
language representing the check amount.
Printout like a company Paycheck with format:
     Company
     Address
     Name:	Amount: numerical
     Amount:    English of numerical value
     Signature Line:
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
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

//User Libraries
#include "Employee.h"

//Function Prototypes
int numEmpl();                      //Gets number of employees for payroll 
Employee * payRoll(int);            //Fill struct array with payroll data
void mkCheck(Employee [], int);     //
string engVal(float );              //
int chekLen(float );                //
float getHrs();                     //
float calcPay(float, float);        //
float getRate();                    //
//--------------------------MAIN starts here--------------------
int main(int argc, char** argv) {
    //Get number of employees
    int size = numEmpl();
    
    //Structure pointer do allocate array
    Employee * payroll;
    
    //This function creates an array and generates the checks,
    // functions inside validate input for negative values and 
    // adequate houras and payrate values. 
    payroll = payRoll(size);

    //unallocate memory that was used for payroll 
    delete payroll;

    return 0;
}
//--------------------------MAIN ends here---------------------



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
    cout << "\n-------------------------------------------------------------------------\n";
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
    //If the number is above ten thousand-------------------------------------------------------
    if(numLen >= 5){
        wdAmnt = "Amount is too high, please contact HR for more info!";}
    //If the number is below 9999.99------------------------------------------------------------
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
    //If the number is below 999.99------------------------------------------------------------------
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
    //If the number is beklow 99.99----------------------------------------------------------------
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
    //If the number is below 9.99--------------------------------------------------------------
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