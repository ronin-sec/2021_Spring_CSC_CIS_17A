/* 
 * File:   Strutures Movie Data 
 * Author: Antero Avalos
 * Created on 04/05/2021
 * Purpose:  Homework
 */


#include <iostream>
#include <string>
using namespace std;

//Structure Declaration
struct MovieData
{
    //member variables
    string title;
    string director;
    int releaseYear;
    int length;

};

//Function Prototypes
//function to write input into filmArr structs 
//function to 

//------------------------------------------MAIN-------------------------------
int main(){
	//Variable declarations
    int nFilms;          //Number of fils that will be recorded
    MovieData * filmArr; //Pointer to dynamic film array

    //Initial Program outout
    cout <<  "This program reviews structures" << endl;
    cout << "Input how many movies, the Title of the Movie, Director,"
            " Year Released, and the Running Time in (minutes)." << endl;

    cin >> nFilms;  //Get number of films

    filmArr = new MovieData[nFilms]; //Allocate dynamic array

    //write input to \corresponding struture members
    for (int i = 0; i < nFilms; i++)
    {
        cin.ignore();
        getline(cin, filmArr[i].title);
        getline(cin, filmArr[i].director);
        cin >> filmArr[i].releaseYear;
        cin >> filmArr[i].length;
    }

    //Outout structure data of all films
    for (int i = 0; i < nFilms; i++)
    {
        cout << endl;
        cout << "Title:     " << filmArr[i].title << endl
             << "Director:  " << filmArr[i].director << endl
             << "Year:      " << filmArr[i].releaseYear << endl
             << "Length:    " << filmArr[i].length << endl;
    }
    
	return 0;
}
//------------------------------------end of MAIN------------------------------