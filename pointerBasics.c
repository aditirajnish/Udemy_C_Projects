//
// Created by Aditi Rajnish on 2020-09-04.
// Demonstrate pointer basics:
// initialize pointer as NULL,
// assign address of int to pointer,
// and display address of pointer, value of pointer,
// and value that pointer points to.
//

#include <stdio.h>

int pointerBasics(){

    int num = 250;
    int *pNum = NULL;

    pNum = &num;

    printf("Address of int: %p\n", &num);
    printf("Address of pointer: %p\n", &pNum);
    printf("Value of pointer: %p\n", pNum);
    printf("Pointer points to: %i\n", *pNum);

    return 0;
}
