/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: anter
 *
 * Created on October 12, 2020, 11:34 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
    int i;
    i=0;
    do
    {
        printf("%d %c \n",i,i);
        i++;
    }
    while(i<=255);
    return 0;
}
