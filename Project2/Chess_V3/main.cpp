/* 
 * Purpose: Project 1 - Chess
 * File:   main.cpp
 * Author: Antero Avalos
 *
 * Created on May, 2021
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

//User Libraries
#include "Pieces.h"
#include "SaveData.h"

//Constant Expressions 
constexpr auto W_CH = char(0x58); //White char
constexpr auto B_CH = char(0x20); //Black char
constexpr auto G_CH = char(0xB1); //Gray char 
constexpr auto NEW_LINE = char(0x0a); //new line char
constexpr auto SPACE = char(0x20); //Space

//Function Prototypes
char** makeBoard_V2(int, int,Piece [],Piece[]);     //Generates board using 2d array, pieces and board
void prntBoard_V2(char**, int, int);                //Print board
void writeLetters(char**, Piece [], Piece []);      //Write letters to board array
void writePatterns(char**);                         //Write black and white board squares to board array ^
void destroy(char**, int);                          //Unallocate memory

//void writePiece_v2(char**, Piece[]);                //Redesigned write Piece function, modifies values of piece arrays
void writePiece_v3(char**, Piece[]);                //Redesigned write Piece function, modifies values of piece arrays

Ply getPly(string);                                 //Player turn information, used for the movePiece function
int processLetter(char);                            //Used for conversion of user input into board coordinates
int processNum(int);                                //Used for conversion of user input into board coordinates
void turnCheck(int&, string&);                      //Check turnCount variable to see who's turn it is
void movePiece(Ply, Piece[], Piece[]);              //Move piece using ply data
void clearScreen();                                 //Outputs a bunch of newlines to shows the new board
string idPiece(Ply, Piece[], int&);                 //Identifies piece by name, using position coordinates (used by legalM)
bool legalM(Ply , Piece [], Piece []);              //returned value indicates move legality (uses piece logic functions below)
bool pwnLogic(Ply,Piece[],Piece[],int);		    //Checks that move is legal for pawns
bool knightLogic(Ply,Piece[],Piece[],int);          //Checks that move is legal for knights
bool bishopLogic(Ply,Piece[],Piece[],int);          //Checks that move is legal for bishops
bool towerLogic(Ply,Piece[],Piece[],int);           //Checks that move is legal for tower
bool queenLogic(Ply,Piece[],Piece[],int);           //Checks that move is legal for queen pieces 
bool kingLogic(Ply,Piece[],Piece[],int);            //Checks that move is legal for king pieces 
bool checkIn(char, int, int&);                            //Validates user input during getPLy function
bool obstructd(Ply,Piece[],Piece[],int);            //Check for obstructing pieces in a move
void capture  (Ply,Piece[],Piece[],int);            //sets the captured value for a piece when needed
void displayCaps(Ply, Piece[], Piece[], vector<string>&, vector<string>&);


//-----------------------------------------MAIN---------------------------------
int main()
{
        
        setbuf(stdout, NULL); 
        
	//Variables for board size:
	const int BW = 70;	//Board Width
	const int BH = 30;	//Board Height

	//create 2d board arr
	char** board = nullptr;
	
	//struct arrays that contain information for all pieces:
	//Black pieces
	const int paSz = 16; //Piece array size
	//white pieces 
	Piece whiteArr[paSz] = {
		Piece("Pawn", "wP", 1, false, 	22, 9, "white", false),
		Piece("Pawn", "wP", 1, false, 	22, 16, "white", false),
		Piece("Pawn", "wP", 1, false, 	22, 23, "white", false),
		Piece("Pawn", "wP", 1, false, 	22, 30, "white", false),
		Piece("Pawn", "wP", 1, false, 	22, 37, "white", false),
		Piece("Pawn", "wP", 1, false, 	22, 44, "white", false),
		Piece("Pawn", "wP", 1, false, 	22, 51, "white", false),
		Piece("Pawn", "wP", 1, false, 	22, 58, "white", false),
		Piece("King",  "wK", 10,false, 	25, 30, "white", false),
		Piece("Queen", "wQ", 9, false, 	25, 37, "white", false),
		Piece("Knight", "wN", 3, false,      25, 16, "white", false),
		Piece("Knight", "wN", 3, false,      25, 51, "white", false),
		Piece("Bishop","wB", 3, false, 	25, 23, "white", false),
		Piece("Bishop","wB", 3, false, 	25, 44, "white", false),
		Piece("Tower", "wT", 5, false, 	25, 9, "white", false),
		Piece("Tower", "wT", 5, false, 	25, 58, "white", false)
	};
	//black pieces
        Piece blackArr[paSz] = {
		Piece("Pawn", "bP", 1, false, 	7, 9, "black", false),
		Piece("Pawn", "bP", 1, false, 	7, 16, "black", false),
		Piece("Pawn", "bP", 1, false, 	7, 23, "black", false),
		Piece("Pawn", "bP", 1, false, 	7, 30, "black", false),
		Piece("Pawn", "bP", 1, false, 	7, 37, "black", false),
		Piece("Pawn", "bP", 1, false, 	7, 44, "black", false),
		Piece("Pawn", "bP", 1, false, 	7, 51, "black", false),
		Piece("Pawn", "bP", 1, false, 	7, 58, "black", false),
		Piece("King",  "bK", 10,false, 	4, 30, "black", false),
		Piece("Queen", "bQ", 9, false, 	4, 37, "black", false),
		Piece("Knight", "bN", 3, false,  4, 16, "black", false),
		Piece("Knight", "bN", 3, false,  4, 51, "black", false),
		Piece("Bishop", "bB", 3, false,  4, 23, "black", false),
		Piece("Bishop", "bB", 3, false,  4, 44, "black", false),
		Piece("Tower", "bT", 5, false, 	4, 9, "black", false),
		Piece("Tower", "bT", 5, false, 	4, 58, "black", false)
	};
	
        //Piece capture/loss vectors
        vector<string> whiteCaps {}; //Stores all white pieces that have been captured
        vector<string> blackCaps {}; //Stores all black pieces that have been captured

	//display welcome msg 
	cout << "Welcome to Chess_Project 1!" << endl;
	//Start these variables off with the first turn values
	// they get modified as the game goes on 
	int turnCount = 1;
	string player = " ";
	Ply moveData;
        
        /*
        //Testing values of the object arrays
        cout << "White Piece array information: " << endl;
        for(int i = 0; i < 16; i++){    
            cout << whiteArr[i].getName() << " ";
            cout << whiteArr[i].getLetters() << " ";
            cout << whiteArr[i].getCap() << " ";
            cout << whiteArr[i].getRow() << " ";
            cout << whiteArr[i].getCol() << " ";
            cout << endl;
        }

        cout << endl;

        cout << "Black Piece array information: " << endl;
        for(int i = 0; i < 16; i++){    
            cout << blackArr[i].getName() << " ";
            cout << blackArr[i].getLetters() << " ";
            cout << blackArr[i].getCap() << " ";
            cout << blackArr[i].getRow() << " ";
            cout << blackArr[i].getCol() << " ";
            cout << endl;
        }
        */
        
        //Main game loop goes here (TESTING)        
        //Loop contains main game logic
	bool cMate = false; //if no check mate detected...
	do
	{       if(exitCode != 100){
                    //use function to make the board 
                    board = makeBoard_V2(BW, BH, whiteArr, blackArr);

                    //display 2d board arr	
                    prntBoard_V2(board, BW, BH);

                    //check who's turn it is
                    turnCheck(turnCount, player);

                    //display the option to leave game
                    int exitCode = 0;
                    displayLeave();

                    if(player == "white"){
                            cout << "White's Turn. \n";                
                    }else{
                            cout << "Black's Turn: \n";
                    }

                    //display current capture information if applicable
                    displayCaps(moveData, whiteArr, blackArr, whiteCaps, blackCaps);                                

                    //get the corresponding ply data
                    moveData = getPly(player);                             

                    //check if move is legal
                    while(legalM(moveData, whiteArr, blackArr) != true){
                            cout << "Your move selection is not legal!\n" << endl;
                            moveData = getPly(player);
                    }

                    //"move" the piece by updating it's coordinate values in struct array
                    movePiece(moveData, blackArr, whiteArr);

                    /*
                    //Loop to test the value of all captured members in structure array
                    for(int i = 0; i < 16; i++) {
                        if(blackArr[i].captured == true){ //change to whiteArr if needed
                            cout << "Piece #" << i << " = True" << endl;
                        }else{
                            cout << "Piece #" << i << " = False" << endl;
                        }
                    }
                    */

                    clearScreen();
                }else{
                    cout << "Would you like to save the game? " << endl;
                    string saveDec  = getSaveDec();
                    
                    if(saveDec == "yes"){
                        
                        //create a save game data object
                        
                        //call savegame function which creates files with the data
                        
                        cout << "Your game has been saved!" << endl; 
                                                                                                
                        
                    }else{
                        
                        cMate == true; 
                    }
                    
                }
                    
	
	} while (cMate != true);
	
        

	//make sure to unallocate any memory used
	destroy(board, BH);
	return 0;
}
//---------------------------------end of MAIN---------------------------------

