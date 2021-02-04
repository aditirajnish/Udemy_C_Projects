//
// Created by Aditi Rajnish on 2020-09-04.
// Reverse a string and sort an array of strings.
//

#include <stdio.h>
#include <string.h>

void reverseString(const char string[]);
void sortStrings(void);

int stringFunctions(){
    const char test1[] = "abc";
    reverseString(test1);

    sortStrings();

    return 0;
}

void reverseString(const char string[]){
    int length = strlen(string);
    char reversed[length + 1];
    int i = 0;
    for(; i <= length; i++){
        reversed[i] = string[length - 1 - i];
    }
    reversed[i] = '\0';

    printf("Reversed \"%s\" to \"%s\".\n", string, reversed);
}

void sortStrings(void){

    char strings[25][50], temp[50];
    int numberOfStrings;

    printf("Enter number of strings to sort: ");
    scanf("%d", &numberOfStrings);

    for(int i = 0; i < numberOfStrings; i++){
        printf("Enter string %d: ", i + 1);
        scanf("%s", strings[i]);
    }

    _Bool switched = 0;
    while(1){
        for(int i = 0; i < (numberOfStrings - 1); i++){
            if(strcmp(strings[i], strings[i + 1]) > 0){

                strncpy(temp, strings[i + 1], sizeof(temp));
                strncpy(strings[i + 1], strings[i], sizeof(strings[i + 1]));
                strncpy(strings[i], temp, sizeof(strings[i]));

                switched = 1;
            }
        }
        if(!switched){
            break;
        }
        switched = 0;
    }

    printf("Sorted strings are: \n");

    for(int i = 0; i < numberOfStrings; i++){
        printf("%s\n", strings[i]);
    }
}


