//System Libraries
#include <iostream>
#include <iomanip>
#include <math.h>
#include <string>
using namespace std;

//User Libraries
#include "Piece.h"

//Constant Expressions 
constexpr auto W_CH = char(0xDB); //White char
constexpr auto B_CH = char(0xFF); //Black char
constexpr auto G_CH = char(0xB1); //Gray char 
constexpr auto NEW_LINE = char(0x0a); //new line char
constexpr auto SPACE = char(0x20); //Space

//Function Prototypes
char** makeBoard_V2(int, int); //Generates board using 2d array
void prntBoard_V2(char**, int, int); //Print board
void prntPieces(char**, int, int); //Print pieces

//-----------------------------------------MAIN--------------------------------
int main()
{

	//Variables for board size:
	const int BW = 70;	//Board Width
	const int BH = 30;	//Board Height

	//create 2d board arr
	char** board = nullptr;
	
	//use function to make the board 
	board = makeBoard_V2(BW, BH);

	//display 2d board arr
	prntBoard_V2(board, BW, BH);

	//print pieces
        string q = " ";
        cout << "Enter quit to leave\n";
        cin >> q;

	//make sure to unallocate any memory used
	
	return 0;
}
//---------------------------------end of MAIN---------------------------------



char** makeBoard_V2(int boardWidth, int boardHeight) {
	//Create 2d pointer arr with board width and height
	char** boardPtr = nullptr;
	boardPtr = new char* [boardHeight];

	for (int i = 0; i < boardHeight; i++) {
		boardPtr[i] = new char[boardWidth];
	}

	//Adds the black padding rows above and below the board
	for(int col = 0; col < boardWidth; col++) {
		*(*(boardPtr + 0) + col) = B_CH;
		*(*(boardPtr + 2) + col) = B_CH;
		*(*(boardPtr + 27) + col) = B_CH;
		*(*(boardPtr + 29) + col) = B_CH;
	}
	//Padding to the left and right of board
	
	for (int row = 3; row < 27; row++)
	{
		for (int col = 0; col < 7; col++)
		{
			*(*(boardPtr + row) + col) = B_CH;
		}
		for (int col = 63; col < 70; col++)
		{
			*(*(boardPtr + row) + col) = B_CH;
		}

	}
	
	
	//Adds the contents of the following string 
	//to display letter indexes above and below board
	string letterIndex = 
		"          A      B      C      D      E      F      G      H         ";
	for (int col = 0; col < boardWidth; col++)
	{
		*(*(boardPtr + 1) + col) = letterIndex[col];
		*(*(boardPtr + 28) + col) = letterIndex[col];
	}
	
	//Add numerical index left and right of board
	char numIndex = '8';
	for (int row = 4 ; row < 27; row+=3, numIndex--)
	{
		int leftCol = 3,
			rightCol = 66;
		*(*(boardPtr + row) + leftCol) = numIndex;
		*(*(boardPtr + row) + rightCol) = numIndex;
	}

	//Next we add the rest of the board
	//Patterns used for line filling 
	//Pattern: White - Black - White - Black - White - Black - White - Black
	char patternA[56] = { W_CH, W_CH, W_CH, W_CH, W_CH, W_CH, W_CH,
						  B_CH, B_CH, B_CH, B_CH, B_CH, B_CH, B_CH, 
						  W_CH, W_CH, W_CH, W_CH, W_CH, W_CH, W_CH,
						  B_CH, B_CH, B_CH, B_CH, B_CH, B_CH, B_CH, 
					      W_CH, W_CH, W_CH, W_CH, W_CH, W_CH, W_CH,
						  B_CH, B_CH, B_CH, B_CH, B_CH, B_CH, B_CH, 
					      W_CH, W_CH, W_CH, W_CH, W_CH, W_CH, W_CH,
						  B_CH, B_CH, B_CH, B_CH, B_CH, B_CH, B_CH };
	//This pattern contains space in the middle (were the piece will go)
	char patternA_S[56]={ W_CH, W_CH, SPACE, SPACE, SPACE, W_CH, W_CH,
						  B_CH, B_CH, SPACE, SPACE, SPACE, B_CH, B_CH,
						  W_CH, W_CH, SPACE, SPACE, SPACE, W_CH, W_CH,
						  B_CH, B_CH, SPACE, SPACE, SPACE, B_CH, B_CH,
						  W_CH, W_CH, SPACE, SPACE, SPACE, W_CH, W_CH,
						  B_CH, B_CH, SPACE, SPACE, SPACE, B_CH, B_CH,
						  W_CH, W_CH, SPACE, SPACE, SPACE, W_CH, W_CH,
						  B_CH, B_CH, SPACE, SPACE, SPACE, B_CH, B_CH };
	//Pattern: Black - White - Black - White - Black - White - Black - White 
	char patternB[56] = { B_CH, B_CH, B_CH, B_CH, B_CH, B_CH, B_CH,
						  W_CH, W_CH, W_CH, W_CH, W_CH, W_CH, W_CH,
					      B_CH, B_CH, B_CH, B_CH, B_CH, B_CH, B_CH,
						  W_CH, W_CH, W_CH, W_CH, W_CH, W_CH, W_CH,
					      B_CH, B_CH, B_CH, B_CH, B_CH, B_CH, B_CH,
						  W_CH, W_CH, W_CH, W_CH, W_CH, W_CH, W_CH, 
						  B_CH, B_CH, B_CH, B_CH, B_CH, B_CH, B_CH,
						  W_CH, W_CH, W_CH, W_CH, W_CH, W_CH, W_CH };
	//This pattern contains space in the middle (were the piece will go)
	char patternB_S[56]={ B_CH, B_CH, SPACE, SPACE, SPACE, B_CH, B_CH,
						  W_CH, W_CH, SPACE, SPACE, SPACE, W_CH, W_CH,
						  B_CH, B_CH, SPACE, SPACE, SPACE, B_CH, B_CH,
						  W_CH, W_CH, SPACE, SPACE, SPACE, W_CH, W_CH,
						  B_CH, B_CH, SPACE, SPACE, SPACE, B_CH, B_CH,
						  W_CH, W_CH, SPACE, SPACE, SPACE, W_CH, W_CH,
						  B_CH, B_CH, SPACE, SPACE, SPACE, B_CH, B_CH,
						  W_CH, W_CH, SPACE, SPACE, SPACE, W_CH, W_CH };
	//Write the patterns to array, creating board 
	for (int col = 7, i = 0; col < 63; col++, i++)
	{
		*(*(boardPtr + 3) + col) = patternA[i];
		*(*(boardPtr + 4) + col) = patternA_S[i];
		*(*(boardPtr + 5) + col) = patternA[i];
		*(*(boardPtr + 6) + col) = patternB[i];
		*(*(boardPtr + 7) + col) = patternB_S[i];
		*(*(boardPtr + 8) + col) = patternB[i];
		*(*(boardPtr + 9) + col) = patternA[i];
		*(*(boardPtr + 10) + col) = patternA_S[i];
		*(*(boardPtr + 11) + col) = patternA[i];
		*(*(boardPtr + 12) + col) = patternB[i];
		*(*(boardPtr + 13) + col) = patternB_S[i];
		*(*(boardPtr + 14) + col) = patternB[i];
		*(*(boardPtr + 15) + col) = patternA[i];
		*(*(boardPtr + 16) + col) = patternA_S[i];
		*(*(boardPtr + 17) + col) = patternA[i];
		*(*(boardPtr + 18) + col) = patternB[i];
		*(*(boardPtr + 19) + col) = patternB_S[i];
		*(*(boardPtr + 20) + col) = patternB[i];
		*(*(boardPtr + 21) + col) = patternA[i];
		*(*(boardPtr + 22) + col) = patternA_S[i];
		*(*(boardPtr + 23) + col) = patternA[i];
		*(*(boardPtr + 24) + col) = patternB[i];
		*(*(boardPtr + 25) + col) = patternB_S[i];
		*(*(boardPtr + 26) + col) = patternB[i];
	}

	

	
	/*
	//Now fill array with gray chars to test
	for (int i = 0; i < boardHeight; i++) {
		for (int j = 0; j < boardWidth; j++) {
			*(*(boardPtr + i) + j) = GRAY_CH;
		}
	}
	*/
	/*
	
struct Piece {
	string name;
	char letters[3];
	int value;
	bool dead;
	int row;
	int col;
	string side;
};

};*/

	//declare struct arr of black pieces
	const int paSz = 16;
	struct Piece blackArr[paSz] = {
		{"Pawn1", "b P", 1, false, 23, 10, "black"},
		{"Pawn2", "b P", 1, false, 23, 17, "black"},
		{"Pawn3", "b P", 1, false, 23, 24, "black"},
		{"Pawn4", "b P", 1, false, 23, 31, "black"},
		{"Pawn5", "b P", 1, false, 23, 38, "black"},
		{"Pawn6", "b P", 1, false, 23, 45, "black"},
		{"Pawn7", "b P", 1, false, 23, 52, "black"},
		{"Pawn8", "b P", 1, false, 23, 59, "black"},
		{"King",  "b K", 10,false, 26, 31, "black"},
		{"Queen", "b Q", 9, false, 26, 38, "black"},
		{"Knight1", "b N", 3, false, 26, 17, "black"},
		{"Knight2", "b N", 3, false, 26, 52, "black"},
		{"Bishop1", "b B", 3, false, 26, 24, "black"},
		{"Bishop2", "b B", 3, false, 26, 45, "black"},
		{"Tower1", "bT", 5, false, 26, 10, "black"},
		{"Tower2", "bT", 5, false, 26, 59, "black"}
	};

	//declare struct arr of white pieces
	struct Piece whiteArr[paSz] = {
		{"Pawn1", "w P", 1, false, 5,10, "white"},
		{"Pawn2", "w P", 1, false, 5,17, "white"},
		{"Pawn3", "w P", 1, false, 5,24, "white"},
		{"Pawn4", "w P", 1, false, 5,31, "white"},
		{"Pawn5", "w P", 1, false, 5,38, "white"},
		{"Pawn6", "w P", 1, false, 5,45, "white"},
		{"Pawn7", "w P", 1, false, 5,52, "white"},
		{"Pawn8", "w P", 1, false, 5,59, "white"},
		{"King",  "w K", 10,false, 8,31, "white"},
		{"Queen", "w Q", 9, false, 8,38, "white"},
		{"Knight1", "w N", 3, false, 8,17, "white"},
		{"Knight2", "w N", 3, false, 8,52, "white"},
		{"Bishop1","w B", 3, false, 8,24, "white"},
		{"Bishop2","w B", 3, false, 8,45, "white"},
		{"Tower1", "w T", 5, false, 8,10, "white"},
		{"Tower2", "w T", 5, false, 8,59, "white"}
	};
	
	//Store the letters of each piece in string that can be assigned to board
	//Black pieces:
	string bPawn1 = blackArr[0].letters;
	string bPawn2 = blackArr[1].letters;
	string bPawn3 = blackArr[2].letters;
	string bPawn4 = blackArr[3].letters;
	string bPawn5 = blackArr[4].letters;
	string bPawn6 = blackArr[5].letters;
	string bPawn7 = blackArr[6].letters;
	string bPawn8 = blackArr[7].letters;
	string bKing =  blackArr[8].letters;
	string bQueen = blackArr[9].letters;
	string bKnight1 = blackArr[10].letters;
	string bKnight2 = blackArr[11].letters;
	string bBishop1 = blackArr[12].letters;
	string bBishop2 = blackArr[13].letters;
	string bTower1 = blackArr[14].letters;
	string bTower2 = blackArr[15].letters;
	//White pieces:
	string wPawn1 = whiteArr[0].letters;
	string wPawn2 = whiteArr[1].letters;
	string wPawn3 = whiteArr[2].letters;
	string wPawn4 = whiteArr[3].letters;
	string wPawn5 = whiteArr[4].letters;
	string wPawn6 = whiteArr[5].letters;
	string wPawn7 = whiteArr[6].letters;
	string wPawn8 = whiteArr[7].letters;
	string wKing = whiteArr[8].letters;
	string wQueen = whiteArr[9].letters;
	string wKnight1 = whiteArr[10].letters;
	string wKnight2 = whiteArr[11].letters;
	string wBishop1 = whiteArr[12].letters;
	string wBishop2 = whiteArr[13].letters;
	string wTower1 = whiteArr[14].letters;
	string wTower2 = whiteArr[15].letters;
	

	//Write pieces to arr
	for (int i = 0, row = 25, col = 9; i < 2; i++, col++) {
		*(*(boardPtr + row) + col) = bTower1[i];
	}

	return boardPtr;

}


void prntBoard_V2(char** boardPtr, int boardW, int boardH) {
	for (int i = 0; i < boardH; i++) {
		for (int j = 0; j < boardW; j++) {
			if (j == boardW - 1) {
				cout << *(*(boardPtr + i) + j);
			}
			else {
				cout << *(*(boardPtr + i) + j);
			}
		}
		if (i != boardW - 1) {
			cout << endl;
		}
	}
}