//Entire board, along with pieces and letter indexes above and below board are 
//displayed via this function.
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
        
        /*Testing captured piece information display, does not work... 
        //Strins to hold the captured pieces if/when applicable
        string wText = "White Captures: ";
        string bText = "Black Captures: ";
        string whteCaps = " ";
        string blckCaps = " ";          
        
        //iterate arrays to get the captured status of the pieces
        for (int i = 0; i < 16; i++){
            if(blckArr[i].captured == true){ //change to whiteArr if needed
                whteCaps += blckArr[i].letters;
                
                for (int col = 0; col < boardWidth; col++){
		*(*(boardPtr + 1) + col) = wText[col];
                *(*(boardPtr + 2) + col) = whteCaps[col];
                }
                
            }else{
                continue; 
            }
        }
        
        */
        

	return boardPtr;
}
//-----------------------------END---of----MAIN---------------------------------

//-----------FUNCTION-------------DEFINITIONS-----------------------------------

//Checkered pattern on board is created via this function
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

//Using writePiece, writes the letters of all pieces
void writeLetters(char** boardPtr, Piece whitArr[], Piece blckArr[]){
		
    //Using writePiece_V2, modify the Piece arrays of each color as needed, this
    //function only changes the "letters" member of a Piece structure
	writePiece_v3(boardPtr, blckArr);
	writePiece_v3(boardPtr, whitArr);
}

