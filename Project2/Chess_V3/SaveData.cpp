//Implementation of the SaveData class
#include "SaveData.h"
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

//Static member variable
int SaveData::arrSize = 16;

//**************************************************************
// Constructor for the SaveData class.                         *
//**************************************************************
SaveData::SaveData(string n, Piece array[]){
    
    this -> name = n;
    this -> colorArray = array;
};

//Copy constructor for this class
SaveData::SaveData(SaveData &obj){
    name = obj.name;
    colorArray = obj.colorArray;
}

//****************************************************************
// Mutator functions for member variables of the SaveData class  *
//****************************************************************
void SaveData::setName(string n) {
    this -> name = n;
}

void SaveData::setArray(Piece pArray[]) {
    this -> colorArray = pArray;
}


//****************************************************************
// Accessor functions for member variables of the SaveData class.   *
//****************************************************************
string SaveData::getName(){
    return name;
}

Piece SaveData::getPiece( int index, Piece array[]) {
    return array[index];
}

