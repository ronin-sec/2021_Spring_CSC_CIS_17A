//Specification of the SaveData class
#ifndef SAVEDATA_H
#define SAVEDATA_H

#include "Pieces.h"

#include <string>

using namespace std;

class SaveData {
    
    private:    
        string name; 
        static int arrSize;
        Piece colorArray[arrSize];
        
    
    public:
        //Constructor
        SaveData(std::string, Piece[]);          
        
        //Mutator functions 
        void setName(string n);
        void setArray(Piece pArray[]);
        
        
        //Accessor Functions
        string getName() const;
        Piece getPiece(int index, Piece array[]) const;
};

#endif /* SAVEDATA_H */