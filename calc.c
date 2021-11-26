//
// Created by Legion on 26.11.2021.
//

#include "calc.h"

const char TERMINATION_SYMBOL = '$';
const int  TRUE               =  1 ;

int main(int argc, char* argv[]) {
    assert("[!] ERROR: NO EXPRESSION [!]" && argc > 1);

    int answer = GetG((const char**) &argv[1]);
    printf("Answer: %i. \n", answer);
}

int GetG(const char** expr) {
    int value = GetE(expr);
    Require(**expr == TERMINATION_SYMBOL);
    return value;
}

int GetE(const char** expr) {
    int value_1 = GetT(expr);
    char operator = **expr;
    if (operator != '-' && operator != '+') return value_1;
    while (TRUE) {
        operator = **expr;
        if (operator != '+' && operator != '-') break;
        (*expr)++;
        int value_2 = GetT(expr);
        if (operator == '+') value_1 += value_2;
        else value_1 -= value_2;
    }
    return value_1;
}

int GetT(const char** expr) {
    int value_1 = GetP(expr);
    char operator = **expr;
    if (operator != '*' && operator != '/') return value_1;
    while (TRUE) {
        operator = **expr;
        if (operator != '*' && operator != '/') break;
        (*expr)++;
        int value_2 = GetP(expr);
        if (operator == '*') value_1 *= value_2;
        else value_1 /= value_2;
    }
    return value_1;
}

int GetP(const char** expr) {
    if (**expr == '(') {
        (*expr)++;
        int value = GetE(expr);
        Require(**expr == ')');
        (*expr)++;
        return value;
    } else {
        return GetN(expr);
    }
}

int GetN(const char** expr) {
    int value = 0;
    const char* oldS = *expr;
    while ('0' <= **expr && **expr <= '9') {
        value = value * 10 + (**expr - '0');
        (*expr)++;
    }
    Require(oldS != *expr);
    return value;
}