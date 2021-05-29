#ifndef PIECES_H
#define PIECES_H

//structure stores piece information contained in member vars below 
struct Piece {
    string name;        //"Pawn", etc..    
    string letters;     //"bP", means black pawn, etc.. 
    int value;          //numerical value assigned for AI choice making
    bool captured;      //if captured, piece is no longer on the field. 
    int row;            //row position of piece in it's corresponding array
    int col;            //column position of piece inn it's corresponding array
    string color;       //-----unsure what this is for yet--------not used in current version (4.3)
    bool firstT;        //check if this is piece's first turn, used for pawns only, currently 
};

//Structure storing move information contained in member variables seen below 
struct Ply {
    string player; //Player color, "white" or "black"
    int pRow;    //Current position row coordinate
    int pCol;    //Current position column coordinate 
    int dRow;    //Destination row coordinate
    int dCol;    //Destination column coordinate
};

#endif 