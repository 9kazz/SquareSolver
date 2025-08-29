#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>

#include "math_ops.h"
#include "utils.h"


int terminal_input (int argc,        char* argv[],
                    double* coef_a,  double* coef_b,  double* coef_c,
                    char* file_name) {
    char* point_arg = NULL;
    int oper = 0;

    bool test_bool      = false;
    bool coef_bool      = false;
    bool file_bool      = false;
    bool reading_status = true;

    int i = 1;
    while(i < argc && reading_status != INCOR_OPER) {
        point_arg = argv[i];
        oper = identify_oper(point_arg); 
        
        if (oper == END_COM_STR)
            break;

        reading_status = run_oper(oper,
                                  coef_a,      coef_b,      coef_c,
                                  file_name,
                                  &test_bool,  &coef_bool,  &file_bool,
                                  argv,
                                  &i); 

        i++;
    }

    if (reading_status == INCOR_OPER)
        return INCOR_OPER;

    else if (reading_status != INCOR_OPER && 
             test_bool == true && 
             file_bool == true &&
             coef_bool == false)
        return TEST;

    else if (reading_status != INCOR_OPER && 
             test_bool == false && 
             file_bool == false &&
             coef_bool == true)
        return COEFFICIENTS;
    
    else
        return INCOR_OPER;
}   

int run_oper (int oper,
              double* coef_a,  double* coef_b,  double* coef_c,
              char* file_name,
              bool* test_bool, bool* coef_bool, bool* file_bool,
              char* argv[],
              int* i) {

    switch (oper) 
    {
        case TEST:

            if (*test_bool == false &&
                *coef_bool == false) {

                *test_bool = true;
                return TEST;

            } else  {
                return INCOR_OPER;
            }

        case COEFFICIENTS:

            if (*coef_bool == false && 
                *test_bool == false && 
                *file_bool == false) {

                *coef_a = atof(argv[*i + 1]);
                *coef_b = atof(argv[*i + 2]);
                *coef_c = atof(argv[*i + 3]);
                *i += 3;
                *coef_bool = true;
                return COEFFICIENTS;

            } else {
                return INCOR_OPER;
            }

        case READ_FILE:

            if (*file_bool == false &&
                *test_bool == true  &&
                *coef_bool == false) {

                strcpy(file_name, argv[*i + 1]);
                *i += 1;
                *file_bool = true;
                return READ_FILE;

            } else {
                return INCOR_OPER;
        }

        case END_COM_STR:
            return END_COM_STR;

        default:
            return INCOR_OPER;

    }
}

int identify_oper (char* point_arg) {
    if (*point_arg == '-') { 
        if (*(point_arg + 2) == '\0') { 
            switch (*(point_arg + 1))
            {
            case 't':
                return TEST;
            case 'c':
                return COEFFICIENTS;
            case 'f':
                return READ_FILE;
            default:
                return INCOR_OPER;
            }
        } else {
            return INCOR_OPER;
        }
    } else if (*point_arg == '\0') {
        return END_COM_STR;

    } else {
        return INCOR_OPER;
    }
}

void pseudo_loading(void) {
    #define LOADING_BAR     30
    #define ONE_PART_TIME  100
    
    printf(BLUE "loading...\n" RESET);
    printf(BLUE_BG "******************************" RESET);

    for (int i = LOADING_BAR; i > 0; i--)
        printf("\b");

    for (int i = LOADING_BAR; i > 0; i--) {
        Sleep(ONE_PART_TIME);
        printf(GREEN_BG "#" RESET);
    }

    for (int i = LOADING_BAR; i > 0; i--)
        printf("\b");
    
    for (int i = LOADING_BAR; i > 0; i--)
        printf("\b");

    for (int i = LOADING_BAR / 2 - 2; i > 0; i--)
        printf(GREEN_BG " " );

    printf("DONE");

    for (int i = LOADING_BAR / 2 - 2; i > 0; i--)
        printf(" ");

    printf(RESET "\n\n");
};

void coef_input(double* coef_a, double* coef_b, double* coef_c) {

        /*checking function*/

    assert(coef_a != NULL),    assert(coef_b != NULL),    assert(coef_c != NULL);
    assert(coef_a != coef_b),  assert(coef_a != coef_c),  assert(coef_b != coef_c);
    assert(isfinite(*coef_a)), assert(isfinite(*coef_b)), assert(isfinite(*coef_c));

    printf("\n" BLUE_BG "Solving quadratic equations" RESET "\n");
    printf(BLUE "Enter coefficients of the equations: a, b, c\n" RESET);

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
        return MORE;

    else if (double_num < -DOUBLE_ACCUR) // double_num is negative
        return LESS;
        
    else                                 // consider double_num as 0
        return EQUAL; 
}