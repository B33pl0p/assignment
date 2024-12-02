#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

// Define a structure for the stack
typedef struct Stack {
    double *items;       // Array to store stack items
    int top;             // Index of the top item
    int capacity;        // Maximum number of items
} Stack;

// Function prototypes
Stack* create_stack(int capacity);
void push(Stack* stack, double item);
double pop(Stack* stack);
double peek(Stack* stack);
bool is_empty(Stack* stack);
bool is_full(Stack* stack);
void destroy_stack(Stack* stack);

#endif // STACK_H
