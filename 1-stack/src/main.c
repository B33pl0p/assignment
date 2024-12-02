#include "stack.h"
#include <stdio.h>
enum subproblem {
    FILLX,
    TRIGGER_OVERFLOW,
    TRIGGER_UNDERFLOW,
    PRINT_REVERSE
};

// DO NOT ALTER THE MAIN, STACK.C/H
// ONLY EDIT PROBLEM.C
int main(int argc, char const *argv[]) {
    assert(argc == 4);

    int subproblem = atoi(argv[1]);
    int init_capacity = atoi(argv[2]);
    int fill = atoi(argv[3]);

    stack_t* stack = stack_init(init_capacity);

    switch (subproblem){
        case FILLX:
            fill_x(stack, fill);
            stack_pretty_print(stack);
            break;
        case TRIGGER_OVERFLOW:
            trigger_overflow(stack);
            break;
        case TRIGGER_UNDERFLOW:
            trigger_underflow(stack);
            break;
        case PRINT_REVERSE:
            fill_x(stack, fill);
            stack = stack_reverse(stack);
            stack_pretty_print(stack);
            break;
        default:
            break;
    }

    stack_free(stack);
    return 0;
}
