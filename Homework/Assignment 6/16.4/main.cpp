/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: antero
 *
 * Created on May 30, 2021, 11:16 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

template <typename T>
T AbsoluteValue(const T& value);

int main(int argc, char** argv) {

    int intValue1 = -4, intValue2 = 5;
    double doubleValue1 = 2.56, doubleValue2 = -23.9;

    int absoluteIntValue1 = AbsoluteValue(intValue1);
    int absoluteIntValue2 = AbsoluteValue(intValue2);
    double absoluteDoubleValue1 = AbsoluteValue(doubleValue1);
    double absoluteDoubleValue2 = AbsoluteValue(doubleValue2);

    cout << "Type: int\n";
    cout << "Value = " << intValue1 << ", absolute value = " << absoluteIntValue1 << endl;
    cout << "Value = " << intValue2 << ", absolute value = " << absoluteIntValue2 << "\n\n";

    cout << "Type: double\n";
    cout << "Value = " << doubleValue1 << ", absolute value = " << absoluteDoubleValue1 << endl;
    cout << "Value = " << doubleValue2 << ", absolute value = " << absoluteDoubleValue2 << "\n\n";

    return 0;
}

template <typename T>
T AbsoluteValue(const T& value)
{
	return value < 0 ? -value : value;
}
