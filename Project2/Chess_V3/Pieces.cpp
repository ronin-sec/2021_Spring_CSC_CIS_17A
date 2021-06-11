//Implementation of the Piece class, contains the definition of all
//class functions/methods.
#include "Pieces.h"
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

//**************************************************************
// Constructors for the Piece class.                           *
//**************************************************************

//Default Constructor, creates Piece with member variable values that are
//meat to be replaced with proper values
Piece::Piece(){
    name = "";
    letters = "";
    value = 0;
    captured = false;
    row = 0;
    col = 0;
    color = "";
    firstT = false;
}

//Parameterized Constructor of this feller, creates a Piece object with the
//specified member variable values
Piece::Piece(string n, string l, int v, bool cap, int r, int c, string colr, bool fT){
    this -> name = n;
    this -> letters = l;
    this -> value = v;
    this -> captured = cap;
    this -> row = r;
    this -> col = c;
    this -> color = colr;
    this -> firstT = fT;
}

//Dynamically parameterized constructor which takes pointers of all member
//variables 
Piece::Piece(std::string *n, std::string *l , int *v, bool *cap, int *r, int *c, std::string *colr, bool *fT){
    n = new string;
    l = new string;
    v = new int;
    cap = new bool;
    r = new int;
    c = new int;
    colr = new string;
    fT = new bool;
};

//Destructor, used for piece objects that are declared with dynamic members 
Piece::~Piece(){
    delete name;
    delete letters;
    delete value;
    delete captured;
    delete row;
    delete col;
    delete color;
    delete firstT;
};

//****************************************************************
// Mutator functions for member variables of the Piece class     *
//****************************************************************
//Set name
void Piece::setName(string na){
    this -> name = na;
}

//Set letters
void Piece::setLetters(string let){
    this -> letters = let;
}

//Set value
void Piece::setVal(int val){
    this -> value = val;
}

//Set captured
void Piece::setCap(bool cap){
    this -> captured = cap;
}

//Set coordinates
void Piece::setCoords(int r, int c){
    this -> row = r;
    this -> col = c;
}

//Set color
void Piece::setColor(string c){
    this -> color = c;
}

void Piece::setFT(bool cap){
    this -> captured = cap;
}


//****************************************************************
// Accessor functions for member variables of the Piece class.    *
//****************************************************************
//Get name
string Piece::getName(){
    return name;
}

//Get letters
string Piece::getLetters(){
    return letters;
}

//Get value
int Piece::getVal(){
    return value;
}

//Get captured
bool Piece::getCap(){
    return captured;
}

//Get row value
int Piece::getRow(){
    return row;
}

//Get col value
int Piece::getCol(){
    return col;
}

//Get color
string Piece::getColor(){
    return color;
}

//Get first turn status
bool Piece::getFT(){
    return firstT;
}