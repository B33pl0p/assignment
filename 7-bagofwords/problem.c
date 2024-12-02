
/**
 * PROJ02: PROBLEM 1
 * Spring 2023
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "pprint.h"
long double factorial(unsigned int n, int times_called);

long double factorial(unsigned int n, int times_called)
{
    long double result;

    printf("%s%s(%d, %d) \n", pprint_indent_memoized(times_called), __func__, n, times_called);

    if (n <= 1)
    {
        result = 1;
    }
    else
    {
        result = n * factorial(n - 1, times_called + 1);
    }

    printf("%s %.0Lf\n", pprint_indent_memoized(times_called), result);
    return result;
}

// Usage: ./mysolution [fn-selector] [n]

// DO NOT EDIT MAIN
char *INDENTATION_MARKER;
int main(int argc, char *argv[])
{

    clock_t start, end;
    double cpu_time_used;

    start = clock();

    char *fnSelector = argv[1];
    INDENTATION_MARKER = argv[2];
    int indentation_n = atoi(argv[3]);

    // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

    if (strcmp(fnSelector, "indent") == 0)
    {
        for (int i = 0; i < indentation_n; i++)
        {
            printf("%d - %s\n", i, pprint_indent(i));
        }
    }

    // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

    if (strcmp(fnSelector, "factorial") == 0)
    {
        unsigned int n = atoi(argv[3]);
        unsigned int result = factorial(n, 1);
        printf("%u", result);
    }

    // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

    if (strcmp(fnSelector, "memoize") == 0)
    {
        pprint_init();
        char *ptr_a = NULL;
        char *ptr_b = NULL;
        int n = atoi(argv[3]);
        for (int i = 0; i < n; i++)
        {
            ptr_a = pprint_indent_memoized(i);
            ptr_b = pprint_indent_memoized(i);
            printf("L(%d) - %s? %s\n", i, ptr_a, ptr_a == ptr_b ? "TRUE" : "FALSE");
        }
        pprint_destroy();
    }

    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;

    printf("Run time: %f ms\n", cpu_time_used);
    return 0;
}
