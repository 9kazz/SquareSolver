#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <limits.h>

#include "math_ops.h"
#include "utils.h"
#include "utest_file.h"

int main() {
    double coef_a = 0, coef_b = 0, coef_c = 0;
    double ans_x1 = 0, ans_x2 = 0;
    int nRoots = 0;

    coef_input(&coef_a, &coef_b, &coef_c);

    if (user_interface(coef_a, coef_b, coef_c) == DEVELOPER) {              // developer mode
        printf(YELLOW "\nOMG! Is that u, my creator? I've been waiting you...\n");
        printf("Eter the name of the file and TEST ME RIGHT NOW!!!\n\n" RESET);

        utest_main_file();
    }

    else {                                                                  // user mode
        general_solve(coef_a,  coef_b, coef_c,
                      &ans_x1, &ans_x2, 
                      &nRoots);

        ans_output (nRoots, ans_x1, ans_x2);
    }

printf(GREEN "\nCOMMIT GIT HUB" RESET);                                                 // testing & notification

return 0;
}