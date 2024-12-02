#include "stack.h"


// Initialize the stack with a specified capacity
stack_t* stack_init(int capacity) {
    assert(capacity > 0);          // Ensure the capacity is a valid positive number

    // Setting members
    stack_t *stack = (stack_t *)malloc(sizeof(stack_t)); // Allocate memory on the heap
    stack->items = (int *)malloc(capacity * sizeof(int));  // Allocate memory on the heap
    assert(stack != NULL);    // Ensure memory allocation succeeded
    assert(stack->items != NULL);    // Ensure memory allocation succeeded
    
    stack->capacity = capacity;
    stack->top = stack->items; // start of the stack->items block.
    return stack;
}
int stack_size(stack_t *stack){
    return stack->top - stack->items;
}

// Add an element to the stack
bool stack_push(stack_t *stack, int item) {
    assert(stack != NULL);           // Ensure the stack pointer is valid
    assert(stack->items != NULL);    // Ensure the items array is valid
    
    if (stack_is_full(stack)) {
        fprintf(stderr, "Stack Overflow! - Attempting to push to a full stack\n");
        return false;  // stack is full, cannot add new item
    }

    stack->items[stack_size(stack)] = item;
    stack->top++;
    
    return true;
}
int stack_pop(stack_t *stack) {
    assert(stack != NULL);           // Ensure the stack pointer is valid
    assert(stack->items != NULL);    // Ensure the items array is valid
    // give error message when popping an empty stack
    if(stack_is_empty(stack)){
        fprintf(stderr, "Stack Underflow! - Attempting to pop from an empty stack\n");
        return -1;
    }
    int oldtop = *(stack->top - 1);
    stack->top--;
    
    return oldtop;
}
int stack_peek(stack_t *stack){
    // give an error message if peeking at an empty stack
    return *(stack->top);
}

// Check if the stack is full
bool stack_is_full(stack_t *stack) {
    assert(stack != NULL);           // Ensure the stack pointer is valid
    assert(stack->items != NULL);    // Ensure the items array is valid
  
    return stack_size(stack) >= stack->capacity;
}

// Check if the stack is full
bool stack_is_empty(stack_t *stack) {
    // return stack_size(stack) == 0;
    return stack->items == stack->top;
}

// Pretty print the stack
void stack_pretty_print(stack_t *stack) {
    assert(stack != NULL);           // Ensure the stack pointer is valid
    assert(stack->items != NULL);    // Ensure the items array is valid
    int n = stack_size(stack);

    assert(n >= 0 && n <= stack->capacity); // Ensure stack size is valid
    printf("------------\nSTACK PRINT\n---\n");
    printf("stack contents [size: %d, capacity: %d]:\n", n, stack->capacity);
    if(n == 0){
        printf("stack is empty\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        printf("%d", stack->items[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("\n------------\n");
}

// Free the dynamically allocated memory for the stack
void stack_free(stack_t *stack) {
    assert(stack != NULL);           // Ensure the stack pointer is valid
    assert(stack->items != NULL);    // Ensure the items array is valid

    free(stack->items);              // Free the dynamically allocated array
    free(stack);
}
