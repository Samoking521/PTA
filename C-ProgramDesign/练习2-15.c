#include <stdio.h>
#include <math.h>
int main(void)
{
    int N;
    scanf("%d", &N);
    double sum = 0;
    int signal = 1;
    for (int i = 1; i <= N; i++)
    {
        sum += signal * 1.0 / (3 * i - 2);
        signal = -signal;
    }
    printf("sum = %.3lf\n", sum);
    return 0;
}