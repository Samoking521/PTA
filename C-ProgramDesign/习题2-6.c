#include <stdio.h>
#include <math.h>
int main(void)
{
    int N;
    scanf("%d", &N);
    int sum = 0;
    int fac = 1;
    for (int i = 1; i <= N; i++)
    {
        fac *= i;
        sum += fac;
    }
    printf("%d\n", sum);
    return 0;
}