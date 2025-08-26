#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <limits.h>

#include "math_ops.h"
#include "utils.h"
#include "unit_tests.h"

void utest_general_solve(void) {

    int count_of_tests = 0;
    int mistakes = 0;
    int test_number = 0;
    double ans_x1 = 0, ans_x2 = 0;
    int nRoots = 0;

    double testing_data[][6] = {         
    /*  {   a,   b,   c,   nRoots,  x1,  x2 },  */
        {   1,  -5,   6,        2,   2,   3 },  // 0
        {   1,   2,   1,        1,  -1,  -1 },  // 1
        {   1,   1,   1,        0, NAN, NAN },  // 2
        {   0,   0,   5,        0, NAN, NAN },  // 3
        {   0,   0,   0,INF_ROOTS, NAN, NAN },  // 4
        {   4,   0, -16,        2,  -2,   2 },  // 5
        {   2,   6,   0,        2,  -3,   0 },  // 6
        {   3,   0,   0,        1,   0,   0 },  // 7
        { 1e5, 2e5, 1e5,        1,  -1,  -1 },  // 8
        {1e-5,2e-5,1e-5,        1,  -1,  -1 }   // 9

    };

    count_of_tests = sizeof(testing_data) / sizeof(testing_data[0]);

    for (test_number = 0; test_number < count_of_tests; ++test_number) {

        general_solve (testing_data[test_number][A],  testing_data[test_number][B], testing_data[test_number][C],
                       &ans_x1,                       &ans_x2,
                       &nRoots );

        if (utest_checking(test_number, nRoots,
                           ans_x1,      ans_x2,
                           testing_data) == 0) // output data are incorrect
        {
            ++mistakes;
            printf("CAM TAKOE C4ITAY, KOZHANIY MEIIIOK!\n");
            printf("Coefficient: %lg %lg %lg \n",
                    testing_data[test_number][A], testing_data[test_number][B], testing_data[test_number][C]);
            printf("Answer: %d, %lg, %lg (should be %d, %lg, %lg)\n", 
                    nRoots,                            ans_x1,                        ans_x2, 
                    testing_data[test_number][NROOTS], testing_data[test_number][X1], testing_data[test_number][X2]);
        }
    }

    printf("Correct answers: %d / %d \n", (test_number - mistakes) , test_number);
}

int utest_checking (int test_number, int nRoots, 
                    double ans_x1,   double ans_x2,
                    double testing_data[][6]) 
{
    if (double_zero_compare (testing_data[test_number][NROOTS] - nRoots) == 0)           // correct returned value of nRoots
    {
        if (nRoots == INF_ROOTS || nRoots == NO_ROOTS)
            return SUCCESS;

        else
        {
            if (double_zero_compare (testing_data[test_number][X1] - ans_x1) == 0 &&     // x1 & x2 are correct roots
                double_zero_compare (testing_data[test_number][X2] - ans_x2) == 0)
                return SUCCESS;
            else
                return UNSUCCESS;
        }
    } else                                                                              // incorrect output data
        return UNSUCCESS;
}                    