//Re-written version of the write piece that is able to work with 
//the piece class
void writePiece_v3(char** boardPtr, Piece colorArr[]) {
    char emptySquare[] = "   ";
    
    for(int i = 0; i < 16; i++){
        Piece iterPiece = colorArr[i]; //Piece values of current iteration assigned to this placeholder obj
        
        if(iterPiece.getCap() == false){ //If piece has not been  captured, write to board normally 

            for (int j = 0, row = iterPiece.getRow(), col = iterPiece.getCol(); j < 2; j++, col++) {
                string iLetters = iterPiece.getLetters();                   
                //*(*(boardPtr + row) + col) = iLetters[j];						                    
                boardPtr[row][col] = iLetters[j];
            }

        }else{//If piece has a true captured status, it is replaced with empty space on board.

            for (int j = 0, row = iterPiece.getRow(), col = iterPiece.getCol(); j < 2; j++, col++) {                    
                //cout << emptySquare[j];
                //*(*(boardPtr + row) + col) = emptySquare[j];
                boardPtr[row][col] = emptySquare[j];
            }

        }
        
    }
}

//Prints the board, used for initial print and following updates. 
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

//Used to destroy the board (frees the memory used)
void destroy(char** boardPtr, int rows) {
	for (int i = 0; i < rows; i++) {
		delete[] boardPtr[i];
	}
}

