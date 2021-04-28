//System Libraries
#include <iostream>
#include <iomanip>
#include <math.h>
#include <string>
using namespace std;

//User Libraries
#include "Pieces.h"

//Constant Expressions 
constexpr auto W_CH = char(0x58); //White char
constexpr auto B_CH = char(0x20); //Black char
constexpr auto G_CH = char(0xB1); //Gray char 
constexpr auto NEW_LINE = char(0x0a); //new line char
constexpr auto SPACE = char(0x20); //Space

//Function Prototypes
char** makeBoard_V2(int, int,Piece [],Piece[]); //Generates board using 2d array, pieces and board
void prntBoard_V2(char**, int, int);			//Print board
void writeLetters(char**, Piece [], Piece []);	//Write letters to board array
void writePatterns(char**);						//Write black and white to board array


void destroy(char**, int);						//Unallocate memory
void writePiece_v2(char**, Piece[]);			//Redesigned write Piece function

Ply getPly(string);								//PLayer turn information, used for the movePiece function
int processLetter(char);						//Used for conversion of user input into board coordinates
int processNum(int);							//Used for conversion of user input into board coordinates

void turnCheck(int&, string&);					//Check turnCount variable to see who's turn it is

void movePiece(Ply, Piece[], Piece[]);			//Move piece using ply data

void clearScreen();								//Outputs a bunch of newlines to shows the new board

string idPiece(Ply, Piece[], int&);					//Identifies pieces by name, using position coordinates (used by legalM)

bool legalM(Ply , Piece [], Piece []);			//returns bool to indicate move legality (uses functions below)

bool pwnLogic(Ply,Piece[],Piece[],int);		//Checks that move is legal for pawns

bool checkIn(char, int);					//Validates user input during getPLy function

//-----------------------------------------MAIN--------------------------------
int main()
{

	//Variables for board size:
	const int BW = 70;	//Board Width
	const int BH = 30;	//Board Height

	//create 2d board arr
	char** board = nullptr;
	
	//struct arrays that contain information for all pieces:
	//Black pieces
	const int paSz = 16; //Piece array size
	//white pieces 
	struct Piece whiteArr[paSz] = {
		{"Pawn", "wP", 1, false, 	22, 9, "white", false},
		{"Pawn", "wP", 1, false, 	22, 16, "white", false},
		{"Pawn", "wP", 1, false, 	22, 23, "white", false},
		{"Pawn", "wP", 1, false, 	22, 30, "white", false},
		{"Pawn", "wP", 1, false, 	22, 37, "white", false},
		{"Pawn", "wP", 1, false, 	22, 44, "white", false},
		{"Pawn", "wP", 1, false, 	22, 51, "white", false},
		{"Pawn", "wP", 1, false, 	22, 58, "white", false},
		{"King",  "wK", 10,false, 	25, 30, "white", false},
		{"Queen", "wQ", 9, false, 	25, 37, "white", false},
		{"Knight", "wN", 3, false,  25, 16, "white", false},
		{"Knight", "wN", 3, false,  25, 51, "white", false},
		{"Bishop","wB", 3, false, 	25, 23, "white", false},
		{"Bishop","wB", 3, false, 	25, 44, "white", false},
		{"Tower", "wT", 5, false, 	25, 9, "white", false},
		{"Tower", "wT", 5, false, 	25, 58, "white", false}
	};
	//black pieces
	struct Piece blackArr[paSz] = {
		{"Pawn", "bP", 1, false, 	7, 9, "black", false},
		{"Pawn", "bP", 1, false, 	7, 16, "black", false},
		{"Pawn", "bP", 1, false, 	7, 23, "black", false},
		{"Pawn", "bP", 1, false, 	7, 30, "black", false},
		{"Pawn", "bP", 1, false, 	7, 37, "black", false},
		{"Pawn", "bP", 1, false, 	7, 44, "black", false},
		{"Pawn", "bP", 1, false, 	7, 51, "black", false},
		{"Pawn", "bP", 1, false, 	7, 58, "black", false},
		{"King",  "bK", 10,false, 	4, 30, "black", false},
		{"Queen", "bQ", 9, false, 	4, 37, "black", false},
		{"Knight", "bN", 3, false,  4, 16, "black", false},
		{"Knight", "bN", 3, false,  4, 51, "black", false},
		{"Bishop", "bB", 3, false,  4, 23, "black", false},
		{"Bishop", "bB", 3, false,  4, 44, "black", false},
		{"Tower", "bT", 5, false, 	4, 9, "black", false},
		{"Tower", "bT", 5, false, 	4, 58, "black", false}
	};
	


	//display welcome msg 
	cout << "Welcome to Chess_Project 1!" << endl;
	//Start these variables off with the first turn values
	// they get modified as the game goes on 
	int turnCount = 1;
	string player = " ";
	Ply moveData;

	//Loop contains main game logic
	bool cMate = false; //if no check mate detected...
	do
	{
		//use function to make the board 
		board = makeBoard_V2(BW, BH, whiteArr, blackArr);
		
		//display 2d board arr	
		prntBoard_V2(board, BW, BH);

		//check who's turn it is
		turnCheck(turnCount, player);

		if(player == "white"){
			cout << "White's Turn. \nPress Enter to continue. \n";
		}else{
			cout << "Black's Turn: \nPress Enter to continue. \n";
		}

		//get the corresponding ply data
		moveData = getPly(player);

		/*	
		//testing: output members of moveData
		cout << "Move data recorded: \n"
			 << moveData.player << endl
			 << moveData.pCol << endl
			 << moveData.pRow << endl
			 << moveData.dCol << endl
			 << moveData.dRow << "\n\n\n";
		*/


		//check if move is legal
		while(legalM(moveData, whiteArr, blackArr) != true){
			cout << "Your move selection is not legal!\n" << endl;
			moveData = getPly(player);
		}
			
		//"move" the piece by updating it's coordinate values in struct array
		movePiece(moveData, blackArr, whiteArr);
		
		//writePieceV2 needs to check the boolean value in each piece to see if it will be printed
		// if the piece is "captured", it gets replaced with an empty space 
		clearScreen();
	
	} while (cMate != true);
	
	
	//get ply from white 
	//getPly(white);
	//move using ply 
	//movePiece(board, )

	//make sure to unallocate any memory used
	destroy(board, BH);
	return 0;
}
//---------------------------------end of MAIN---------------------------------


