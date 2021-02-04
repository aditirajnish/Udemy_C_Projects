//
// Created by Aditi Rajnish on 2020-08-21.
// Convert minutes into years and days.
//

#include <stdio.h>

int minuteConversion(){

    // declare minutes from user; prevent overflow w/ long long int
    long long int minutesEntered;

    // use type double to retain decimal portions after operations
    double years = 0, days = 0, leftoverMinutes = 0;

    // calculate number of minutes in a day and a year;
    // store in variables of type double (retain decimals)
    double dayMinutes = 24 * 60, yearMinutes = dayMinutes * 365;

    // get number of minutes from user
    printf("Enter the number of minutes: ");
    scanf("%lld", &minutesEntered);

    // calculate number of years
    years = minutesEntered / yearMinutes;

    // handle three scenarios for calculation of days

    // scenario 1: more than 1 year
    if(years > 1) {

        // get leftover fraction of year and convert to minutes
        leftoverMinutes = (years - (int) years) * yearMinutes;

        // convert leftover fraction into days
        days = leftoverMinutes / dayMinutes;

    }

    // scenario 2: less than 1 year
    if(years < 1){

        // set years equal to 0
        years = 0;

        // convert minutes into days
        days = minutesEntered / dayMinutes;
    }

    // scenario 3: equal to 1 year
    // do not calculate number of days

    // display final conversion of minutes into years and days,
    // with years converted to int (decimal portion converted to days)
    // and days rounded to the nearest integer
    printf("%lld minute(s) equals about %d year(s) and %.lf day(s).", minutesEntered, (int) years, days);

    return 0;
}