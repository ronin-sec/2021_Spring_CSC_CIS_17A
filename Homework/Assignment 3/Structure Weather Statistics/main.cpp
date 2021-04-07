/* 
 * File:   Structure Weather Statistics
 * Author: Antero Avalos
 * Created on 04/05/2021
 * Purpose:  Homework
 */


//System Libraries
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

//Declaring Month struct
struct Month
{
    string name;
    float rainFall;
    float highTemp;
    float lowTemp;
    float avgTemp;
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


    struct Month mArr[ARR_SIZE] = { {"Jan", 0, 0, 0, 0}, {"Feb", 0, 0, 0, 0}, {"Mar", 0, 0, 0, 0}, 
                                    {"Apr", 0, 0, 0, 0}, {"May", 0, 0, 0, 0}, {"Jun", 0, 0, 0, 0},
                                    {"Jul", 0, 0, 0, 0}, {"Aug", 0, 0, 0, 0}, {"Sep", 0, 0, 0, 0},
                                    {"Oct", 0, 0, 0, 0}, {"Nov", 0, 0, 0, 0}, {"Dec", 0, 0, 0, 0}};
    
    for(int i = JAN; i <= DEC; i++){
        string name;
        float  lowT, hiT;
        float rain;
        
        cin >> name >> rain >> lowT >> hiT;
        
        mArr[i].name = name;
        mArr[i].rainFall = rain;
        mArr[i].lowTemp = lowT;
        mArr[i].highTemp = hiT;
        mArr[i].avgTemp = (hiT+lowT)/2;
    }

    /*
    //testing:disply rainfall of all months... checking that it is stored correctly
    for (int i = JAN; i <= DEC; i++)
    {
        cout << fixed << mArr[i].rainFall << endl;
    }
    */

    avgRainfall(mArr, DEC);

    temps(mArr, DEC);

    return 0;
}
//---------------------------------END of MAIN-----------------------------------------------



//Function Definitions

void avgRainfall (Month mArr[], int monthCount)
{
    float sum = 0;
    for(int i = JAN; i <= monthCount; i++)
    {
        sum += mArr[i].rainFall;
    }

    //testing
    //cout << "SUM: " << sum;

    float average = sum/12;
    cout << fixed << setprecision(1);
    cout << "Average Rainfall " << ceil(average*10)/10 << " inches/month" << endl;
}

void temps(Month mArr[], int monthCount)
{
    int hiTemp = mArr[0].highTemp;
    int lowTemp = mArr[0].lowTemp;;
    string lowMonth = mArr[0].name;
    string hiMonth = mArr[0].name;

    for(int i = 1; i < monthCount; i++){
        
        if(hiTemp < mArr[i].highTemp){
            hiTemp = mArr[i].highTemp;
            hiMonth = mArr[i].name;
        }
        if(lowTemp > mArr[i].lowTemp){
            lowTemp = mArr[i].lowTemp;
            hiMonth = mArr[i].name;
        }

    }

    cout << "Lowest  Temperature " << lowMonth << "  " << lowTemp << " Degrees Fahrenheit" << endl;
    cout << "Highest Temperature " << hiMonth << "  " << hiTemp << " Degrees Fahrenheit" << endl;
    
    float   avgTemp = 0,
            hiSum = 0,
            lowSum = 0;
    
    for(int i = 0; i < monthCount; i++){
        hiSum += mArr[i].highTemp;
        lowSum += mArr[i].lowTemp;
    }
    
    //cout << "Lowsum: " << lowSum << "hi sum: " << hiSum << endl;
    
    avgTemp = (hiSum+lowSum)/(monthCount*2);
    cout << setprecision(0);
    cout << "Average Temperature for the year " << floor(avgTemp) << " Degrees Fahrenheit" << endl;;
}

