#include <stdio.h>
#include <math.h>
/*solve_quadr: solves quadratic equations & returns nRoots*/
int solve_quadr(double coef_a, double coef_b, double coef_c,
                double* ans_x1, double* ans_x2);

main() {
printf("Solving quadratic equations\n");
printf("Enter coefficient of the equations: a, b, c\n");
double coef_a = 0, coef_b = 0, coef_c = 0;
double ans_x1 = 0, ans_x2 = 0;
int nRoots = 0;
scanf("%g %g %g", coef_a, coef_b, coef_c);

/*checking posible options & calculating roots*/
if (coef_a == 0) { //isn't quadratic equations, linal one

}
else {
    printf("Number of roots: %d\n", solve_quadr(coef_a, coef_b, coef_c,
                                                &ans_x1, &ans_x2));
    printf("x1 = %d\n", ans_x1);
    printf("x2 = %d\n", ans_x2);
}
system("pause");
return 0;
}

/*solve_quadr: solves quadratic equations & returns nRoots*/
int solve_quadr(double coef_a, double coef_b, double coef_c,
                double* ans_x1, double* ans_x2) {
double discr = coef_b*coef_b - 4*coef_a*coef_b; 
switch ((discr > 0) ? 1 : 0) {
case 1: //discr > 0
    nRoots = 2;
    *ans_x1 = (-b + sqrt(discr)) / (2*a);
    *ans_x2 = (-b - sqrt(discr)) / (2*a);
    return nRoots;
case 0: //discr < 0
    nRoots = 0;
    return nRoots;
default: //discr = 0
    nRoots = 1;
    ans_x1 = ans_x2 = (-b) / (2*);
}
}