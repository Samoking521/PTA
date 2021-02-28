#include <stdio.h>
#include <math.h>
int main(void)
{
    int N;
    scanf("%d", &N);
    double sum = 0;
    for (int i = 1; i <= N; i++)
    {
        sum += sqrt(i);
    }
    printf("sum = %.2lf\n", sum);
    return 0;
}