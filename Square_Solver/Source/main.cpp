#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <limits.h>

#include "math_ops.h"
#include "utils.h"
#include "utest_file.h"

int main(int argc, char* argv[]) {
    double coef_a = 0, coef_b = 0, coef_c = 0;
    double ans_x1 = 0, ans_x2 = 0;
    int nRoots = 0;

    char file_name[MAX_LINE] = {0};

    int reading_status = terminal_input(argc, argv,
                                        &coef_a, &coef_b, &coef_c,
                                        file_name);

    if (reading_status == TEST) {              
        printf(YELLOW "\nOMG! Is that u, my creator? I've been waiting you...\nTEST ME RIGHT NOW!!!\n\n");
        utest_main_file(file_name);
    }

    else if (reading_status == COEFFICIENTS) {                                                                             
        general_solve(coef_a,  coef_b, coef_c,
                      &ans_x1, &ans_x2, 
                      &nRoots);

        ans_output (nRoots, 
                    ans_x1, ans_x2);
    }

    else
        printf(RED "Incorrect terminal operations :(\n" RESET);

printf(GREEN "\nCOMMIT GIT HUB" RESET);                                                 // testing & notification

return 0;
}