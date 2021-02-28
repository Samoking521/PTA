#include <stdio.h>
int main(void)
{
    double x;
    scanf("%lf", &x);
    double y = x > 0 ? x : -x;
    printf("f(%.1lf) = %.1lf\n", x, (y - 0) < 1e-9 ? 0 : 1 / x);
    return 0;
}