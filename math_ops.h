#ifndef MATH_OPS_H
#define MATH_OPS_H

/*functions*/

    void general_solve(double coef_a,  double coef_b, double coef_c, // general_solve: solve any types of the 2nd rate polynom & return nRoots
                       double* ans_x1, double* ans_x2, 
                       int* nRoots);

    int solve_lin(double coef_b, double coef_c, double* ans_x1);     // solve_lin: solves liner equations & returns nRoots

    int solve_quadr(double coef_a,  double coef_b, double coef_c,    // solve_quadr: solves quadratic equations & returns nRoots
                    double* ans_x1, double* ans_x2);             

#endif