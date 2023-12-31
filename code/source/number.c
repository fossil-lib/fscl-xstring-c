/*
==============================================================================
Author: Michael Gene Brockus (Dreamer)
Email: michaelbrockus@gmail.com
Organization: Fossil Logic
Description: 
    This file is part of the Fossil Logic project, where innovation meets
    excellence in software development. Michael Gene Brockus, also known as
    "Dreamer," is a dedicated contributor to this project. For any inquiries,
    feel free to contact Michael at michaelbrockus@gmail.com.
==============================================================================
*/
#include "fossil/xstring/number.h"
#include <string.h>
#include <ctype.h>

typedef struct {
    cstring word;
    long long int value;
} NumberMapping;

typedef struct {
    cstring operator;
    int priority;
} OperatorMapping;

OperatorMapping operators[] = {
    {"+", 1}, {"-", 1}, {"*", 2}, {"/", 2}
};

// Define mappings for units, tens, and powers of ten
NumberMapping units[] = {
    {"zero", 0}, {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4},
    {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}
};

NumberMapping teens[] = {
    {"ten", 10}, {"eleven", 11}, {"twelve", 12}, {"thirteen", 13}, {"fourteen", 14},
    {"fifteen", 15}, {"sixteen", 16}, {"seventeen", 17}, {"eighteen", 18}, {"nineteen", 19}
};

NumberMapping tens[] = {
    {"twenty", 20}, {"thirty", 30}, {"forty", 40}, {"fifty", 50},
    {"sixty", 60}, {"seventy", 70}, {"eighty", 80}, {"ninety", 90}
};

NumberMapping powersOfTen[] = {
    {"thousand", 1000}, {"million", 1000000}, {"billion", 1000000000}, {"trillion", 1000000000000}
};

int fscl_string_number_to_numeric(cstring number) {
    int total = 0;
    int currentNumber = 0;

    for (size_t i = 0; i < sizeof(units) / sizeof(units[0]); ++i) {
        if (strcmp(number, units[i].word) == 0) {
            currentNumber = units[i].value;
            break;
        }
    }

    if (currentNumber == 0) {
        for (size_t i = 0; i < sizeof(teens) / sizeof(teens[0]); ++i) {
            if (strcmp(number, teens[i].word) == 0) {
                currentNumber = teens[i].value;
                break;
            }
        }
    }

    if (currentNumber == 0) {
        for (size_t i = 0; i < sizeof(tens) / sizeof(tens[0]); ++i) {
            if (strcmp(number, tens[i].word) == 0) {
                currentNumber = tens[i].value;
                break;
            }
        }
    }

    int lastNumber = 0;
    if (currentNumber == 0) {
        for (size_t i = 0; i < sizeof(powersOfTen) / sizeof(powersOfTen[0]); ++i) {
            if (strcmp(number, powersOfTen[i].word) == 0) {
                total += currentNumber * powersOfTen[i].value;
                lastNumber = currentNumber;
                currentNumber = 0;
                break;
            }
        }
    }

    if (currentNumber != 0) {
        if (lastNumber != 0) {
            total += lastNumber * 10 + currentNumber;
        } else {
            total += currentNumber;
        }
    }

    return total;
}

int fscl_string_expression_to_numeric(cstring expression) {
    // Convert a written expression to a numeric value
    // Assumes a simple expression without parentheses
    
    int result = 0;
    int currentNumber = 0;
    int currentPriority = 0;
    cstring currentOperator = "+";

    size_t len = strlen(expression);

    for (size_t i = 0; i <= len; ++i) {
        if (i == len || isspace((unsigned char)expression[i])) {
            // Handle the end of the expression or space
            int numericValue = fscl_string_number_to_numeric(expression + i - currentPriority);
            
            if (currentOperator[0] == '+') {
                result += numericValue;
            } else if (currentOperator[0] == '-') {
                result -= numericValue;
            } else if (currentOperator[0] == '*') {
                result *= numericValue;
            } else if (currentOperator[0] == '/') {
                if (numericValue != 0) {
                    result /= numericValue;
                } else {
                    // Handle division by zero
                    return -1;
                }
            }

            // Reset variables for the next number/operator
            currentNumber = 0;
            currentPriority = 0;
            currentOperator = "+";
        } else if (isdigit((unsigned char)expression[i])) {
            // Accumulate digits for the current number
            currentNumber = currentNumber * 10 + (expression[i] - '0');
        } else if (isalpha((unsigned char)expression[i])) {
            // Accumulate alphabetic characters for the current operator
            currentOperator = expression + i - currentPriority;
            currentPriority = 0;
        } else if (expression[i] == '*') {
            // Handle priority for multiplication
            if (currentPriority == 0) {
                currentPriority = 2;
            }
        } else if (expression[i] == '/') {
            // Handle priority for division
            if (currentPriority == 0) {
                currentPriority = 2;
            }
        }
    }

    return result;
}

cstring fscl_string_number_from_numeric(int number) {
    // Implementation of converting numeric values to English words is more complex
    // and may require additional logic based on your specific requirements.
    // This example includes only basic handling for numbers less than 100.
    
    if (number >= 10 && number <= 19) {
        for (size_t i = 0; i < sizeof(teens) / sizeof(teens[0]); ++i) {
            if (number == teens[i].value) {
                return teens[i].word;
            }
        }
    } else if (number % 10 == 0 && number < 100) {
        for (size_t i = 0; i < sizeof(tens) / sizeof(tens[0]); ++i) {
            if (number == tens[i].value) {
                return tens[i].word;
            }
        }
    } else {
        for (size_t i = 0; i < sizeof(units) / sizeof(units[0]); ++i) {
            if (number % 10 == units[i].value) {
                return units[i].word;
            }
        }
    }

    return "unknown";
}
