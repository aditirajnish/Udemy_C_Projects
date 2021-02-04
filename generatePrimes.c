//
// Created by Aditi Rajnish on 2020-08-22.
// Find all of the primes up to 100.
//

#include <stdio.h>
#include <math.h> // performs exponent operation

int generatePrimes(){

    // initialize array of primes, start with the primes 2 and 3
    int primes[50] = {2, 3};

    // length of primes array
    int lengthOfPrimes = 2;

    // loop through all odd integers from 5 to 100, increment by 2
    for(int i = 5; i <= 100; i += 2){

        // loop through all primes in primes array
        for(int j = 0; j < lengthOfPrimes; j++){

            // if i is divisible by a prime exit inner loop
            // since i is not a prime; return to the outer loop
            if(i % primes[j] == 0){
                break;
            }
            // if a prime is greater than the square root of i, i must be prime;
            // append i to the primes array, increment lengthOfPrimes,
            // exit the inner loop and return to the outer loop
            if(primes[j] > pow(i, 0.5)){
                primes[lengthOfPrimes] = i;
                lengthOfPrimes++;
                break;
            }
        }
    }

    // after all primes are found and appended to the primes array,
    // display all of the primes stored inside of the array
    for(int i = 0; i < lengthOfPrimes; i++){
        printf("%d ", primes[i]);
    }

    return 0;
}