/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Purpose:  Driver program to test out the statistics problem.
 */

//Libraries
#include <iostream>//I/O
using namespace std;

//User Libraries
#include "Array.h"
#include "Stats.h"

//No Global Constants

//Function Prototypes I supply
Array *fillAry(int,int);        //Fill an array and put into a structure
void prntAry(const Array *,int);//Print the array 
int *copy(const int *,int);     //Copy the array
void mrkSort(int *,int);        //Sort an array
void prtStat(const Stats *);    //Print the structure
void rcvrMem(Array *);          //Recover memory from the Array Structure
void rcvrMem(Stats *);          //Recover memory from Statistics Structure

//Functions you are to supply
Stats *stat(const Array *);     //Find & store mean, median, & modes in structure

//Execution begins here
int main(int argc, char*argv[]) {
    //Declare variables
    int arySize;//Array Size
    int modNum; //Number to control the modes (digits 0 to 9 allowed)
    Array *array;
    
    //Input the size and mod number
    cout<<"This program develops an array to be analyzed"<<endl;
    cout<<"Array size from mod number to 100"<<endl;
    cout<<"Mod number from 2 to 10"<<endl;
    cout<<"Input the Array Size and the mod number to be used."<<endl;
    cin>>arySize>>modNum;
    cout<<endl<<endl;
    
    //Fill the array
    array=fillAry(arySize,modNum);
    
    //Print the initial array
    cout<<"Original Array before sorting"<<endl;
    prntAry(array,10);
    
    //Sort the array
    mrkSort(array->data,array->size);
    cout<<"Sorted Array to be utilize for the stat function"<<endl;
    prntAry(array,10);
    
    //Calculate some of the statistics
    Stats *stats=stat(array);
    
    //Print the statistics
    prtStat(stats);
    
    //Recover allocated memory
    rcvrMem(array);
    rcvrMem(stats);
    
    //Exit stage right
    return 0;
}

int *copy(const int *a,int n){
    //Declare and allocate an array
    //that is a c
    int *b=new int[n];
    //Fill
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
    //Return the copy
    return b;
}

void prtStat(const Stats *ary){
    cout<<endl;
    cout<<"The average of the array = "<<ary->avg<<endl;
    cout<<"The median of the array  = "<<ary->median<<endl;
    cout<<"The number of modes      = "<<
            ary->mode->size<<endl;
    cout<<"The max Frequency        = "<<
            ary->modFreq<<endl;
    if(ary->mode->size==0){
        cout<<"The mode set             = {null}"<<endl;
        return;
    }
    cout<<"The mode set             = {";
    for(int i=0;i<ary->mode->size-1;i++){
        cout<<ary->mode->data[i]<<",";
    }
    cout<<ary->mode->data[ary->mode->size-1]<<"}"<<endl;
}

void mrkSort(int *array,int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(array[j]<array[i]){
                int temp=array[i];
                array[i]=array[j];
                array[j]=temp;
            }
        }
    }
}

void rcvrMem(Stats *stats){
    rcvrMem(stats->mode);
    delete stats;
}

void rcvrMem(Array *array){
    delete []array->data;
    delete array;
}

void prntAry(const Array *array,int perLine){
    //Output the array
    for(int i=0;i<array->size;i++){
        cout<<array->data[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

Array *fillAry(int n, int modNum){
    //Allocate memory
    Array *array=new Array;
    array->size=n;
    array->data=new int[array->size];
    
    //Fill the array with mod numbers
    for(int i=0;i<n;i++){
        array->data[i]=i%modNum;
    }
    
    //Exit function
    return array;
}

Stats *stat(const Array *array){
    //Non-working stub to be completed by the student
    //cout<<endl<<"Stat function to be completed by the student"<<endl;

    //find the max frequency-----------------------------------------------------------
    int count = 0,
        maxFreq = 0;

    for (int j = 0; j < (*array).size; j++) {
        count = 0;
        for (int i = 0; i < (*array).size; i++) {
            if (j == ((*array).data[i])) {
                count++;
            }
        }
        if (count > maxFreq) {
            maxFreq = count;
        }
    }

    //Find the number of modes--------------------------------------------------------------------
    int mode = 0,
        mode0 = 0;

    for (int i = 1, j = (maxFreq * 2) - 1; i < (*array).size, j < (*array).size; i++, j += maxFreq) {
        if ( (*array).data[+1] == 0) {
            mode0 = 1;
        } else {
            break;
        }
        if ( (*array).data[j] == i) {
            mode = i;
        }
    }

    mode += mode0; //the variable mode contains the number of modes in the set 
    

    Stats *stats=new Stats; //dynamically creates new Stat structure

    stats->mode=new Array;  //dynamically creates new array for mode member in Stats
    stats->mode->size=mode;    //sets size member of Array, which is itself a member of Stats ^
    
    int nModes=mode; //Size of mode array = number of modes
    if(nModes!=0)stats->mode->data=new int[nModes]; //Alocate array using nModes
    
    stats->modFreq=maxFreq; //Set max freq to value found earlier, see line 152 onward

    //fill the mode array---------------------------------------------
    for (int i = 0; i <= mode; i++) {
        stats->mode->data[i] = i;
    }

    //Find the median------------------------------------------------------------------------------------

    int median; 
    int  sum = 0;
    int size = (*array).size;
    
    for(int i = 0; i < (*array).size; i++)
    {
        sum += (*array).data[i];
    }
    
    if(size % 2 == 0){
        //If even, get next number in arrPtr and divide by 2
        median = (*array).data[size/2];
        median = (median +(*array).data[size/2 - 1] / 2);
    }
    if(size % 2 != 0){
        median = sum / size;
    }
    stats->median=median; //Assign calculated value to median    
    
    //Find the average-------------------------------------------------------------------------
    float avg; 
    float fsum = 0;    
    
    for(int i = 0; i < (*array).size; i++)
    {
        fsum += (*array).data[i];
    }
    
    if(size % 2 == 0){
        //If even, get next number in arrPtr and divide by 2
        avg = (*array).data[size/2];
        avg = (avg +(*array).data[size/2 - 1] / 2);
    }
    if(size % 2 != 0){
        avg = fsum / size;
    }
    stats->avg=avg; //Assign calculated value to average

    return stats;
}
