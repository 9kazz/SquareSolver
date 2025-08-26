#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <limits.h>

#include "math_ops.h"
#include "utils.h"

    /*coef_input*/

void coef_input(double* coef_a, double* coef_b, double* coef_c) {

        /*checking function*/

    assert(coef_a != NULL),    assert(coef_b != NULL),    assert(coef_c != NULL);
    assert(coef_a != coef_b),  assert(coef_a != coef_c),  assert(coef_b != coef_c);
    assert(isfinite(*coef_a)), assert(isfinite(*coef_b)), assert(isfinite(*coef_c));

    printf(BLUE "Solving quadratic equations\n");
    printf("Enter coefficients of the equations: a, b, c\n" RESET);

        /*checking of the incorrect coef_input*/

    int success_coef_input = 0;                               // count of successfully read variables
    while (success_coef_input != 3) {
        success_coef_input = scanf("%lg %lg %lg", coef_a, coef_b, coef_c);
        if (success_coef_input == 3)                          // correct input
            break;
        else {                                                // incorrect input
            printf(RED "Incorrect coefficient :(\n");
            printf("Try again, stupid skin bag\n\n" RESET);
            clean_buffer(); }
    }
}
        
    /*user_interface*/

int user_interface(double coef_a, double coef_b, double coef_c) {

        /*Checking function*/

    assert(isfinite(coef_a)), assert(isfinite(coef_b)), assert(isfinite(coef_c));
    
    if (double_zero_compare(coef_a - 52) == 0 &&
        double_zero_compare(coef_b - 69) == 0 && 
        double_zero_compare(coef_c - 1488) == 0) // checking password
        return DEVELOPER;
    else
        return USER;
}

    /*clean_buffer: cleans input buffer*/

void clean_buffer(void) {
    int input_char = 0;
    while ((input_char = getchar()) != '\n') 
        ;
}

    /*ans_output*/

void ans_output (int nRoots, double ans_x1, double ans_x2) {

        /*checking function*/

    assert(isfinite(ans_x1)), assert(isfinite(ans_x2));
    assert(nRoots > INT_MIN), assert(nRoots < INT_MAX);

    switch (nRoots) {
        case INF_ROOTS:
            printf("Number of roots: infinity\n");
            break;
        case NO_ROOTS:
            printf("Number of roots: %d\n", nRoots);
            break;
        case ONE_ROOT:
            printf("Number of roots: %d\n", nRoots);
            printf("x = %g\n", ans_x1);
            break;
        case TWO_ROOTS:
            printf("Number of roots: %d\n", nRoots);
            printf("x1 = %g\n", ans_x1);
            printf("x2 = %g\n", ans_x2);
            break;
    }                   
}

    /*double_zero_compare: compares double number with 0*/

int double_zero_compare(double double_num) {

    const double DOUBLE_ACCUR = 1e-6;   // Accurancy of double numbers

        /*checking function*/

    assert(isfinite(double_num));

    if (double_num > DOUBLE_ACCUR)       // double_num is possitive
        return 1;
    else if (double_num < -DOUBLE_ACCUR) // double_num is negative
        return -1;
    else                                 // consider double_num as 0
        return 0; 
}