#ifndef UNIT_TESTS_H
#define UNIT_TESTS_H

/*functions*/

    void utest_general_solve(void);

    int utest_checking (int test_number, int nRoots, 
                        double ans_x1,   double ans_x2,
                        double testing_data[][6]);

/*enums*/

    enum utest_checking_Results {
        UNSUCCESS = 0,
        SUCCESS   = 1
    };

    enum testing_data_Columns {
        A      = 0,
        B      = 1,
        C      = 2,
        NROOTS = 3,
        X1     = 4,
        X2     = 5
    };

#endif