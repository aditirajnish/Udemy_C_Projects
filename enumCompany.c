//
// Created by Aditi Rajnish on 2020-08-20.
// Create and use an enum type for companies.
//

#include <stdio.h>

int enumCompany() {

    // define enum named "Company"; values are various companies
    enum Company {GOOGLE, FACEBOOK, XEROX, YAHOO, EBAY, MICROSOFT};

    // initialize Company variables for 3 companies
    enum Company xerox = XEROX, google = GOOGLE, ebay = EBAY;

    // output values of each Company variable (integer values)
    printf("The value of Xerox is %d.\n", xerox); // 2
    printf("The value of Google is %d.\n", google); // 0
    printf("The value of eBay is %d.\n", ebay); // 4

    return 0;
}