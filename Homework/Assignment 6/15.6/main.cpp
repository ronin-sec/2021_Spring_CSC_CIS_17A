/*
 * 6. Essay class

Design an Essay class that is derived from the GradedActivity class presented in this
chapter. The Essay class should determine the grade a student receives on an essay.
The student’s essay score can be up to 100, and is determined in the following manner:
•
•
•
•
Grammar: 30 points
Spelling: 20 points
Correct length: 20 points
Content: 30 points
Demonstrate the class in a simple program.

 */

/* 
 * File:   main.cpp
 * Author: antero
 *
 * Created on May 30, 2021
 */

#include <cstdlib>
#include <iostream>
#include "Essay.h"

using namespace std;

int main()
{
	Essay essay;

        cout << "Essay score calculator: " << endl << endl;
        
        cout << "Enter grammar points: ";
        int gramP;
        cin >> gramP;
        
        cout << "Enter spelling points: " << endl;
        int spellP;
        cin >> spellP;
        
        cout << "Enter correct length points: " << endl;
        int clP;
        cin >> clP;
        
        cout << "Enter content points: " << endl;
        int contP;
        cin  >> contP;
        
	essay.GrammarPoints(gramP);
	essay.SpellingPoints(spellP);
	essay.CorrectLengthPoints(clP);
	essay.ContentPoints(contP);

	cout << "Total score from you input: " << essay.getScore() << endl;
	cout << "Grade:                      " << essay.getLetterGrade() << endl;

	return 0;
}