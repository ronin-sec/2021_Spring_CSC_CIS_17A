/* 
 * File:        	main.cpp
 * Author:      	Antero Avalos
 * Date Created:    	02/23/2021 9:52 am
 * Date Finished:       02/23/2021 
 * Purpose:     	Gratuity Calculator
 *                      
 */

//System Libraries
#include <iostream>  //I/O Library
#include <iomanip>   //I/O Manipulation

using namespace std;

//Tips class declaration
class Tips
{
    private:
        float taxRate;  //Single member variable
    
    public:
        Tips(float rate);       //overloaded constructor with one parameter   
        Tips();                 //default constructor, no parameters
        float computeTip(float tipRate, float billAmnt);     //used for tip calculation
};
    

int main(){
   
    //Sentinel controlled loop
    bool done = false;      //Sentinel variable, allows program to exit user is done
    short choice;           //Used for switch 
    float tipRate, billAmnt;//Tip rate and bill amount, both come from user input.
    char taxQues;           //Stores user selection when asked for custom tax option
    float cusTax;           //custom tax value used  if user needs a custom tax amount
    
    float result;           //Resulting tip
    
    Tips tip;     
    
    do{
        cout << "Gratuity Calculator: \n\n"
                << "\t 1.Calculate Tip\n"
                << "\t 2.Exit\n\n"
                << "Please make a selection (1 or 2.)\n";
        cin >> choice;
        

        if (choice >= 0 && choice <= 2){
            switch(choice){
                //Tip calculation case
                case 1:
                    //Get bill amount from user
                    cout << "Please enter the bill amount: " << endl;
                    cin >> billAmnt;
                    //Ask if they would like to specify the tax rate used
                    cout << "Would you like to specify a tax rate? (Y/N)\n"
                         << "(If not specified, default tax of 8.5% will be used):   ";
                    cin >> taxQues;
                    //Depending on the answer to the previous question, tip is calculated
                    if(tolower(taxQues) == 'y'){
                        cout << "Enter the tax rate you'd like to use in calculation:  "; 
                        cin >> cusTax;
                        
                        //Get tip rate from user
                        cout << "\nNow enter the percentage you'd like to tip:  ";
                        cin >> tipRate;
                        
                        //Calculate tip amount with custom tax
                        
                        result = tip.computeTip(tipRate, billAmnt);
                        cout << "\nTip amount for a bill of $" << billAmnt << "dollars is: "
                                << "$" << result <<" dollars.\n\n";
                         
                    }else if(tolower(taxQues) == 'n'){
                        //Get tip rate from user
                        cout << "\n Default tax rate will be used.";
                        cout << "\nNow enter the percentage you'd like to tip:  ";
                        cin >> tipRate;
                                            
                        //Calculate tip amount with default tax
                                      
                        result = tip.computeTip(tipRate, billAmnt);
                        cout << "\nTip amount for a bill of $" << billAmnt << "dollars is: "
                                << "$" << result <<" dollars.\n\n";
                        
                    }else{
                        cout << "Please enter yes(y) or no(n)...\n\n";
                    }
                    break;
                case 2:
                    done = true;
                    break;
                default:
                    cout << "Error in switch logic. See code." << endl;
                    break;
            }
        }else{
            cout << "Please make a valid selection (1 or 2)." << endl; 
        };
        
    }while(done != true);
    return 0;
}

//Function Definitions

//Definition of constructor used when a value for taxRate is provided
Tips::Tips(float rate){
    taxRate = rate; 
}

//Definition of default constructor which is used when no taxRate value is set
Tips::Tips(){
    taxRate = 0.084;
}



//Compute tip from bill and tax rate
float Tips::computeTip(float tipRate, float billAmnt){
    float tip;      //Holds resulting tip value
    float taxdBill; //Holds the bill amount with tax
    
    //Calculate bill amount with tax
    taxdBill = ((billAmnt * taxRate)/100) + billAmnt;
    
    //Calculate tip from amount above
    tip = taxdBill * (tipRate / 100);
    
    //return tip amount
    return tip; 
}