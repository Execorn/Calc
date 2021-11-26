//
// Created by Legion on 26.11.2021.
//

#ifndef CALCULATOR_CALC_H
#define CALCULATOR_CALC_H

#include <assert.h>
#include <stdio.h>
#include "stdlib.h"

extern const char TERMINATION_SYMBOL;
extern const int                TRUE;

#define NAME(var) #var

#define Require(condition)                                                                                            \
    if (!(condition)) {                                                                                               \
        fprintf(stderr, "ERROR in line %i in function %s: \"%s\" assertion failed. \n",                               \
                __LINE__, __FUNCTION__, NAME(condition));                                                             \
                abort();                                                                                              \
    }


int main(int argc, char* argv[]);

int GetG(const char** expr);

int GetE(const char** expr);

int GetT(const char** expr);

int GetP(const char** expr);

int GetN(const char** expr);



#endif //CALCULATOR_CALC_H
