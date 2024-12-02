#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

// Static stack structure
typedef struct {
    int *items;  // Pointer to dynamically allocated array
    int capacity; // Maximum capacity of the stack
    int* top;
} stack_t;

// Initialize the stack with a specified capacity
stack_t* stack_init(int capacity);

// Add an element to the stack
bool stack_push(stack_t *stack, int item);
int stack_pop(stack_t *stack);
int stack_peek(stack_t *stack);
//append

// Check if the stack is full
bool stack_is_full(stack_t *stack);
bool stack_is_empty(stack_t *stack);

// Pretty print the stack
void stack_pretty_print(stack_t *stack);

// Free the dynamically allocated memory for the stack
void stack_free(stack_t *stack);

// PROBLEM FUNCTIONS
void trigger_underflow(stack_t *stack);
void trigger_overflow(stack_t *stack);
void fill_x(stack_t *stack, int fill);
stack_t* stack_reverse(stack_t *stack);

#endif // STACK_H
