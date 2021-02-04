//
// Created by Aditi Rajnish on 2020-08-26.
// Implement three functions to use on char arrays
// (a.k.a. strings): strlen(), strcat(), and strcmp().
//

#include <stdio.h>
#include <string.h>

int stringLength(const char string[]);
void concatenate(char result[], const char str1[], const char str2[]);
_Bool stringEqual(const char str1[], const char str2[]);


int understandingCharArrays(){
    const char test1[20] = "My name is ";
    printf("Length of \"%s\" is %d.\n", test1, stringLength(test1));
    printf("strlen(\"%s\") = %d\n\n", test1, strlen(test1));

    const char test2[] = "Molly";
    char result[20];
    concatenate(result, test1, test2);
    printf("strcat(test1, test2) is \"%s\".\n\n", strcat(test1, test2));

    _Bool equal = stringEqual(test1, test2);
    printf("\"%s\" is %s to \"%s\".\n", test1, equal ? "equal" : "not equal", test2);
    printf("strcmp(test1, test2) is %d.\n", strcmp(test1, test2));

    return 0;
}


int stringLength(const char string[]){
    int count = 0;
    while(string[count] != '\0'){
        count++;
    }
    return count;
}

void concatenate(char result[], const char str1[], const char str2[]){
    int index = 0;
    while(str1[index] != '\0'){
        result[index] = str1[index];
        index++;
    }

    int length = index;
    index = 0;
    while(str2[index] != '\0'){
        result[index + length] = str2[index];
        index++;
    }

    result[index + length] = '\0';
    printf("The resulting string is \"%s\".\n", result);
}

_Bool stringEqual(const char str1[], const char str2[]){
    _Bool equal = 1;
    int i = 0;

    for(; i < stringLength(str1); i++){
        if(str1[i] != str2[i]){
            equal = 0;
        }
    }

    if(str1[i] != str2[i] && str1[i] == '\0'){
        equal = 0;
    }

    return equal;
}