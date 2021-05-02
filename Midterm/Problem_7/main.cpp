/* 
 * File:   main.cpp
 * Author: Antero
 *
 * Created on 04/28/2021
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <math.h>
using namespace std;

//User Libraries
#include "Primes.h"

//Function Prototypes
Primes *factor(int);            //Input an integer, return all prime factors
void prntPrm(Primes *);         //Output all prime factors

int * getPrimes(int , int &);   //
Primes addExps(int * , int );   //
//-----------------------------MAIN starts here---------------------------------
int main(int argc, char** argv) {

    int number;
    cout << "Enter number: " << endl;
    cin >> number;

    //Declare pointer of primes
    Primes * primeArr = nullptr;

    primeArr = factor(number);

    prntPrm(primeArr);

    return 0;
}
//-----------------------------MAIN ends here-----------------------------------

//Function Definitions

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

    //Counter for number of primes that will remain
    // once exponents are identified.
    int pwExponents = 0; 

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