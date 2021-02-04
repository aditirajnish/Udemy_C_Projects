//
// Created by Aditi Rajnish on 2020-08-20.
// Gets width and height from command line to calculate
// the area and perimeter of a rectangle.
//
// Can select Run > Edit Configurations > Program arguments
// to input command line arguments.
//

#include <stdlib.h>
#include <stdio.h>

int rectangle(int argc, char *argv[]){

    // declare variables
    double width, height, perimeter, area;

    // two ways of reading command line arguments:
    // 1) use sscanf(argv[n], %formatter, &variable)
    // 2) use variable = atof(argv[n])

    /* method 1) initializes width and height via sscanf:
    sscanf(argv[1], "%lf", &width);
    sscanf(argv[2], "%lf", &height);
     */

    // method 2) initializes width and height via atof:
    width = atof(argv[1]);
    height = atof(argv[2]);

    // output width and height
    printf("Height: %lf; Width: %lf\n", width, height);

    // calculate perimeter and area
    perimeter = (width + height) * 2;
    area = width * height;

    // output perimeter and area, rounded to 1 decimal place
    printf("The perimeter is %.1lf.\n", perimeter);
    printf("The area is %.1lf.\n", area);

    return 0;
}