char** makeBoard_V2(int boardWidth, int boardHeight, Piece whitArr[], Piece blckArr[]) {
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
	writePatterns(boardPtr);
	writeLetters(boardPtr, whitArr, blckArr);

	return boardPtr;
}

void writePatterns(char** boardPtr) {
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
	char patternA_S[56] ={W_CH, SPACE, SPACE, SPACE, SPACE, SPACE, W_CH,
						  B_CH, SPACE, SPACE, SPACE, SPACE, SPACE, B_CH,
						  W_CH, SPACE, SPACE, SPACE, SPACE, SPACE, W_CH,
						  B_CH, SPACE, SPACE, SPACE, SPACE, SPACE, B_CH,
						  W_CH, SPACE, SPACE, SPACE, SPACE, SPACE, W_CH,
						  B_CH, SPACE, SPACE, SPACE, SPACE, SPACE, B_CH,
						  W_CH, SPACE, SPACE, SPACE, SPACE, SPACE, W_CH,
						  B_CH, SPACE, SPACE, SPACE, SPACE, SPACE, B_CH };
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
	char patternB_S[56] ={B_CH, SPACE, SPACE, SPACE, SPACE, SPACE, B_CH,
						  W_CH, SPACE, SPACE, SPACE, SPACE, SPACE, W_CH,
						  B_CH, SPACE, SPACE, SPACE, SPACE, SPACE, B_CH,
						  W_CH, SPACE, SPACE, SPACE, SPACE, SPACE, W_CH,
						  B_CH, SPACE, SPACE, SPACE, SPACE, SPACE, B_CH,
						  W_CH, SPACE, SPACE, SPACE, SPACE, SPACE, W_CH,
						  B_CH, SPACE, SPACE, SPACE, SPACE, SPACE, B_CH,
						  W_CH, SPACE, SPACE, SPACE, SPACE, SPACE, W_CH };
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
}

