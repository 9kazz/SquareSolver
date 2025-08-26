#ifndef UTILS_H
#define UTILS_H

/*functions*/

    void coef_input(double* coef_a, double* coef_b, double* coef_c); // coef_input

    int user_interface(double coef_a, double coef_b, double coef_c); // interacte with user

    void clean_buffer(void);                                         // clean_buffer: cleans input buffer

    void ans_output (int nRoots, double ans_x1, double ans_x2);      // ans_output

    int double_zero_compare(double double_num);                      //double_zero_compare: compares double number with 0

/*enums*/

    enum Root_options {
        INF_ROOTS = -1, // Infinite number of roots
        NO_ROOTS  =  0,
        ONE_ROOT  =  1,
        TWO_ROOTS =  2 
    };

    enum user_interface_commands {
        DEVELOPER = 1, // correct password to developer mode
        USER      = 0  // user mode
    };

/*definitions*/

               /*colors*/
               
        #define BLUE   "\033[34m"
        #define RED    "\033[31m"
        #define YELLOW "\033[93m" 
        #define GREEN  "\033[32m"

        #define RESET   "\033[0m"

#endif