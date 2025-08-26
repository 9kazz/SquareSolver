#ifndef UTEST_FILE_H
#define UTEST_FILE_H

#include <stdio.h>

/*functions*/

    void utest_main_file (void);

        int utest_input_file(FILE* fp_utest,
                             double* coef_a,     double* coef_b,     double* coef_c,
                             int* nRoots_ref,
                             double* ans_x1_ref, double* ans_x2_ref);
    
    int utest_checking_file (int nRoots_ref, 
                             double ans_x1_ref,  double ans_x2_ref,
                             int nRoots,
                             double ans_x1,      double and_x2);

/*enums*/

        enum reading_file_result {
            READ_SUCCESS   = 1,
            READ_FAIL = 0
        };

        enum checking_file_result {
            CHECK_SUCCESS   = 1,
            CHECK_FAIL = 0
        };

/*constants*/

    const int MAX_LINE = 1000;

#endif