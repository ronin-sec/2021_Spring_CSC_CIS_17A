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
        //Constructors
        //Default
        Piece();
        //Parameterized
        Piece(std::string, std::string, int, bool, int, int, std::string, bool);
        //Dynamic Parameterized
        Piece(std::string *, std::string *, int *, bool *, int *, int *, std::string *, bool *);

        //Destructor
        ~Piece();

        //Accessor Functions (setters)
        void setName(std::string);
        void setLetters(std::string);
        void setVal(int);
        void setCap(bool);
        void setCoords(int, int); //(row, col)
        void setColor(std::string);
        void setFT(bool);
        
        //Mutator Functions (getters)
        std::string getName() ;
        std::string getLetters() ;
        int getVal() ;
        bool getCap() ;
        int getRow() ;
        int getCol() ;
        std::string getColor() ;
        bool getFT() ;
       
        /*
        bool getFT(){
            return firstT;
        };
        */
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
