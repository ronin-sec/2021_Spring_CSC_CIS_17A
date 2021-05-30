//Specification of ProductionWorker class
#ifndef PRODUCTIONWORKER_H
#define PRODUCTIONWORKER_H

#include "Employee.h"

class ProductionWorker: public Employee{
    //All member variables made private
    protected:
        int shift; 
        double hourlyPayRate;
    
    public: 
        //Default constructor
        ProductionWorker();
        
        //Parameterized, takes arguments for all member variables
        ProductionWorker(int, double);
        
        //Mutators
        void setShift(int);
        void setRate(double);
        
        //Accessors
        int getShift() const;
        double getRate() const; 
        
};


#endif /* PRODUCTIONWORKER_H */

