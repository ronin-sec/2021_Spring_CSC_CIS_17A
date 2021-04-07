/* 
 * File:   Division Struct
 * Author: Antero Avalos
 * Created on : 04/05/2021
 * Purpose:  Store division characteristics in struct, then display them. 
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Struct Declarations
struct Division
{
    string name;
    int firstQ;
    int secondQ;
    int thirdQ;
    int fourthQ;
    float totalSales;
    float avgQtrSales;
    
    
};

//Function Prototypes
void setDivData(Division); 

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    Division N;
    N.name = "North";
    setDivData(N);
    cout << endl;
    
    Division W;
    W.name = "West";
    setDivData(W);
    cout << endl;
    
    Division E;
    E.name = "East";
    setDivData(E);
    cout << endl;
    
    Division S;
    S.name = "South";
    setDivData(S);
    
    //Exit stage right!
    return 0;
}

void setDivData(Division divName)
{
    float first,
        second, 
        third, 
        fourth;
        
    string n = "";
    n = divName.name;
    
    cout << n << endl;
        
    cin >> first >> second >> third >> fourth;
    cout << "Enter first-quarter sales:\n";
    cout << "Enter second-quarter sales:\n";
    cout << "Enter third-quarter sales:\n";
    cout << "Enter fourth-quarter sales:\n";

    divName.firstQ = first;
    divName.secondQ = second;
    divName.thirdQ= third;
    divName.fourthQ = fourth;
    
    float sum =  (divName.firstQ + divName.secondQ + divName.thirdQ + divName.fourthQ);
    
    divName.totalSales = sum;
    
    cout << fixed << setprecision(2);
    
    cout << "Total Annual sales:$" << divName.totalSales << endl;
    
    divName.avgQtrSales = divName.totalSales / 4;
    
    cout << "Average Quarterly Sales:$" << divName.avgQtrSales;
}