void writeLetters(char** boardPtr, Piece whitArr[], Piece blckArr[]){
	//declare struct arr of black pieces
	
		
	writePiece_v2(boardPtr, blckArr);
	writePiece_v2(boardPtr, whitArr);
}

void writePiece_v2(char** boardPtr, Piece colorArr[]) {
	//there are 16 pieces of each color 
	
	//iterate color array to write each piece on the board based on its members 
	//we can use the bool dead to decide wether to print it or not

	for (int i = 0; i < 16; i++) {
		string iLetters = colorArr[i].letters;
		for (int j = 0, row = colorArr[i].row, col = colorArr[i].col; j < 2; j++, col++) {
			*(*(boardPtr + row) + col) = iLetters[j];
		}
	}
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

void destroy(char** boardPtr, int rows) {
	for (int i = 0; i < rows; i++) {
		delete[] boardPtr[i];
	}
}


Ply getPly(string player){
	Ply input;
	
	if(player == "white"){
		input.player = "white";
	}else{
		input.player = "black";
	}
	
	cin.ignore();
	char pLetter = ' '; //input from position letter 
	int  pNum = 0;		//input from position row
	char dLetter = ' '; //input from destination letter
	int  dNum = 0;		//input from destination row
	
	cout << "You must enter location of the piece you'd like to move,\n"
			<< "then the location you'd like to move it to... \n\n";
	
	cout << "What piece do you want to move(e.x.: A 8): ";
	
	//get position values 
	cin >> pLetter >> pNum;	
	//validate piece position input 
	while(checkIn(pLetter, pNum) != true){
		cout << "Your selection is invalid.\n"
			    "Choose column, then row(e.x: A 7)\n";
		
		cin >> pLetter >> pNum;	
	}

	//get destination values
	cout << "Where do you want to move?(e.x: A 4): ";
	cin >> dLetter >> dNum;	
	//validate piece destination input
	while(checkIn(dLetter, dNum) != true){
		cout << "Your selection is invalid.\n"
			    "Choose column, then row(e.x: A 7)\n";
		
		cin >> dLetter >> dNum;	
	}	
	
	

	//Rewritting validation


	//Letters are used to determine the column value on the board
	//Numbers are used to determine the row value on the board

	int pCol = 0,	dCol = 0, 	pRow = 0, 	dRow = 0;		

	pCol = processLetter(pLetter);
	pRow = processNum(pNum);
	dCol = processLetter(dLetter);
	dRow = processNum(dNum);

	//Declare a ply struct and return it with this turn's information
	
	input.pRow = pRow;
	input.pCol = pCol;
	input.dRow = dRow;
	input.dCol = dCol;

	return input;
	
}

int processLetter(char letter){
	int column;

	if(letter == 'A'){
		column = 9;
	}else if(letter == 'B'){
		column = 16;
	}else if(letter == 'C'){
		column = 23;
	}else if(letter == 'D'){
		column = 30;
	}else if(letter == 'E'){
		column = 37;
	}else if(letter == 'F'){
		column = 44;
	}else if(letter == 'G'){
		column = 51;
	}else if(letter == 'H'){
		column = 58;
	}else{
		column = -1;
	}

	return column;
}


int processNum(int inRow){
	int row = 0;

	if(inRow == 1){
		row = 25;
	}else if(inRow == 2){
		row = 22;
	}else if(inRow == 3){
		row = 19;
	}else if(inRow == 4){
		row = 16;
	}else if(inRow == 5){
		row = 13;
	}else if(inRow == 6){
		row = 10;
	}else if(inRow == 7){
		row = 7;
	}else if(inRow == 8){
		row = 4;
	}else{
		row = -1;
	}

	return row;
}

void turnCheck(int &turnCount, string &player){
	string w = "white", 
		   b = "black";

	if(turnCount % 2 == 0){ //if turnCoount even
		player = b;
		turnCount++;
	}
		//return b;
    else { //if turnCount is odd 
		player = w;
		turnCount++;
		//return w;
	}
	
}

void movePiece (Ply move, Piece blckArr[], Piece whitArr[]){
	
	//If move was made by black player
	if(move.player == "black"){
		//find the piece to be moved with the position row coordinates, and 
		// change the piece's row and col values to reposition it 
		for(int i = 0; i < 16; i++){
			//When piece is found, modify to reposition in array 
			if(blckArr[i].col == move.pCol && blckArr[i].row == move.pRow){
				blckArr[i].row = move.dRow;
				blckArr[i].col = move.dCol;
			}
		}
	}
	//If move was made by white player
	if(move.player == "white"){
		//find the piece to be moved with the position row coordinates, and 
		// change the piece's row and col values to reposition it 
		for(int i = 0; i < 16; i++){
			//When piece is found, modify to reposition in array 
			if(whitArr[i].col == move.pCol && whitArr[i].row == move.pRow){
				whitArr[i].row = move.dRow;
				whitArr[i].col = move.dCol;
			}
		}
	}

	//testing: display that the values were indeed modified
	for(int i = 0; i < 16; i++){
		cout << whitArr[i].row << endl
			 << whitArr[i].col << endl;
			 
	}


}

void clearScreen(){
	for(int i = 0; i < 50; i++){
		cout << endl;
	}
};


string idPiece(Ply move, Piece colorArr[], int &pIndex){
	string pieceID = " ";
	
	//Iterate white piece array and identify the piece by name
	//This is done using position row and col values
	for (int i = 0; i < 16; i++)
	{
		//When piece is found, set pieceID to name of piece
		if(colorArr[i].col == move.pCol && colorArr[i].row == move.pRow){
			pieceID = colorArr[i].name;
			pIndex = i;
		}
	}

	return pieceID;
}

bool legalM(Ply move, Piece whitArr[], Piece blckArr[]){
	bool legal; 				//Will store legality of move
	string pieceName = " ";		//Stores the name of the piece (e.x. Pawn, Queen, etc)
	int pIndex = 0;				//Stores index of piece in array, used to mod piece

	if(move.player == "white"){
		pieceName = idPiece(move, whitArr, pIndex); //Get piece name, also sets value of pIndex 
	}
	if(move.player == "black"){
		pieceName = idPiece(move, blckArr, pIndex); //Get piece name, also sets value of pIndex 
	}	

	//Depending on piece name and color, certain restrictions to moving are applied
	//these are defined by the piece logic functions below (e.x. pawnLogic)...
	if(pieceName == "Pawn"){
		legal = pwnLogic(move, whitArr, blckArr, pIndex);
	}

	return legal;
}

bool pwnLogic(Ply move, Piece whitArr[], Piece blckArr[], int pIndex){
	bool legalPly;
	int i = pIndex;
	//If pawn is white and has not moved yet
	if(move.player == "white" && whitArr[i].firstT == false)
	{
		//if statement is true move is legal
		if(move.dRow == move.pRow - 3 || move.dRow == move.pRow - 6){
			legalPly = true; 
		}else{//move is false
			legalPly = false;
		}
	}
	//If pawn is black and has not moved yet
	if(move.player == "black" && blckArr[i].firstT == false)
	{
		//if statement is true move is legal
		if(move.dRow == move.pRow + 3 || move.dRow == move.pRow + 6){
			legalPly = true; 
		}else{
			legalPly = false;
		}
	}
	//If pawn is white and has moved once
	if(move.player == "white" && whitArr[i].firstT == true)
	{
		//if statement is true move is legal
		if(move.dRow == move.pRow - 3){
			legalPly = true; 
		}else{
			legalPly = false;
		}
	}//else the pawn is attemping to capture... code is yet to be written for this	*******************

	//If pawn is black and has moved once
	if(move.player == "black" && blckArr[i].firstT == true)
	{
		//if statement is true move is legal
		if(move.dRow == move.pRow - 3){
			legalPly = true; 
		}else{
			legalPly = false;
		}
	}//else the pawn is attemping to capture... code is yet to be written for this	******************
	return legalPly;
}

//add knight logic here

//Check input for piece selection and destination, used in get ply function
bool checkIn(char letter, int number){
	bool valid;
	//Validates letter input for column selection 
	if(letter < 'A' || letter > 'H'){
		valid = false; 
	}else{
		valid = true;
	}
	
	//validate number input for row selection
	if(number < 1 || number > 8){
		valid = false;
	}else{
		valid = true;
	}

	return valid;
}