#ifndef PIECES_H
#define PIECES_H


struct Piece {
	string name;
	string letters;
	int value;
	bool dead;
	int row;
	int col;
	string color;
};

#endif 