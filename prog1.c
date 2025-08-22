#include <stdio.h>
#include <math.h>
#define D_ACCUR 0.0001 //accurancy of double numbers

/*d_0comp: compares double number with 0*/
int d_0comp(double da);

/*solve_lin: solves linal equations & returns nRoots*/
int solve_lin(double coef_b, double coef_c, double* ans_x1);

/*solve_quadr: solves quadratic equations & returns nRoots*/
int solve_quadr(double coef_a, double coef_b, double coef_c,
                double* ans_x1, double* ans_x2);

int main() {
    printf("Solving quadratic equations\n");
    printf("Enter coefficient of the equations: a, b, c\n");
    double coef_a = 0, coef_b = 0, coef_c = 0;
    double ans_x1 = 0, ans_x2 = 0;
    int nRoots = 0;
    scanf("%lg %lg %lg", &coef_a, &coef_b, &coef_c);

    /*checking posible options & calculating roots*/
        /*linal equation*/
    if (d_0comp(coef_a) == 0) { //a = 0
        nRoots = solve_lin(coef_b, coef_c, &ans_x1);
        switch (nRoots) {
            case -1:
                printf("Number of roots: infinity\n");
                break;
            case 0:
                printf("Number of roots: %d\n", nRoots);
                break;
            case 1:
            printf("Number of roots: %d\n", nRoots);
            printf("x = %g\n", ans_x1);
        }
        /*quadratic equations*/
    } else { 
        nRoots = solve_quadr(coef_a, coef_b, coef_c,
                             &ans_x1, &ans_x2);
        printf("Number of roots: %d\n", nRoots);
        switch (nRoots) {
            case 0:
                break;
            case 1:
                printf("x = %g\n", ans_x1);
                break;
            case 2:
                printf("x1 = %g\n", ans_x1);
                printf("x2 = %g\n", ans_x2);
        }
    }
    system("pause");
    return 0;
}

/*d_0comp: compares double number with 0*/
int d_0comp(double da) {
    if (da > D_ACCUR) //da is possitive
        return 1;
    else if (da < -D_ACCUR) //da is negative
        return -1;
    else //consider da as 0
        return 0; 
}

/*solve_lin: solves linal equations & returns nRoots*/
int solve_lin(double coef_b, double coef_c, double* ans_x) {
    if (d_0comp (coef_b) == 0) { //b = 0
        if (d_0comp(coef_c) == 0) // c = 0 ==> equation like 0 = 0
            return -1; //infitite number of roots
        else // equation like const = 0
            return 0;
    } else { // b != 0 ==> common linal equation
        *ans_x = -coef_c / coef_b;
        return 1;
    }
}

/*solve_quadr: solves quadratic equations & returns nRoots*/
int solve_quadr(double coef_a, double coef_b, double coef_c,
                    double* ans_x1, double* ans_x2) {
    static double discr = coef_b*coef_b - 4*coef_a*coef_c;
    static double sqrt_discr = sqrt(discr);

    if (d_0comp(discr) > 0) { //discr > 0
        *ans_x1 = (-coef_b + sqrt_discr) / (2*coef_a);
        *ans_x2 = (-coef_b - sqrt_discr) / (2*coef_a);
        return 2;
    } else if (d_0comp(discr) < 0) {//discr < 0
        return 0;
    } else { //discr = 0
        *ans_x1 = *ans_x2 = (-coef_b) / (2*coef_a);
        return 1; }
}