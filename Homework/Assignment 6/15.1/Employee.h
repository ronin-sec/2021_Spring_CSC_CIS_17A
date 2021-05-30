//Specification of the Employee class
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee {
    //All member variables made private
    protected:
        std::string name;
        int number;
        std::string date; 
    
    public: 
        //Default Constructor
        Employee();
        
        //Parameterized, takes arguments for all member variables
        Employee(std::string, int, std::string);
        
        //Mutators 
        void setName(std::string);
        void setNumber(int);
        void setDate(std::string);
        
        //Accessors
        std::string getName() const;
        int getNumber() const;
        std::string getDate() const;           
   
};


#endif /* EMPLOYEE_H */