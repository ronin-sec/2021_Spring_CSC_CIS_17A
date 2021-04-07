/* 
 * File:   Weather Stats with Enum Data Type
 * Author: Antero Avalos
 * Created on : 04/05/2021
 * Purpose:  Use an enumerated data type for months
 */
 
 
//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Declaring Month struct
struct Month
{
    string name;
    float rainFall;
    float highTemp;
    float lowTemp;
};
//enums
enum Months {JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC};
//Function Prototypes
void avgRainfall (Month [], int);
void temps(Month [], int);
//---------------------------------MAIN------------------------------------------------------
//Execution Begins Here
int main(int argc, char** argv) {
    const int ARR_SIZE = 12;


    struct Month mArr[ARR_SIZE] = { {"Jan", 0, 0, 0}, {"Feb", 0, 0, 0}, {"Mar", 0, 0, 0}, {"Apr", 0, 0, 0},
                                    {"May", 0, 0, 0}, {"Jun", 0, 0, 0}, {"Jul", 0, 0, 0}, {"Aug", 0, 0, 0}, 
                                    {"Sep", 0, 0, 0}, {"Oct", 0, 0, 0}, {"Nov", 0, 0, 0}, {"Dec", 0, 0, 0} };
    
    for(int i = 0; i < JUL; i++){
        cout << "Enter the total rainfall for the month:" << endl;
        cout << "Enter the high temp:" << endl;
        cout << "Enter the low temp:" << endl;
        
        float rain, lowT, hiT;
        
        cin >> rain >> hiT >> lowT;
        
        mArr[i].rainFall = rain;
        mArr[i].highTemp = hiT;
        mArr[i].lowTemp = lowT;
    
    }
    

   

    avgRainfall(mArr, 6);

    temps(mArr, 6);

    return 0;
}
//---------------------------------END of MAIN-----------------------------------------------



//Function Definitions

void avgRainfall (Month mArr[], int monthCount)
{
    float sum = 0;
    for(int i = JAN; i < monthCount; i++)
    {
        sum += mArr[i].rainFall;
    }

    float average = sum/monthCount;
    cout << fixed << setprecision(2);
    cout << "Average monthly rainfall:" << average << endl;
}

void temps(Month mArr[], int monthCount)
{
    int hiTemp = mArr[0].highTemp;
    int lowTemp = mArr[0].lowTemp;;

    for(int i = 1; i < monthCount; i++){
        
        if(hiTemp < mArr[i].highTemp){
            hiTemp = mArr[i].highTemp;
        }
        if(lowTemp > mArr[i].lowTemp){
            lowTemp = mArr[i].lowTemp;
        }

    }

    cout << "High Temp:" << hiTemp << endl;
    cout << "Low Temp:" << lowTemp << endl;
    
    float   avgTemp = 0,
            hiSum = 0,
            lowSum = 0;
    
    for(int i = 0; i < monthCount; i++){
        hiSum += mArr[i].highTemp;
        lowSum += mArr[i].lowTemp;
    }
    
    //cout << "Lowsum: " << lowSum << "hi sum: " << hiSum << endl;
    
    avgTemp = (hiSum+lowSum)/(monthCount*2);
    cout << setprecision(1);
    cout << "Average Temp:" << avgTemp;
}


