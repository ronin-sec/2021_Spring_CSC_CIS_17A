/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Antero Avalos
 *
 * Created on May 30, 2021
 */

#include <cstdlib>
#include <iostream>

using namespace std;

template <typename T>
T minimum(const T& first, const T& second);

template <typename T>
T maximum(const T& first, const T& second);

int main(int argc, char** argv) {

    int intValue1 = 5, intValue2 = 10;
    int intMax = minimum(intValue1, intValue2);

    cout << "Type: int\n";
    cout << "Value1 = " << intValue1 << endl;
    cout << "Value2 = " << intValue2 << endl;
    cout << "Min    = " << intMax << endl;

    double doubleValue1 = 2.35, doubleValue2 = 6.43;
    double doubleMax = maximum(doubleValue1, doubleValue2);

    cout << "Type: double\n";
    cout << "Value1 = " << doubleValue1 << endl;
    cout << "Value2 = " << doubleValue2 << endl;
    cout << "Max    = " << doubleMax << endl;

    return 0;
}

template <typename T>
T minimum(const T& first, const T& second)
{
	return first < second ? first : second;
}

template <typename T>
T maximum(const T& first, const T& second)
{
	return first > second ? first : second;
}