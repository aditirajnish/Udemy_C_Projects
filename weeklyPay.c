//
// Created by Aditi Rajnish on 2020-08-21.
// Calculates weekly pay, given number of hours worked.
// Takes into account overtime pay and tax brackets.
// Displays gross pay, taxes, and net pay.
//

#include <stdio.h>

// defining constants
#define PAYRATE 12.00
#define OVERTIME_HOURS 40

// values for tax brackets (i.e. up to $300, next $150)
#define TAXVAL_LOW 300.0
#define TAXVAL_MID 150.0

// tax rates for 3 brackets (i.e. 0.15 = 15% tax)
#define TAXRATE_LOW 0.15
#define TAXRATE_MID 0.2
#define TAXRATE_REST 0.25

int weeklyPay(){

    // initialize variables (all of type double)
    double hours, normalPay, overtimePay;
    double grossPay, taxes, netPay;

    // get number of hours worked by user
    printf("Enter the number of hours worked this week: ");
    scanf("%lf", &hours);

    // determine gross pay; two scenarios:

    // 1) if 40 or less hours worked (no overtime)
    if(hours <= OVERTIME_HOURS){
        grossPay = hours * PAYRATE;
    }

    // 2) if more than 40 hours worked
    else{
        // find normal payment (portion that isn't overtime)
        normalPay = 40 * PAYRATE;

        // get overtime hours, then find overtime payment;
        // overtime rate is 1.5 times normal rate
        overtimePay = ((hours - 40) * (PAYRATE * 1.5));

        // combine normal payment with overtime payment
        grossPay = normalPay + overtimePay;
    }
    // determine taxes, w/ three scenarios
    // for 3 tax brackets; depends on gross pay

    // scenario 1)
    if(grossPay <= TAXVAL_LOW){
        taxes = grossPay * TAXRATE_LOW; // bracket 1 (low)
    }

    // scenario 2)
    else if(grossPay > TAXVAL_LOW && grossPay <= (TAXVAL_LOW + TAXVAL_MID)){
        taxes = (TAXVAL_LOW * TAXRATE_LOW); // bracket 1 (low)
        taxes += ((grossPay - TAXVAL_LOW) * TAXRATE_MID); // bracket 2 (mid)
    }

    // scenario 3)
    else{
        taxes = (TAXVAL_LOW * TAXRATE_LOW); // bracket 1 (low)
        taxes += (TAXVAL_MID * TAXRATE_MID); // bracket 2 (mid)
        taxes += ((grossPay - (TAXVAL_LOW + TAXVAL_MID)) * TAXRATE_REST); // bracket 3 (rest)
    }

    // determine net pay from gross pay and taxes
    netPay = grossPay - taxes;

    //display gross pay, taxes, and net pay (rounded to 2 decimal places)
    printf("Gross pay: $%.2f.\n", grossPay);
    printf("Taxes: $%.2f.\n", taxes);
    printf("Net pay: $%.2f.\n", netPay);

    return 0;
}