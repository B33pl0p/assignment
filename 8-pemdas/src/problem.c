#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "stack.h"

// Function to determine if a character is an operator
bool is_operator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to get the precedence of an operator
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Function to perform arithmetic operations
double apply_operator(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: return 0;
    }
}

// Function to evaluate the expression
double evaluate_expression(const char* expression) {
    Stack* values = create_stack(strlen(expression));  // Stack for numbers
    Stack* operators = create_stack(strlen(expression));  // Stack for operators
    
    for (int i = 0; i < strlen(expression); i++) {
        char c = expression[i];
        
        // Skip spaces
        if (isspace(c)) continue;

        // If the current character is a number
        if (isdigit(c)) {
            double value = 0;
            while (i < strlen(expression) && isdigit(expression[i])) {
                value = value * 10 + (expression[i] - '0');
                i++;
            }
            i--;  // Decrease i to compensate for the loop increment
            push(values, value);
        }
        // If the current character is an opening parenthesis
        else if (c == '(') {
            push(operators, c);
        }
        // If the current character is a closing parenthesis
        else if (c == ')') {
            // Evaluate the expression inside the parentheses
            while (!is_empty(operators) && peek(operators) != '(') {
                double b = pop(values);
                double a = pop(values);
                char op = (char)pop(operators);
                push(values, apply_operator(a, b, op));
            }
            pop(operators);  // Remove '(' from the operator stack
        }
        // If the current character is an operator
        else if (is_operator(c)) {
            // Process the operator by checking precedence
            while (!is_empty(operators) && precedence(peek(operators)) >= precedence(c)) {
                double b = pop(values);
                double a = pop(values);
                char op = (char)pop(operators);
                push(values, apply_operator(a, b, op));
            }
            push(operators, c);
        }
    }
    
    // Process remaining operators in the stack
    while (!is_empty(operators)) {
        double b = pop(values);
        double a = pop(values);
        char op = (char)pop(operators);
        push(values, apply_operator(a, b, op));
    }
    
    // The final result will be the only value left in the stack
    double result = pop(values);
    
    // Clean up
    destroy_stack(values);
    destroy_stack(operators);
    
    return result;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: ./mysolution \"expression\"\n");
        return 1;
    }

    const char* expression = argv[1];
    double result = evaluate_expression(expression);
    printf("Result: %.2f\n", result);

    return 0;
}
