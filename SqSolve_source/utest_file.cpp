#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <limits.h>

#include "math_ops.h"
#include "utils.h"
#include "utest_file.h"

void utest_main_file (void) {
    double coef_a = 0, coef_b = 0, coef_c = 0;

    int nRoots = 0;
    double ans_x1 = 0, ans_x2 = 0;

    int nRoots_ref = 0;
    double ans_x1_ref = 0, ans_x2_ref = 0;

    int test_number = 0;
    int mistakes = 0;

    FILE* fp_utest;
    char file_name[MAX_LINE] = {0};

    scanf("%s", file_name);                                                            // readinf of the name of the file

    if ((fp_utest = fopen(file_name, "r")) == NULL)                                    // not able to open the file   

        printf(RED "utest_input_file: I can't open the file :(\n" RESET);
    else
    {   
        for (test_number = 0; utest_input_file (fp_utest,                              // file have read successfuly
                                                &coef_a,     &coef_b,     &coef_c,
                                                &nRoots_ref,
                                                &ans_x1_ref, &ans_x2_ref)
                                                == READ_SUCCESS; 
            ++test_number) 
        {

            general_solve (coef_a,  coef_b, coef_c,
                        &ans_x1, &ans_x2,
                        &nRoots);

            if (utest_checking_file (nRoots_ref, 
                                     ans_x1_ref, ans_x2_ref,
                                     nRoots,
                                     ans_x1,     ans_x2) 
                                     == CHECK_FAIL)                                    // output data are incorrect
            {
                ++mistakes;

                printf(RED   "CAM TAKOE C4ITAY, KOZHANIY MEIIIOK!\n" RESET);

                printf(BLUE "test number: %d \n" RESET, test_number + 1);

                printf(BLUE  "Coefficient: %lg %lg %lg\n" RESET, coef_a, coef_b, coef_c);

                printf(RED   "Count of roots: %d" RESET, nRoots);
                printf(GREEN " (should be %d)\n" RESET,  nRoots_ref);

                printf(RED   "Answer: %lg, %lg" RESET,         ans_x1,     ans_x2);
                printf(GREEN " (should be %lg, %lg)\n" RESET, ans_x1_ref, ans_x2_ref);
            }
        }

    printf(BLUE "Correct answers: %d / %d \n" RESET, (test_number - mistakes) , test_number);
    }
}

int utest_input_file(FILE* fp_utest,
                     double* coef_a,     double* coef_b,     double* coef_c,
                     int* nRoots_ref,
                     double* ans_x1_ref, double* ans_x2_ref) 
{
    if (fscanf(fp_utest,                            // EOF
              "%lg %lg %lg %d %lg %lg",
               coef_a,     coef_b,     coef_c,
               nRoots_ref,
               ans_x1_ref, ans_x2_ref)
               == EOF)
        return READ_FAIL;

    else                                            // reading file is correct
        return READ_SUCCESS;
}

int utest_checking_file (int nRoots_ref, 
                         double ans_x1_ref, double ans_x2_ref,
                         int nRoots,
                         double ans_x1,     double ans_x2)    
{
    if (nRoots_ref == nRoots)                                     // correct returned value of nRoots
    {
        if (nRoots == INF_ROOTS || nRoots == NO_ROOTS)
            return CHECK_SUCCESS;

        else
        {
            if (double_zero_compare (ans_x1_ref - ans_x1) == 0 && // x1 & x2 are correct roots
                double_zero_compare (ans_x2_ref - ans_x2) == 0)
                return CHECK_SUCCESS;
            else
                return CHECK_FAIL;
        }
    } else                                                        // incorrect output data
        return CHECK_FAIL;
}                    