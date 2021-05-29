//Implementation of the Piece class
#include "Pieces.h"
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std; 

//**************************************************************
// The constructor accepts arguments for all member variables. *
//**************************************************************

Piece::Piece(string n, string l, int v, bool cap, int r, int c, string colr, bool fT){
    n = name;
    l = letters;
    v = value;
    cap = captured;
    r = row;
    c = col;
    colr = colr;
    fT = firstT;
    
}

//****************************************************************
// Accessor functions for member variables of the Piece class    *
//****************************************************************
//Set name
void Piece::setName(string na){
    na = name;
}

//Set letters
void Piece::setLetters(string let){
    let = letters;
}
       
//Set value 
void Piece::setVal(int val){
    val = value;
}

//Set captured 
void Piece::setCap(bool cap){
    cap = captured;
}

//Set coordinates 
void Piece::setCoords(int r, int c){
    r  = row;
    c = col;
}
       
//Set color 
void Piece::setColor(string c){
    c = color; 
}
        
void Piece::setFT(bool cap){
    cap = captured;
}


//****************************************************************
// Mutator functions for member variables of the Piece class.    *
//****************************************************************
//Get name
string Piece::getName() const{
    return name;
}

//Get letters 
string Piece::getLetters() const{
    return letters;
}

//Get value
int Piece::getVal() const{
    return value;
}

//Get captured
bool Piece::getCap() const{
    return captured;
}

//Get row value
int Piece::getRow() const{
    return row;
}

//Get col value
int Piece::getCol() const{
    return col;
}

//Get color 
string Piece::getColor() const{
    return color;
}

//Get first turn status 
bool Piece::getFT() const{
    return firstT;
}