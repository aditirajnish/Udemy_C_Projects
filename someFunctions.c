//
// Created by Aditi Rajnish on 2020-08-23.
// Define and test three separate functions:
// a greatest common denominator function,
// an absolute value function, and a square root function.
//

#include <stdio.h>
#include <math.h>

// recursively calculates GCD of two integer arguments;
// returns GCD (integer)
int greatestCommonDenominator(int a, int b){
    if(a % b == 0){
        return b;
    }
    return greatestCommonDenominator(b, a % b);
}

// returns absolute value of argument;
// accepts and returns float
float absoluteValue(float number){
    float abs = number;
    if(number < 0){
        abs *= (-1);
    }
    return abs;
}

// returns square root of argument;
// if float argument is positive, returns square root;
// otherwise, prints error message and returns -1.0
float squareRoot(float number){
    if(number < 0){
        printf("You cannot compute the square root of a negative number.\n");
        return -1.0;
    }
    return sqrt(number);
}

// testing out each of the above functions;
// displaying arguments and returned values
int someFunctions(){
    int num1 = 240, num2 = 83;
    int gcd = greatestCommonDenominator(num1, num2);
    printf("GCD of %d and %d: %d\n", num1, num2, gcd);

    float num3 = -10.2;
    float abs = absoluteValue(num3);
    printf("Absolute value of %f: %f\n", num3, abs);

    float num4 = 25;
    float root = squareRoot(num4);
    printf("Square root of %f: %f\n", num4, root);
    return 0;
}