//Used to store a player's move information aka "Ply"
Ply getPly(string player){
	Ply input;
	
	if(player == "white"){
		input.player = "white";
	}else{
		input.player = "black";
	}
	
	char pLetter = ' '; //input from position letter 
	int  pNum = 0;		//input from position row
	char dLetter = ' '; //input from destination letter
	int  dNum = 0;		//input from destination row
	
	cout << "\n\n You must enter location of the piece you'd like to move,\n"
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

//Player input processing, needed to turn the player coords into array coords 
int processLetter(char letter){
	int column;

	if(letter == 'A' || letter == 'a'){
		column = 9;
	}else if(letter == 'B' || letter == 'b'){
		column = 16;
	}else if(letter == 'C' || letter == 'c'){
		column = 23;
	}else if(letter == 'D' || letter == 'd'){
		column = 30;
	}else if(letter == 'E' || letter == 'e'){
		column = 37;
	}else if(letter == 'F' || letter == 'f'){
		column = 44;
	}else if(letter == 'G' || letter == 'g'){
		column = 51;
	}else if(letter == 'H' || letter == 'h'){
		column = 58;
	}else{
		column = -1;
	}

	return column;
}

//Player input processing, needed to turn the player coords into array coords 
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

//Used to establish player turn in the main function. 
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

//Uses Ply (move information), and modifies both piece structure arrays accordingly
void movePiece (Ply move, Piece blckArr[], Piece whitArr[]){

	//If move was made by black player
	if(move.player == "black"){
		//find the piece to be moved with the position row coordinates, and 
		// change the piece's row and col values to reposition it 
		for(int i = 0; i < 16; i++){
			//When piece is found, modify to reposition in board
			if(blckArr[i].getCol() == move.pCol && blckArr[i].getRow() == move.pRow){
				//blckArr[i].row = move.dRow;
				//blckArr[i].col = move.dCol;
                                blckArr[i].setCoords(move.dRow, move.dCol);
			}
		}
	}
	//If move was made by white player
	if(move.player == "white"){
		//find the piece to be moved with the position row coordinates, and 
		// change the piece's row and col values to reposition it 
		for(int i = 0; i < 16; i++){
			//When piece is found, modify to reposition in board
			if(whitArr[i].getCol() == move.pCol && whitArr[i].getRow() == move.pRow){
				//whitArr[i].row = move.dRow;
				//whitArr[i].col = move.dCol;
                                whitArr[i].setCoords(move.dRow, move.dCol);
			}
		}
	}
}

//"clears" screen for updated board to be displayed
void clearScreen(){
	for(int i = 0; i < 50; i++){
		cout << endl;
	}
};


//This function is used by legalM 
string idPiece(Ply move, Piece colorArr[], int &pIndex){
	string pieceID = " ";
	
	//Iterate white piece array and identify the piece by name
	//This is done using position row and col values
	for (int i = 0; i < 16; i++)
	{
		//When piece is found, set pieceID to name of piece
		if(colorArr[i].getCol() == move.pCol && colorArr[i].getRow() == move.pRow){
			pieceID = colorArr[i].getName();
			pIndex = i;
		}
	}

	return pieceID;
}

//Analysis of the Ply structure which contains player move information done here 
//Returns boolean that indicates the "legality" of the move
//Modifies pIndex by reference. 
bool legalM(Ply move, Piece whitArr[], Piece blckArr[]){
	bool legal; 				//Will store legality of move
	string pieceName = " ";                 //Stores the name of the piece (e.x. Pawn, Queen, etc)
	int pIndex = 0;				//Stores index of piece in array, used to mod piece

	if(move.player == "white"){
		pieceName = idPiece(move, whitArr, pIndex); //Get piece name, also sets value of pIndex 
	}
	if(move.player == "black"){
		pieceName = idPiece(move, blckArr, pIndex); //Get piece name, also sets value of pIndex 
	}	

	//Depending on piece name, certain restrictions to moving are applied
	//these are defined by the piece logic functions below (e.x. pawnLogic)...
	if(pieceName == "Pawn"){
		legal = pwnLogic(move, whitArr, blckArr, pIndex);
	}
	if(pieceName == "Knight"){
		legal = knightLogic(move, whitArr, blckArr, pIndex);
	}
	if(pieceName == "Bishop"){
		legal = bishopLogic(move, whitArr, blckArr, pIndex);
	}
	if(pieceName == "Tower"){
		legal = towerLogic(move, whitArr, blckArr, pIndex);
	}
	if(pieceName == "Queen"){
		legal = queenLogic(move, whitArr, blckArr, pIndex);
	}
	if(pieceName == "King"){
		legal = kingLogic(move, whitArr, blckArr, pIndex);
	}


	return legal;
}

//The following 6 functions provide the movement logic for all 6 piece types. 

bool pwnLogic(Ply move, Piece whitArr[], Piece blckArr[], int pIndex){
	bool legalPly;
	int i = pIndex;
	//If pawn is white and has not moved yet
	if(move.player == "white" && whitArr[i].getFT() == false)
	{
		//if statement is true move is legal
		if(move.dRow == move.pRow - 3 || move.dRow == move.pRow - 6){
			legalPly = true; 
		}else{//move is false
			legalPly = false;
		}
	}
	//If pawn is black and has not moved yet
	if(move.player == "black" && blckArr[i].getFT() == false)
	{
		//if statement is true move is legal
		if(move.dRow == move.pRow + 3 || move.dRow == move.pRow + 6){
			legalPly = true; 
		}else{
			legalPly = false;
		}
	}
	//If pawn is white and has moved once
	if(move.player == "white" && whitArr[i].getFT() == true)
	{
		//if statement is true move is legal
		if(move.dRow == move.pRow - 3){
			legalPly = true; 
		}else{
			legalPly = false;
		}
	}//else the pawn is attemping to capture... code is yet to be written for this	*******************

	//If pawn is black and has moved once
	if(move.player == "black" && blckArr[i].getFT() == true)
	{
		//if statement is true move is legal
		if(move.dRow == move.pRow - 3){
			legalPly = true; 
		}else{
			legalPly = false;
		}
	}//else the pawn is attemping to capture... code is yet to be written for this	******************

        //If the square that player is trying to move onto is occupied by a piece of same color
        //obstructd will return true, and the move will be illegal 
	if(obstructd(move, whitArr, blckArr, pIndex) == true){
		legalPly = false; 
	}
        
        //do a capture check and modify piece if needed 
        capture(move, whitArr, blckArr, pIndex);
        
	return legalPly;
}

bool knightLogic(Ply move, Piece whitArr[], Piece blckArr[], int pIndex){
	bool legalPly;
	int i = pIndex;
	//The knight has 8 possible moves maximum at any given time
	//This is only true if the all 8 destination coords are within
	//the board. 
        
        //Need to check the boundaries along with the direction 
        
	//If the destination coords match the possible legal areas;
	//Legal ply returns true, else; it is returned false without 
	//being modified
        
	if(move.dRow == (move.pRow - 6) && move.dCol == (move.pCol - 7)){
		legalPly = true;
	}
	if(move.dRow == (move.pRow - 6) && move.dCol == (move.pCol + 7)){
		legalPly = true;
	}
	if(move.dRow == (move.pRow - 3) && move.dCol == (move.pCol - 14)){
		legalPly = true;
	}
	if(move.dRow == (move.pRow - 3) && move.dCol == (move.pCol + 14)){
		legalPly = true;
	}
	if(move.dRow == (move.pRow + 3) && move.dCol == (move.pCol - 14)){
		legalPly = true;
	}
	if(move.dRow == (move.pRow + 3) && move.dCol == (move.pCol + 14)){
		legalPly = true;
	}
	if(move.dRow == (move.pRow + 6) && move.dCol == (move.pCol - 7)){
		legalPly = true;
	}
	if(move.dRow == (move.pRow + 6) && move.dCol == (move.pCol + 7)){
		legalPly = true;
	}

	if(obstructd(move, whitArr, blckArr, pIndex) == true){
		legalPly = false; 
	}
    
        //do a capture check and modify piece if needed 
        capture(move, whitArr, blckArr, pIndex);
        
	return legalPly;
}

bool bishopLogic(Ply move, Piece whitArr[], Piece blckArr[], int pIndex){
	bool legalPly = false;
	int i = pIndex;

	//the bishop moving diagonally means that it will always conform to certain diagonal 
	// movement requirements

	//The are 7 possible values in every direction, hence the many checks... 

	//for diagonal movement in ASCENDING RIGHT direction (row -3 , col +7)
	if(move.dRow == (move.pRow - 3) && move.dCol == (move.pCol + 7)){
		legalPly = true;
	}
	if(move.dRow == (move.pRow  -6) && move.dCol == (move.pCol + 14)){
		legalPly = true;
	}
	if(move.dRow == (move.pRow - 9) && move.dCol == (move.pCol + 21)){
		legalPly = true;
	}
	if(move.dRow == (move.pRow - 12) && move.dCol == (move.pCol + 28)){
		legalPly = true;
	}
	if(move.dRow == (move.pRow - 15) && move.dCol == (move.pCol + 35)){
		legalPly = true;
	}
	if(move.dRow == (move.pRow - 18) && move.dCol == (move.pCol + 42)){
		legalPly = true;
	}
	if(move.dRow == (move.pRow - 21) && move.dCol == (move.pCol + 49)){
		legalPly = true;
	}

	//for diagonal movement in DESCENDING RIGHT direction (row +3 , col +7)
	if(move.dRow == (move.pRow + 3) && move.dCol == (move.pCol + 7)){
		legalPly = true;
	}
	if(move.dRow == (move.pRow + 6) && move.dCol == (move.pCol + 14)){
		legalPly = true;
	}
	if(move.dRow == (move.pRow + 9) && move.dCol == (move.pCol + 21)){
		legalPly = true;
	}
	if(move.dRow == (move.pRow + 12) && move.dCol == (move.pCol + 28)){
		legalPly = true;
	}
	if(move.dRow == (move.pRow + 15) && move.dCol == (move.pCol + 35)){
		legalPly = true;
	}
	if(move.dRow == (move.pRow + 18) && move.dCol == (move.pCol + 42)){
		legalPly = true;
	}
	if(move.dRow == (move.pRow + 21) && move.dCol == (move.pCol + 49)){
		legalPly = true;
	}

	//for diagonal movement in ASCENDING LEFT direction (row -3 , col -7)
	if(move.dRow == (move.pRow - 3) && move.dCol == (move.pCol - 7)){
		legalPly = true;
	}
	if(move.dRow == (move.pRow - 6) && move.dCol == (move.pCol - 14)){
		legalPly = true;
	}
	if(move.dRow == (move.pRow - 9) && move.dCol == (move.pCol - 21)){
		legalPly = true;
	}
	if(move.dRow == (move.pRow - 12) && move.dCol == (move.pCol - 28)){
		legalPly = true;
	}
	if(move.dRow == (move.pRow - 15) && move.dCol == (move.pCol - 35)){
		legalPly = true;
	}
	if(move.dRow == (move.pRow - 18) && move.dCol == (move.pCol - 42)){
		legalPly = true;
	}
	if(move.dRow == (move.pRow - 21) && move.dCol == (move.pCol - 49)){
		legalPly = true;
	}

	//for diagonal movement in DESCENDING LEFT direction (row +3 , col -7)
	if(move.dRow == (move.pRow + 3) && move.dCol == (move.pCol - 7)){
		legalPly = true;
	}
	if(move.dRow == (move.pRow + 6) && move.dCol == (move.pCol - 14)){
		legalPly = true;
	}
	if(move.dRow == (move.pRow + 9) && move.dCol == (move.pCol - 21)){
		legalPly = true;
	}
	if(move.dRow == (move.pRow + 12) && move.dCol == (move.pCol - 28)){
		legalPly = true;
	}
	if(move.dRow == (move.pRow + 15) && move.dCol == (move.pCol - 35)){
		legalPly = true;
	}
	if(move.dRow == (move.pRow + 18) && move.dCol == (move.pCol - 42)){
		legalPly = true;
	}
	if(move.dRow == (move.pRow + 21) && move.dCol == (move.pCol - 49)){
		legalPly = true;
	}

	if(obstructd(move, whitArr, blckArr, pIndex) == true){
		legalPly = false; 
	}
        
        //do a capture check and modify piece if needed 
        capture(move, whitArr, blckArr, pIndex);
        
	return legalPly;
}

bool towerLogic(Ply move, Piece whitArr[], Piece blckArr[], int pIndex){
    bool legalPly = false;
	int i = pIndex;

	//for vertical movement in an UPWARD direction
	if(move.dRow == (move.pRow - 3) && move.pCol == move.dCol){
		legalPly = true;
	}
	if(move.dRow == (move.pRow - 6) && move.pCol == move.dCol){
		legalPly = true;
	}
	if(move.dRow == (move.pRow - 9) && move.pCol == move.dCol){
		legalPly = true;
	}
	if(move.dRow == (move.pRow - 12) && move.pCol == move.dCol){
		legalPly = true;
	}
	if(move.dRow == (move.pRow - 15) && move.pCol == move.dCol){
		legalPly = true;
	}
	if(move.dRow == (move.pRow - 18) && move.pCol == move.dCol){
		legalPly = true;
	}
	if(move.dRow == (move.pRow - 21) && move.pCol == move.dCol){
		legalPly = true;
	}
	
	//for vertical movement in a DOWNWARD direction
	if(move.dRow == (move.pRow + 3) && move.pCol == move.dCol){
		legalPly = true;
	}
	if(move.dRow == (move.pRow + 6) && move.pCol == move.dCol){
		legalPly = true;
	}
	if(move.dRow == (move.pRow + 9) && move.pCol == move.dCol){
		legalPly = true;
	}
	if(move.dRow == (move.pRow + 12) && move.pCol == move.dCol){
		legalPly = true;
	}
	if(move.dRow == (move.pRow + 15) && move.pCol == move.dCol){
		legalPly = true;
	}
	if(move.dRow == (move.pRow + 18) && move.pCol == move.dCol){
		legalPly = true;
	}
	if(move.dRow == (move.pRow + 21) && move.pCol == move.dCol){
		legalPly = true;
	}

	//for horizontal movement in a RIGHTWARD direction
	if(move.pRow == move.dRow && move.dCol == (move.pCol + 7)){
		legalPly = true;
	}
	if(move.pRow == move.dRow && move.dCol == (move.pCol + 14)){
		legalPly = true;
	}
	if(move.pRow == move.dRow && move.dCol == (move.pCol + 21)){
		legalPly = true;
	}
	if(move.pRow == move.dRow && move.dCol == (move.pCol + 28)){
		legalPly = true;
	}
	if(move.pRow == move.dRow && move.dCol == (move.pCol + 35)){
		legalPly = true;
	}
	if(move.pRow == move.dRow && move.dCol == (move.pCol + 42)){
		legalPly = true;
	}
	if(move.pRow == move.dRow && move.dCol == (move.pCol + 49)){
		legalPly = true;
	}

	//for horizontal movement in a LEFTWARD direction
	if(move.pRow == move.dRow && move.dCol == (move.pCol - 7)){
		legalPly = true;
	}
	if(move.pRow == move.dRow && move.dCol == (move.pCol - 14)){
		legalPly = true;
	}
	if(move.pRow == move.dRow && move.dCol == (move.pCol - 21)){
		legalPly = true;
	}
	if(move.pRow == move.dRow && move.dCol == (move.pCol - 28)){
		legalPly = true;
	}
	if(move.pRow == move.dRow && move.dCol == (move.pCol - 35)){
		legalPly = true;
	}
	if(move.pRow == move.dRow && move.dCol == (move.pCol - 42)){
		legalPly = true;
	}
	if(move.pRow == move.dRow && move.dCol == (move.pCol - 49)){
		legalPly = true;
	}

	if(obstructd(move, whitArr, blckArr, pIndex) == true){
		legalPly = false; 
	}
	
        //do a capture check and modify piece if needed 
        capture(move, whitArr, blckArr, pIndex);
        
	return legalPly;
}

bool queenLogic(Ply move, Piece whitArr[], Piece blckArr[], int pIndex){
	bool legalPly = false;
	int i = pIndex;

	//for vertical movement in an UPWARD direction
	if(move.dRow == (move.pRow - 3) && move.pCol == move.dCol){
		legalPly = true;
	}
	if(move.dRow == (move.pRow - 6) && move.pCol == move.dCol){
		legalPly = true;
	}
	if(move.dRow == (move.pRow - 9) && move.pCol == move.dCol){
		legalPly = true;
	}
	if(move.dRow == (move.pRow - 12) && move.pCol == move.dCol){
		legalPly = true;
	}
	if(move.dRow == (move.pRow - 15) && move.pCol == move.dCol){
		legalPly = true;
	}
	if(move.dRow == (move.pRow - 18) && move.pCol == move.dCol){
		legalPly = true;
	}
	if(move.dRow == (move.pRow - 21) && move.pCol == move.dCol){
		legalPly = true;
	}
	
	//for vertical movement in a DOWNWARD direction
	if(move.dRow == (move.pRow + 3) && move.pCol == move.dCol){
		legalPly = true;
	}
	if(move.dRow == (move.pRow + 6) && move.pCol == move.dCol){
		legalPly = true;
	}
	if(move.dRow == (move.pRow + 9) && move.pCol == move.dCol){
		legalPly = true;
	}
	if(move.dRow == (move.pRow + 12) && move.pCol == move.dCol){
		legalPly = true;
	}
	if(move.dRow == (move.pRow + 15) && move.pCol == move.dCol){
		legalPly = true;
	}
	if(move.dRow == (move.pRow + 18) && move.pCol == move.dCol){
		legalPly = true;
	}
	if(move.dRow == (move.pRow + 21) && move.pCol == move.dCol){
		legalPly = true;
	}

	//for horizontal movement in a RIGHTWARD direction
	if(move.pRow == move.dRow && move.dCol == (move.pCol + 7)){
		legalPly = true;
	}
	if(move.pRow == move.dRow && move.dCol == (move.pCol + 14)){
		legalPly = true;
	}
	if(move.pRow == move.dRow && move.dCol == (move.pCol + 21)){
		legalPly = true;
	}
	if(move.pRow == move.dRow && move.dCol == (move.pCol + 28)){
		legalPly = true;
	}
	if(move.pRow == move.dRow && move.dCol == (move.pCol + 35)){
		legalPly = true;
	}
	if(move.pRow == move.dRow && move.dCol == (move.pCol + 42)){
		legalPly = true;
	}
	if(move.pRow == move.dRow && move.dCol == (move.pCol + 49)){
		legalPly = true;
	}

	//for horizontal movement in a LEFTWARD direction
	if(move.pRow == move.dRow && move.dCol == (move.pCol - 7)){
		legalPly = true;
	}
	if(move.pRow == move.dRow && move.dCol == (move.pCol - 14)){
		legalPly = true;
	}
	if(move.pRow == move.dRow && move.dCol == (move.pCol - 21)){
		legalPly = true;
	}
	if(move.pRow == move.dRow && move.dCol == (move.pCol - 28)){
		legalPly = true;
	}
	if(move.pRow == move.dRow && move.dCol == (move.pCol - 35)){
		legalPly = true;
	}
	if(move.pRow == move.dRow && move.dCol == (move.pCol - 42)){
		legalPly = true;
	}
	if(move.pRow == move.dRow && move.dCol == (move.pCol - 49)){
		legalPly = true;
	}
	
	//for diagonal movement in ASCENDING RIGHT direction (row -3 , col +7)
	if(move.dRow == (move.pRow - 3) && move.dCol == (move.pCol + 7)){
		legalPly = true;
	}
	if(move.dRow == (move.pRow  -6) && move.dCol == (move.pCol + 14)){
		legalPly = true;
	}
	if(move.dRow == (move.pRow - 9) && move.dCol == (move.pCol + 21)){
		legalPly = true;
	}
	if(move.dRow == (move.pRow - 12) && move.dCol == (move.pCol + 28)){
		legalPly = true;
	}
	if(move.dRow == (move.pRow - 15) && move.dCol == (move.pCol + 35)){
		legalPly = true;
	}
	if(move.dRow == (move.pRow - 18) && move.dCol == (move.pCol + 42)){
		legalPly = true;
	}
	if(move.dRow == (move.pRow - 21) && move.dCol == (move.pCol + 49)){
		legalPly = true;
	}

	//for diagonal movement in DESCENDING RIGHT direction (row +3 , col +7)
	if(move.dRow == (move.pRow + 3) && move.dCol == (move.pCol + 7)){
		legalPly = true;
	}
	if(move.dRow == (move.pRow + 6) && move.dCol == (move.pCol + 14)){
		legalPly = true;
	}
	if(move.dRow == (move.pRow + 9) && move.dCol == (move.pCol + 21)){
		legalPly = true;
	}
	if(move.dRow == (move.pRow + 12) && move.dCol == (move.pCol + 28)){
		legalPly = true;
	}
	if(move.dRow == (move.pRow + 15) && move.dCol == (move.pCol + 35)){
		legalPly = true;
	}
	if(move.dRow == (move.pRow + 18) && move.dCol == (move.pCol + 42)){
		legalPly = true;
	}
	if(move.dRow == (move.pRow + 21) && move.dCol == (move.pCol + 49)){
		legalPly = true;
	}

	//for diagonal movement in ASCENDING LEFT direction (row -3 , col -7)
	if(move.dRow == (move.pRow - 3) && move.dCol == (move.pCol - 7)){
		legalPly = true;
	}
	if(move.dRow == (move.pRow - 6) && move.dCol == (move.pCol - 14)){
		legalPly = true;
	}
	if(move.dRow == (move.pRow - 9) && move.dCol == (move.pCol - 21)){
		legalPly = true;
	}
	if(move.dRow == (move.pRow - 12) && move.dCol == (move.pCol - 28)){
		legalPly = true;
	}
	if(move.dRow == (move.pRow - 15) && move.dCol == (move.pCol - 35)){
		legalPly = true;
	}
	if(move.dRow == (move.pRow - 18) && move.dCol == (move.pCol - 42)){
		legalPly = true;
	}
	if(move.dRow == (move.pRow - 21) && move.dCol == (move.pCol - 49)){
		legalPly = true;
	}

	//for diagonal movement in DESCENDING LEFT direction (row +3 , col -7)
	if(move.dRow == (move.pRow + 3) && move.dCol == (move.pCol - 7)){
		legalPly = true;
	}
	if(move.dRow == (move.pRow + 6) && move.dCol == (move.pCol - 14)){
		legalPly = true;
	}
	if(move.dRow == (move.pRow + 9) && move.dCol == (move.pCol - 21)){
		legalPly = true;
	}
	if(move.dRow == (move.pRow + 12) && move.dCol == (move.pCol - 28)){
		legalPly = true;
	}
	if(move.dRow == (move.pRow + 15) && move.dCol == (move.pCol - 35)){
		legalPly = true;
	}
	if(move.dRow == (move.pRow + 18) && move.dCol == (move.pCol - 42)){
		legalPly = true;
	}
	if(move.dRow == (move.pRow + 21) && move.dCol == (move.pCol - 49)){
		legalPly = true;
	}
	
	if(obstructd(move, whitArr, blckArr, pIndex) == true){
		legalPly = false; 
	}

        //do a capture check and modify piece if needed 
        capture(move, whitArr, blckArr, pIndex);
        
	return legalPly;
}

bool kingLogic(Ply move, Piece whitArr[], Piece blckArr[], int pIndex){
	bool legalPly = false;
	int i = pIndex;

	//for vertical movement in an UPWARD direction
	if(move.dRow == (move.pRow - 3) && move.pCol == move.dCol){
		legalPly = true;
	}

	//for vertical movement in a DOWNWARD direction
	if(move.dRow == (move.pRow + 3) && move.pCol == move.dCol){
		legalPly = true;
	}

	//for horizontal movement in a RIGHTWARD direction
	if(move.pRow == move.dRow && move.dCol == (move.pCol + 7)){
		legalPly = true;
	}

	//for horizontal movement in a LEFTWARD direction
	if(move.pRow == move.dRow && move.dCol == (move.pCol - 7)){
		legalPly = true;
	}

	//for diagonal movement in ASCENDING RIGHT direction (row -3 , col +7)
	if(move.dRow == (move.pRow - 3) && move.dCol == (move.pCol + 7)){
		legalPly = true;
	}

	//for diagonal movement in ASCENDING LEFT direction (row -3 , col -7)
	if(move.dRow == (move.pRow - 3) && move.dCol == (move.pCol - 7)){
		legalPly = true;
	}

	//for diagonal movement in DESCENDING RIGHT direction (row +3 , col +7)
	if(move.dRow == (move.pRow + 3) && move.dCol == (move.pCol + 7)){
		legalPly = true;
	}

	//for diagonal movement in DESCENDING LEFT direction (row +3 , col -7)
	if(move.dRow == (move.pRow + 3) && move.dCol == (move.pCol - 7)){
		legalPly = true;
	}
	
	if(obstructd(move, whitArr, blckArr, pIndex) == true){
		legalPly = false; 
	}

        //do a capture check and modify piece if needed 
        capture(move, whitArr, blckArr, pIndex);
        
	return legalPly;
}

//Check input for piece selection and destination, used in get ply function
// This function does input validation
bool checkIn(char letter, int number, int &exitCode){
	bool valid;
        if(letter == 'x' || letter == 'X'){
                valid = true;
                exitCode = 100;
        }
        
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

// Checks that the square you move to is not occupied by a piece of the same color.
bool obstructd(Ply move, Piece whitArr[], Piece blckArr[], int pIndex){
    bool obstructed = false; 

    Piece pDataM; 	//Stores information of piece being moved
    Piece pDataWh; 	//Store information of white piece iterated 
    Piece pDataBl; 	//Store information of black piece iterated 

    //does the obstruction check for white pieces
    if(move.player == "white"){
            pDataM = whitArr[pIndex];	//this is the moving piece
            for(int i = 0; i < 16; i++){
                    pDataWh = whitArr[i];   //this is the iterated piece 

                    if(i == pIndex){
                            continue; //Skip iteration that would compare moving piece with itself
                    }
                    if((move.dRow == pDataWh.getRow()) && (move.dCol == pDataWh.getCol())){
                            obstructed = true;
                    }
            } 
    }

    //does the obstruction check for black pieces
    if(move.player == "black"){
            pDataM = blckArr[pIndex];	//this is the moving piece
            for(int i = 0; i < 16; i++){
                    pDataBl = blckArr[i];  //this is the iterated piece 

                    if(i == pIndex){
                            continue; //Skip iteration that would compare moving piece with itself
                    }
                    if((move.dRow == pDataBl.getRow()) && (move.dCol == pDataBl.getCol())){
                            obstructed = true;
                    }
            } 
    }


    

    return obstructed; //true if obstruction exists, false if it doesn't 
}

//Capture function, should be called after obstruction check 
//Similar to the obstructed function, it checks for pieces that are located 
//at the destination coordinates, but it checks for pieces that are the adversary color
//if it finds an "enemy" piece, it modifies it's captured boolean member variable 
//to true. By doing this, the piece is not displayed on the board anymore. 
void capture(Ply move, Piece whitArr[], Piece blckArr[], int pIndex){
    
    Piece pDataM; 	//Stores information of piece being moved
    Piece pDataWh; 	//Store information of white piece iterated 
    Piece pDataBl; 	//Store information of black piece iterated 

    //does the capture check for white pieces
    if(move.player == "white"){
            pDataM = whitArr[pIndex];	//this is the moving piece (White)
            for(int i = 0; i < 16; i++){
                    pDataBl = blckArr[i];   //this is the iterated piece (Black)
       
                    if((move.dRow == pDataBl.getRow()) && (move.dCol == pDataBl.getCol())){
                        blckArr[i].setCap(true); //capture status modified 
                        //blckArr[i].col = 0 ;
                        //blckArr[i].row = 0 ;
                        blckArr[i].setCoords(0, 0);
                    }
            } 
    }

    //does the capture check for black pieces
    if(move.player == "black"){
            pDataM = blckArr[pIndex];	//this is the moving piece (Black)
            for(int i = 0; i < 16; i++){
                    pDataWh = whitArr[i];   //this is the iterated piece (White)
       
                    if((move.dRow == pDataWh.getRow()) && (move.dCol == pDataWh.getCol())){
                        pDataWh.setCap(true); //capture status modified 
                        //whitArr[i].setRow(0);
                        //whitArr[i].setCol(0);
                        pDataWh.setCoords(0, 0);
                    }
            } 
    }
    
    
    //delete pDataBl, pDataM, pDataWh; //free the mem used for the 3 piece pointers created above
    
    return;
}

//Display pieces that player has lost and those they have captured
//Used within do-while loop in Main function
void displayCaps(Ply move, Piece whitArr[], Piece blckArr[], vector<string> &wCaps, vector<string> &bCaps){
    
    //Check both Piece arrays to see if any pieces have been captured
    
    
    bool whiteHasCaps = false; 
    bool blackHasCaps = false;
    
    for(int i = 0; i < 16; i++){
        if(whitArr[i].getCap() == true){
            whiteHasCaps = true; 
        }
        if(blckArr[i].getCap() == true){
            blackHasCaps = true; 
        }
    }   
    
    //Assign all current values of captures to capture vectors
    
    //White capture vector
    //First we clear vector of previous information on captures, so it can be updated
    wCaps.clear();
    
    for(int i =0 ; i < 16 ; i++){                                                        
        if(whitArr[i].getCap() == false){      //Skip piece if not captured                             
            continue; 
        }else if(whitArr[i].getCap() != false){ //If captured write to vector                     
            wCaps.push_back(whitArr[i].getLetters());
        }
    }
    
    //Black capture vector
    //First we clear vector of previous information on captures, so it can be updated
    bCaps.clear();
    
    for(int i =0 ; i < 16 ; i++){                                                        
        if(blckArr[i].getCap() == false){     //Skip piece if not captured               
            continue; 
        }else if(blckArr[i].getCap() != false){ //If captured write to vector            
            bCaps.push_back(blckArr[i].getLetters());
        }
    }
    
    if(move.player == "black"){
        cout << "These are the pieces you have lost: ";
        for(int i = 0 ; i < wCaps.size(); i++){
            cout << wCaps[i] << " ";
        }
        cout << "\nThese are the pieces you have captured: ";
        for(int i = 0 ; i < bCaps.size(); i++){
            cout << bCaps[i] << " ";
        }
    }
        
    
    if(move.player == "white"){
        cout << "These are the pieces you have lost: ";
        for(int i = 0 ; i < bCaps.size(); i++){
            cout << bCaps[i] << " ";
        }
        cout << "\nThese are the pieces you have captured: ";
        for(int i = 0 ; i < wCaps.size(); i++){
            cout << wCaps[i] << " ";
        }
    }        
    
    return;
}

//create a save-game data object for a particular piece color
SaveData createSave(string name, Piece colorArr[]){
    SaveData arrayInfo = SaveData(name, colorArr[]);
    
}

//Used to create a save-game file which holds the current game data
void saveGame( SaveData dataObject, string fileName, fstream stream){
    
    fstream stream(fileName, ios::out | ios::binary);
    
     
    
}

//
void displayLeave (){
    cout << "Enter 'X' or 'x' at anytime to exit the game. "<< endl;       
}

//
string getSaveDec(){
    string decision;
    
    cin >> decision;
    
    return decision;
}