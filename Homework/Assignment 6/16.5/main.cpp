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
T total(size_t amountOfValues);

int main(int argc, char** argv) {

    cout << "Type: int. Amount of Values = 3\n";
    int sum1 = total<int>(3);
    cout << "Sum = " << sum1 << endl;

    cout << "Type: double. Amount of Values = 2\n";
    double sum2 = total<double>(2);
    cout << "Sum = " << sum2 << endl;

    return 0;
}

template <typename T>
T total(size_t amountOfValues)
{
	T sum = 0;
	T value;

	do
	{
		cout << "Enter value: ";
		cin >> value;
		sum += value;

	} while (--amountOfValues > 0);

	return sum;
}