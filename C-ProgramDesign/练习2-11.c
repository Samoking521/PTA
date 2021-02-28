#include <stdio.h>
#include <math.h>
int main(void)
{
    double x, y;
    scanf("%lf", &x);
    if (x >= 0)
        y = sqrt(x);
    else
        y = pow(x + 1, 2.0) + 2 * x + 1 / x;
    printf("f(%.2lf) = %.2lf\n", x, y);
    return 0;
}