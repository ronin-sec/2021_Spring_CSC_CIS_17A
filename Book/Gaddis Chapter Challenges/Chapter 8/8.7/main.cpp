/* 
 * File:        	main.cpp
 * Author:      	Antero Avalos
 * Date Created:    	02/28/2021 07:00 pm
 * Date Finished:     02/28/2021 10:13 pm
 * Purpose:     	Lottery
 *                      
 */

//System Libraries
#include <iostream>  //I/O Library
#include <cstdlib>   //For random seed
using namespace std;

//Prototypes
void cmpNums(int[], int[], int); //Compares corresponding ints in winningDigits and player arrays 


int main(){
    
    //Set random number seed
    srand(static_cast<unsigned int>(time(0)));

    //Variable declarations
    const int ARRSZ = 5;      //Constant variable for array size
    int winningDigits[ARRSZ]; //winning digits array, contains 5 random ints 
    int player[ARRSZ];        //user given int array

    //Get 5 ints from user and assign them to "player" array
    int userIn;
    cout << "Enter your lottery numbers as prompted. \n";
    for(int i = 0; i < ARRSZ; i++){
      cout << "Lottery number #" << (i+1) << ": ";
      cin >> userIn;
      player[i] = userIn;
      cout << endl;
    }

    //Assign random int values to the "winningDigits" array;
    int rando;
    for(int i = 0; i < ARRSZ; i++){
      rando =  (rand() % (9 - 0 + 1)) + 0; 
      winningDigits[i] = rando;
    }

    //Display the contents of winning digits array:
    cout << "\nWinning numbers were: \n";
    for(int i = 0; i < ARRSZ; i++){
      cout << winningDigits[i] << " ";
    }

    //Display the contents of player digits array:
    cout << "\nYour numbers were: \n";
    for(int i = 0; i < ARRSZ; i++){
      cout << player[i] << " ";
    }

    //Compare corresponding numbers in both arrays and display number of matches. 
    cmpNums(winningDigits, player, ARRSZ);
    return 0;
}

//Function Definitions 

void cmpNums(int winDig[], int player[], int arrSz){
  short matches = 0;                //To count number of matching numbers
  for(int i = 0; i < arrSz; i++){
    if(winDig[i] == player[i]){     //Compare corresponding array elements 
      matches++;     //increase match count if needed 
    }
  }
  //Display results
  if(matches == 0){ //If no matches...
    cout << "\nYou had no winning numbers. Better luck next time!\n";
  }else{            //If matches ocurred, display how many digits matched.
    //If statement can be added to display singular for "numbers" when matches == 1.
    cout << "\nCongratulations, you had " << matches << " winning numbers!!\n";
  }
}