/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Customer.h
 * Author: Antero
 *
 * Created on October 19, 2020
 */

#ifndef CUSTOMER_H
#define CUSTOMER_H

struct Customer{

    string name;        //customer name
    string address;     //customer address
    int acctNum;        //account number
    float initBal;      //initial account balance this month
    float spent;        //amount spent this month
    float dposits;      //amount deposited to account this month 
    float newBal;       //updated balance for the month
    bool  odChrge;      //shows if account was charged "overdraw fee"
};


#endif

