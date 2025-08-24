#include "math_ops.h"
#include "utils.h"
#include "unit_tests.h"

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <limits.h>

int main() {
    double coef_a = 0, coef_b = 0, coef_c = 0;
    double ans_x1 = 0, ans_x2 = 0;
    int nRoots = 0;

    coef_input(&coef_a, &coef_b, &coef_c);

    if (user_interface(coef_a, coef_b, coef_c) == DEVELOPER) { // developer mode
        printf("OMG! Is that u, my creator? I've been waiting you... TEST ME RIGHT NOW!!!\n\n");
        printf("Testing:\n");
        utest_general_solve(); 
    }

    else {                                                       // user mode
        general_solve(coef_a,  coef_b, coef_c,
                      &ans_x1, &ans_x2, 
                      &nRoots);

        ans_output (nRoots, ans_x1, ans_x2);
    }
return 0;
}