//
// Created by Aditi Rajnish on 2020-08-23.
// Given rainfall data for each month for 5 years, calculate and display
// the total rainfall for each year, the average yearly rainfall
// for all 5 years, and the average monthly rainfall for all 5 years.
//

#include <stdio.h>

int weather(){

    // initializing 2D array for rainfall amounts;
    // 5 rows (years) and 12 columns (months)
    float rainfallAmounts[5][12] =
            {
                {6.5, 7.3, 9.8, 10.4, 9.6, 7.6, 5.7, 4.5, 6.7, 8.9, 9.0, 11.4}, // Year One
                {4.9, 2.6, 5.8, 7.0, 8.6, 7.2, 6.7, 2.5, 6.4, 7.2, 10.0, 11.1}, // Year Two
                {6.5, 7.3, 9.8, 10.4, 9.6, 7.6, 5.7, 4.5, 6.7, 8.9, 9.0, 11.4}, // Year Three
                {4.9, 2.6, 5.8, 7.0, 8.6, 7.2, 6.7, 2.5, 6.4, 7.2, 10.0, 11.1}, // Year Four
                {6.5, 7.3, 9.8, 10.4, 9.6, 7.6, 5.7, 4.5, 6.7, 8.9, 9.0, 11.4}  // Year Five
            };

    // declare arrays for total rainfall for each year and
    // for average monthly rainfall for all 5 years
    float yearlyRainfall[5], monthlyRainfall[12];

    // initialize variables for calculating
    // average yearly rainfall for all 5 years
    float totalRainfall = 0.0f, averageYearlyRainfall;

    // filling in array for total rainfall for each year

    // loop through each year
    for(int year = 0; year < 5; year++){
        float yearSum = 0;

        // loop through each month in year
        for(int month = 0; month < 12; month++){

            // add rainfall from month to yearly total
            yearSum += rainfallAmounts[year][month];
        }

        // append total for year to total rainfall array
        yearlyRainfall[year] = yearSum;
    }

    // display total rainfall for each year
    printf("YEAR    RAINFALL (inches)\n");

    for(int year = 0; year < 5; year++){
        float yearRainfall = yearlyRainfall[year];

        // add total rainfall from year to sum of rainfall for all 5 years
        totalRainfall += yearRainfall;

        // display total yearly rainfall
        printf("%d\t\t\t%.1f\n", year + 1, yearRainfall);
    }

    // calculate and display average yearly rainfall
    averageYearlyRainfall = totalRainfall / 5;
    printf("\nThe yearly average is %.1f inches.\n\n", averageYearlyRainfall);

    // filling in array for average monthly rainfall for all 5 years

    // loop through each month
    for(int month = 0; month < 12; month++){
        float monthSum = 0;

        // loop through each year
        for(int year = 0; year < 5; year++){

            // add monthly rainfall from year to monthly rainfall sum
            monthSum += rainfallAmounts[year][month];
        }

        // calculate average monthly rainfall and
        // append to monthly rainfall array
        monthlyRainfall[month] = monthSum / 12;
    }

    // display average monthly rainfall;
    // loop through monthly rainfall array
    printf("MONTHLY AVERAGES:\n\n");
    printf("  Jan  Feb  Mar  Apr  May  Jun  Jul  Aug  Sep  Oct  Nov  Dec\n");

    for(int month = 0; month < 12; month++){
        printf("%5.1f", monthlyRainfall[month]);
    }

    return 0;
}