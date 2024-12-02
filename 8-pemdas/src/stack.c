#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

// Function to create a stack of a given capacity
Stack* create_stack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->items = (double*)malloc(sizeof(double) * capacity);
    return stack;
}

// Push an item onto the stack
void push(Stack* stack, double item) {
    if (is_full(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->items[++stack->top] = item;
}

// Pop an item from the stack
double pop(Stack* stack) {
    if (is_empty(stack)) {
        printf("Stack Underflow\n");
        return -1; // Error code
    }
    return stack->items[stack->top--];
}

// Peek at the top item of the stack without removing it
double peek(Stack* stack) {
    if (!is_empty(stack)) {
        return stack->items[stack->top];
    }
    return -1; // Error code
}

// Check if the stack is empty
bool is_empty(Stack* stack) {
    return stack->top == -1;
}

// Check if the stack is full
bool is_full(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// Free the memory allocated for the stack
void destroy_stack(Stack* stack) {
    free(stack->items);
    free(stack);
}
