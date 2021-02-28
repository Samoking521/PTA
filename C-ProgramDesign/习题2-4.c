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
        sum += signal * (double)i / (2 * i - 1);
        signal = -signal;
    }
    printf("%.3lf\n", sum);
    return 0;
}