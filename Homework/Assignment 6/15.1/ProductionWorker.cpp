//Implementation of the ProductionWorker class, derived from Employee
#include "ProductionWorker.h"
using namespace std;

//**************************************************************
// Constructors for the ProductionWorker class.                        *
//**************************************************************
//Default constructor 
ProductionWorker::ProductionWorker(){
    shift = 0;
    hourlyPayRate = 0;
}

//Parameterized, takes arguments for all member variables
ProductionWorker::ProductionWorker(int sh, double rate){
    sh = shift;
    rate = hourlyPayRate;
}


//****************************************************************
// Mutator functions for member variables of the ProductionWorker class  *
//****************************************************************
void ProductionWorker::setShift(int sh){
    shift = sh;
}

void ProductionWorker::setRate(double r8){
    r8 = hourlyPayRate;
}

//****************************************************************
// Accessor functions for member variables of the ProductionWorker class *
//****************************************************************
int ProductionWorker::getShift() const{
    return shift;
}

double ProductionWorker::getRate() const{
    return hourlyPayRate; 
}