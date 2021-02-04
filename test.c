//
// Created by Aditi Rajnish on 2020-09-07.
//

#include <stdio.h>

int main(){

    int value = 0;
    int *pValue = &value;

    printf("Enter an integer: ");
    scanf("%i", pValue);

    printf("You entered %i.\n", value);

    return 0;
}