#include "stack.h"

// Function to trigger underflow: pop all items, then try popping from empty stack
void trigger_underflow(stack_t *stack) {
    // Pop all elements in stack till it's empty
    while (!stack_is_empty(stack)) {
        stack_pop(stack);  // Pop 1 item from stack
    }

    // Now, try popping again from empty stack. Should trigger underflow!
    stack_pop(stack);  // This will print "Stack Underflow!" error
}

// Function to trigger overflow: push more items than stack can hold
void trigger_overflow(stack_t *stack) {
    // Try to push 1 more than the stack capacity
    for (int i = 0; i < stack->capacity + 1; i++) {
        if (!stack_push(stack, i)) {
            // if push fails, stack's full, stop pushing
            // should print "Stack Overflow!" from stack_push
            break;
        }
    }
}

// Function to fill stack with 'fill' number of items
void fill_x(stack_t *stack, int fill) {
    // Push 'fill' items into stack
    for (int i = 0; i < fill; i++) {
        if (!stack_push(stack, i)) {
            break;  // Stop if stack is full
        }
    }
    
    // Print stack contents after filling
    stack_pretty_print(stack);  // Shows the items in the stack
}

// Function to reverse stack using temp stack
stack_t* stack_reverse(stack_t *stack) {
    stack_t *temp_stack = stack_init(stack->capacity);  // Create a temp stack

    // Pop from original stack and push onto temp stack (to reverse order)
    while (!stack_is_empty(stack)) {
        int item = stack_pop(stack);
        stack_push(temp_stack, item);  // Push to temp stack
    }

    return temp_stack;  // Return reversed stack
}
