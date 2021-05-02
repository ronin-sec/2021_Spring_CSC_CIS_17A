
/* 
 * File:   Primes.h
 * Author: Antero
 *
 * Created on October 20, 2020
 */

#ifndef PRIMES_H
#define PRIMES_H

struct Prime{
	unsigned short prime;   //Prime number
	unsigned char power;    //Exponent to reach given value
};


struct Primes{
	unsigned char nPrimes;  //Size of the array of primes
	Prime *prime;           //Pointer to array of primes
};

#endif /* PRIMES_H */