//Specification of the Piece class
#ifndef PIECES_H
#define PIECES_H

#include <string>

//Piece stores piece information contained in member vars below 
class Piece {
    
    private:
        std::string name;        //"Pawn", etc..    
        std::string letters;     //"bP", means black pawn, etc.. 
        int value;               //numerical value assigned for AI choice making
        bool captured;           //if captured, piece is no longer on the field. 
        int row;                 //row position of piece in it's corresponding array
        int col;                 //column position of piece inn it's corresponding array
        std::string color;       //used to identify the piece color
        bool firstT;             //check if this is piece's first turn, used for pawns only, currently 
    
    public:            
        //Constructor
        Piece(std::string, std::string, int, bool, int, int, std::string, bool); 
        
        //Accessor Functions (setters)
        void setName(std::string);
        void setLetters(std::string);
        void setVal(int);
        void setCap(bool);
        void setCoords(int, int); //(row, col)
        void setColor(std::string);
        void setFT(bool);        
        
        //Mutator Functions (getters)
        std::string getName() const;
        std::string getLetters() const;
        int getVal() const;
        bool getCap() const;
        int getRow() const;
        int getCol() const;
        std::string getColor() const;
        bool getFT() const;
};

//Structure storing move information contained in member variables seen below 
struct Ply {
    std::string player; //Player color, "white" or "black"
    int pRow;    //Current position row coordinate
    int pCol;    //Current position column coordinate 
    int dRow;    //Destination row coordinate
    int dCol;    //Destination column coordinate
};

#endif 