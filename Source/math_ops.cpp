#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <limits.h>

#include "math_ops.h"
#include "utils.h"

    /*general_solve: solve any types of the 2nd rate polynom*/

void general_solve(double coef_a,  double coef_b, double coef_c,
                   double* ans_x1, double* ans_x2, 
                   int* nRoots)
{
        /*checking function*/

    assert(isfinite(coef_a)),  assert(isfinite(coef_b)),  assert(isfinite(coef_c));
    assert(ans_x1 != NULL),    assert(ans_x2 != NULL),    assert(nRoots != NULL);
    assert(ans_x1 != ans_x2);
    assert(isfinite(*ans_x1)), assert(isfinite(*ans_x2));
    assert(*nRoots > INT_MIN && *nRoots < INT_MAX);
    

    if (double_zero_compare(coef_a) == 0)                // liner equation (a = 0)
        *nRoots = solve_lin(coef_b, coef_c, ans_x1);

    else if (double_zero_compare(coef_c) == 0 &&
             double_zero_compare(coef_a) != 0 &&
             double_zero_compare(coef_b) != 0) {
        *nRoots = solve_lin(coef_a, coef_b, ans_x1) + 1; // +1 root is x = 0
        *ans_x2 = 0;  

    } else                                               // quadratic equations
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
    assert(double_zero_compare(coef_a) != 0);
    assert(ans_x1 != NULL),    assert(ans_x2 != NULL);
    assert(ans_x1 != ans_x2);
    assert(isfinite(*ans_x1)), assert(isfinite(*ans_x2));

    double discr = coef_b * coef_b - 4 * coef_a * coef_c;

    if (double_zero_compare(discr) > 0) {        // discr > 0
        double sqrt_discr = sqrt(discr);
        *ans_x1 = (-coef_b - sqrt_discr) / (2 * coef_a);
        *ans_x2 = (-coef_b + sqrt_discr) / (2 * coef_a);
        return TWO_ROOTS;
        
    } else if (double_zero_compare(discr) < 0) { // discr < 0
        return NO_ROOTS;
        
    } else {                                     //discr = 0
        *ans_x1 = *ans_x2 = -coef_b / (2 * coef_a);
        return ONE_ROOT; 
    }
}