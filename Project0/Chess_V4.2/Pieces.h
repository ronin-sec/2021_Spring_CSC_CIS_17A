#ifndef PIECES_H
#define PIECES_H

//Stores information used to display pieces
struct Piece {
	string name;
	string letters;
	int value;
	bool captured;
	int row;
	int col;
	string color;
    bool firstT;
};

//Stores information used to move pieces
struct Ply {
    string player; //Player color
    int pRow;    //Current position row coordinate
    int pCol;    //Current position column coordinate 
    int dRow;    //Destination row coordinate
    int dCol;    //Destination column coordinate
};

#endif 