//
// Created by Aditi Rajnish on 2020-08-21.
// Display byte size of several data types.
//

#include <stdio.h>

int byteSize(){

    // use sizeof operator on data type;
    // display each data type size with %zd formatter

    // interesting observations for my system:
    // 1) long and long long store the same number of bytes (8 bytes)
    // 2) the largest size is long double (16 bytes)

    printf("Size of char: %zd bytes.\n", sizeof(char));
    printf("Size of short: %zd bytes.\n", sizeof(short));
    printf("Size of int: %zd bytes.\n", sizeof(int));
    printf("Size of long: %zd bytes.\n", sizeof(long));
    printf("Size of long long: %zd bytes.\n", sizeof(long long));
    printf("Size of float: %zd bytes.\n", sizeof(float));
    printf("Size of double: %zd bytes.\n", sizeof(double));
    printf("Size of long double: %zd bytes.\n", sizeof(long double));
    printf("Size of long long int: %zd bytes.\n", sizeof(long long int));

    return 0;
}
