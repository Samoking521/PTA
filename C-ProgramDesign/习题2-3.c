#include <stdio.h>
int main(void)
{
    int m, n;
    scanf("%d%d", &m, &n);
    double sum = 0;
    for (; m <= n; m++)
    {
        sum += m * m;
        sum += 1.0 / m;
    }
    printf("sum = %.6lf", sum);
    return 0;
}