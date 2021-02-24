/* 
 * File:        	main.cpp
 * Author:      	Antero Avalos
 * Date Created:    	02/22/2021 11:17 am
 * Date Finished:       02/22/2021 1:25 pm
 * Purpose:     	Geometry Calculator
 *                      
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

//Function Prototypes
float areaCir();    //Calculates the area of a circle from given radius. 
float areaRec();    //Calculates the area of a rectangle from given length and width
float areaTri();    //Calculates the area of a triangle from given base and height

int main(int argc, char** argv) {
    
    bool exit = false;  //Boolean to exit the do-while loop
    int choice;         //Stores user menu selection, used in switch
    float result;       //Stores returned area from respective calculating function
    
    //Do while loop which contains the calculator process
    do{
        //Display menu
        cout << "Geometry Calculator" << endl
                << "\t1.Calculate the Area of a Circle.\n"
                << "\t2.Calculate the Area of a Rectangle\n"
                << "\t3.Calculate the Area of a Triangle\n"
                << "\t4.Quit\n"
             << "Enter your choice (1-4):  ";
        cin >> choice;
        
        if(choice >= 1 && choice <= 4){
            //Process the user input for menu selection
            switch(choice) {
                case 1:
                    result = areaCir();
                    if(result > 0){
                        cout << "The area of your circle is " << result << " ." << endl;
                    }
                    break;
                case 2: 
                    result = areaRec();
                    if(result > 0){
                        cout << "The area of your rectangle is " << result << " ." << endl;
                    }
                    break;
                case 3:
                    result = areaTri();
                    if(result > 0){
                        cout << "The area of your triangle is " << result << " ." << endl;
                    }              
                    break;
                case 4:
                    exit = true;
                    break;
            }
        }else{
            cout << "Please make a valid selection (1-4).";
        };
        
            
        
    }while(exit != true);
    
    
    
    //Exit the Program - Cleanup
    return 0;
}


//Function definitions

//Calculates the area of a circle from given radius. 
float areaCir(){
    float rad, area;     //Radius and circle area
    
    bool okData = false; //Boolean to exit the input validation loop below
    
    //Input validation loop where the result is release after adequate data is given 
    do {
        cout << "Please enter the circle radius: " << endl; 
        cin >> rad;
        if(rad < 0){        //Validation of radius value
            cout << "Enter a valid radius value(greater than 0).\n\n";
        }else{
            area = (rad * rad) * 3.14159;
            okData = true;
        }; 
    }while(okData != true);
    
    return area;
};           

//Calculates the area of a rectangle from given length and width
float areaRec(){
    float length, width, area; //Variables needed to calculate the area, and area itself
    bool okData = false; //Boolean to exit the input validation loop below    
    
    //Input validation loop where the result is released after adequate data is confirmed 
    do {
        cout << "Enter rectangle length: ";
        cin >> length;
        
        if(length < 0){        
            cout << "Enter a valid length value(greater than 0).\n\n";
        }else{
            
            bool okWidth = false;
            do{
                cout << "Enter rectangle width: "; 
                cin >> width;
                if(width < 0){
                    cout << "Enter a valid width (greater than 0).\n\n"; 
                }else{
                    area = width * length;
                    okWidth = true;
                }
            }while(okWidth != true);
            okData = true;             
        }; 
    }while(okData != true);              
    
    return area;
};    

//Calculates the area of a circle from given base and height
float areaTri(){
    float base, height, area; //Variables needed to calculate the area, and area itself
    bool okData = false; //Boolean to exit the input validation loop below    
    //Input validation loop where the result is released after adequate data is confirmed 
    do {
        cout << "Enter triangle base: ";
        cin >> base;
        
        if(base < 0){        
            cout << "Enter a valid base value(greater than 0).\n\n";
        }else{
            
            bool okHeigt = false;
            do{
                cout << "Enter triangle height: "; 
                cin >> height;
                if(height < 0){
                    cout << "Enter a valid height(greater than 0).\n\n"; 
                }else{
                    area = (base * height) / 2; 
                    okHeigt = true;
                }
            }while(okHeigt != true);
            okData = true;             
        }; 
    }while(okData != true);          
    
    return area; 
};    