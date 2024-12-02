
#ifndef PPRINT_H
#define PPRINT_H

// Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

// Definitions
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
#define BITS_IN_BYTE 8


int pprint_binary(unsigned int, unsigned int);
void bitcalculator(unsigned int, unsigned int, const char, unsigned int);

#endif /* PPRINT_H */