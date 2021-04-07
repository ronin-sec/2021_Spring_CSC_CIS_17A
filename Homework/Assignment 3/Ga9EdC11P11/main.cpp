/* 
 * File:   Student Budget Program
 * Author: Antero Avalos
 * Created on 04/05/2021
 * Purpose:  Homework
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//struct declaration
struct MonthlyBudget {
    float housing;
    float util;
    float homeExp;
    float transp;
    float food;
    float med;
    float insurance;
    float ent;
    float clothes;
    float misc;
};

//Function Prototypes
MonthlyBudget getExpenses();
void dispResults(MonthlyBudget, MonthlyBudget);
void totalCheck(MonthlyBudget, MonthlyBudget);
//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    
    //Initialize Variables
    MonthlyBudget setBudg = {500.00, 150.00, 65.00, 50.00, 250.00, 30.00, 100.00, 150.00, 75.00, 50.00};
    MonthlyBudget spent = getExpenses();
    
    //Process or map Inputs to Outputs
    
    
    
    //Display Outputs
    dispResults(spent, setBudg);
    //Exit stage right!
    return 0;
}

//Function Definitions
MonthlyBudget getExpenses(){
    cout << "Enter housing cost for the month:$" << endl;
    cout << "Enter utilities cost for the month:$" << endl;
    cout << "Enter household expenses cost for the month:$" << endl;
    cout << "Enter transportation cost for the month:$" << endl;
    cout << "Enter food cost for the month:$" << endl;
    cout << "Enter medical cost for the month:$" << endl;
    cout << "Enter insurance cost for the month:$" << endl;
    cout << "Enter entertainment cost for the month:$" << endl;
    cout << "Enter clothing cost for the month:$" << endl;
    cout << "Enter miscellaneous cost for the month:$" << endl;

    MonthlyBudget spent;

    cin >> spent.housing >> spent.util  >> spent.homeExp 
        >> spent.transp >> spent.food >> spent.med 
        >> spent.insurance >> spent.ent >> spent.clothes >> spent.misc;
    
    return spent;
}

void dispResults(MonthlyBudget spent, MonthlyBudget setBudg){
    //Housing
    if(spent.housing == setBudg.housing)
        cout << "Housing Even" << endl;
    if(spent.housing > setBudg.housing)
        cout << "Housing Over" << endl;
    if(spent.housing < setBudg.housing)
        cout << "Housing Under" << endl;
    //Utilities
    if(spent.util == setBudg.util){
        cout << "Utilities Even" << endl;
    }else if(spent.util > setBudg.util){
        cout << "Utilities Over" << endl;
    }else{
        cout << "Utilities Under" << endl;
    }
    //Household Exp
    if(spent.homeExp == setBudg.homeExp){
        cout << "Household Expenses Even" << endl;
    }else if(spent.homeExp > setBudg.homeExp){
        cout << "Household Expenses Over" << endl;
    }else{
        cout << "Household Expenses Under" << endl;
    }
    //Transportation
    if(spent.transp == setBudg.transp){
        cout << "Transportation Even" << endl;
    }else if(spent.transp > setBudg.transp){
        cout << "Transportation Over" << endl;
    }else{
        cout << "Transportation Under" << endl;
    }
    //Food
    if(spent.food == setBudg.food){
        cout << "Food Even" << endl;
    }else if(spent.food > setBudg.food){
        cout << "Food Over" << endl;
    }else{
        cout << "Food Under" << endl;
    }
    //Medical
    if(spent.med == setBudg.med){
        cout << "Medical Even" << endl;
    }else if(spent.med > setBudg.med){
        cout << "Medical Over" << endl;
    }else{
        cout << "Medical Under" << endl;
    }
    //Insurance
    if(spent.insurance == setBudg.insurance){
        cout << "Insurance Even" << endl;
    }else if(spent.insurance > setBudg.insurance){
        cout << "Insurance Over" << endl;
    }else{
        cout << "Insurance Under" << endl;
    }
    //Entertainment
    if(spent.ent == setBudg.ent){
        cout << "Entertainment Even" << endl;
    }else if(spent.ent > setBudg.ent){
        cout << "Entertainment Over" << endl;
    }else{
        cout << "Entertainment Under" << endl;
    }
    //Clothing
    if(spent.clothes == setBudg.clothes){
        cout << "Clothing Even" << endl;
    }else if(spent.clothes > setBudg.clothes){
        cout << "Clothing Over" << endl;
    }else{
        cout << "Clothing Under" << endl;
    }
    //Miscellaneous
    if(spent.misc == setBudg.misc){
        cout << "Miscellaneous Even" << endl;
    }else if(spent.misc > setBudg.misc){
        cout << "Miscellaneous Over" << endl;
    }else{
        cout << "Miscellaneous Under" << endl;
    }
    totalCheck(spent, setBudg);
}


void totalCheck(MonthlyBudget spent, MonthlyBudget currBudg){
    float budgTotal = 0,
          spentTotal = 0;

    budgTotal = currBudg.clothes+currBudg.housing+currBudg.util+currBudg.homeExp+currBudg.transp+currBudg.food+currBudg.med+currBudg.insurance+currBudg.ent+currBudg.misc;
    spentTotal = spent.clothes+spent.housing+spent.util+spent.homeExp+spent.transp+spent.food+spent.med+spent.insurance+spent.ent+spent.misc;

    if(budgTotal == spentTotal){
        cout << "You were even";
    }
    else if(budgTotal > spentTotal){
        float diff =  budgTotal - spentTotal;
        cout << fixed << setprecision(2);
        cout << "You were $" << diff << " under budget";
    }else{
        float diff = spentTotal - budgTotal;
        cout << fixed << setprecision(2);
        cout << "You were $" << diff << " over budget";
    }
}