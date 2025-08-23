#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <limits.h>

const double DOUBLE_ACCUR = 1e-6; // Accurancy of double numbers

enum Root_options {
    INF_ROOTS = -1, // Infinite number of roots
    NO_ROOTS  = 0,
    ONE_ROOT  = 1,
    TWO_ROOTS = 2 
};

/*coef_input*/
void coef_input(double* coef_a, double* coef_b, double* coef_c);

/*clean_buffer: cleans input buffer*/
void clean_buffer(void);

/*ans_output*/
void ans_output (int nRoots, double ans_x1, double ans_x2);

/*general_solve: solve any types of the 2nd rate polynom*/
void general_solve(double coef_a,  double coef_b, double coef_c,
                   double* ans_x1, double* ans_x2, 
                   int* nRoots);

/*double_zero_compare: compares double number with 0*/
int double_zero_compare(double double_num);

/*solve_lin: solves liner equations & returns nRoots*/
int solve_lin(double coef_b, double coef_c, double* ans_x1);

/*solve_quadr: solves quadratic equations & returns nRoots*/
int solve_quadr(double coef_a,  double coef_b, double coef_c,
                double* ans_x1, double* ans_x2);             

int main() {
    double coef_a = 0, coef_b = 0, coef_c = 0;
    double ans_x1 = 0, ans_x2 = 0;
    int nRoots = 0;

    coef_input(&coef_a, &coef_b, &coef_c);

    general_solve(coef_a,  coef_b, coef_c,
                  &ans_x1, &ans_x2, 
                  &nRoots);

    ans_output (nRoots, ans_x1, ans_x2);

    system("pause");
    return 0;
}

/*coef_input*/
void coef_input(double* coef_a, double* coef_b, double* coef_c) {
    /*checking function*/
    assert(coef_a != NULL),    assert(coef_b != NULL),    assert(coef_c != NULL);
    assert(coef_a != coef_b),  assert(coef_a != coef_c),  assert(coef_b != coef_c);
    assert(isfinite(*coef_a)), assert(isfinite(*coef_b)), assert(isfinite(*coef_c));

    printf("Solving quadratic equations\n");
    printf("Enter coefficients of the equations: a, b, c\n");

    /*checking of the incorrect coef_input*/
    int success_coef_input = 0;      // count of successfully read variables
    while (success_coef_input != 3) {
        success_coef_input = scanf("%lg %lg %lg", coef_a, coef_b, coef_c);
        if (success_coef_input == 3) // correct input
            break;
        else {                       // incorrect input
            printf("Incorrect coefficient :(\n");
            printf("Try again, stupid skin bag\n");
            clean_buffer(); }
    }
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
    /*checking function*/
    assert(isfinite(double_num));

    if (double_num > DOUBLE_ACCUR)       // double_num is possitive
        return 1;
    else if (double_num < -DOUBLE_ACCUR) // double_num is negative
        return -1;
    else                                 // consider double_num as 0
        return 0; 
}

/*general_solve: solve any types of the 2nd rate polynom*/
void general_solve(double coef_a,  double coef_b, double coef_c,
                   double* ans_x1, double* ans_x2, 
                   int* nRoots)
{
    /*checking function*/
    assert(isfinite(coef_a)),  assert(isfinite(coef_b)), assert(isfinite(coef_c));
    assert(ans_x1 != NULL),    assert(ans_x2 != NULL),   assert(nRoots != NULL);
    assert(ans_x1 != ans_x2);
    assert(isfinite(*ans_x1)), assert(isfinite(*ans_x2));
    assert(*nRoots > INT_MIN && *nRoots < INT_MAX);
    

    if (double_zero_compare(coef_a) == 0) // liner equation (a = 0)
        *nRoots = solve_lin(coef_b, coef_c, ans_x1);
    else if (double_zero_compare(coef_c) == 0 &&
             double_zero_compare(coef_a) != 0 &&
             double_zero_compare(coef_b) != 0) {
        printf("This quadratic equation is able to reduce to liner one\n");
        *nRoots = solve_lin(coef_a, coef_b, ans_x1) + 1; // +1 root is x = 0
        *ans_x2 = 0;  
    } else                                // quadratic equations
        *nRoots = solve_quadr(coef_a, coef_b, coef_c,
                             ans_x1, ans_x2);
}

/*solve_lin: solves liner equations & returns nRoots*/
int solve_lin(double coef_b, double coef_c, double* ans_x) {
    /*checking function*/
    assert(isfinite(coef_b)), assert(isfinite(coef_c));
    assert(ans_x != NULL);
    assert(isfinite(*ans_x));

    if (double_zero_compare (coef_b) == 0) {  // b = 0
        if (double_zero_compare(coef_c) == 0) // c = 0 ==> equation like 0 = 0
            return INF_ROOTS;
        else                                  // equation like const = 0
            return NO_ROOTS;
    } else {                                  // b != 0 ==> common liner equation
        *ans_x = -coef_c / coef_b;
        return ONE_ROOT;
    }
}

/*solve_quadr: solves quadratic equations & returns nRoots*/
int solve_quadr(double coef_a,  double coef_b, double coef_c,
                double* ans_x1, double* ans_x2)
{
    /*checking function*/
    assert(isfinite(coef_a)),  assert(isfinite(coef_b)), assert(isfinite(coef_c));
    assert(ans_x1 != NULL),    assert(ans_x2 != NULL);
    assert(ans_x1 != ans_x2);
    assert(isfinite(*ans_x1)), assert(isfinite(*ans_x2));

    double discr = coef_b * coef_b - 4 * coef_a * coef_c;
    double sqrt_discr = sqrt(discr);

    if (double_zero_compare(discr) > 0) {        // discr > 0
        *ans_x1 = (-coef_b + sqrt_discr) / (2 * coef_a);
        *ans_x2 = (-coef_b - sqrt_discr) / (2 * coef_a);
        return TWO_ROOTS;
    } else if (double_zero_compare(discr) < 0) { // discr < 0
        return NO_ROOTS;
    } else {                                     //discr = 0
        *ans_x1 = *ans_x2 = -coef_b / (2 * coef_a);
        return ONE_ROOT; 
    }
}