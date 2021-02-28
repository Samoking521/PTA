#include <stdio.h>
double fact(int n)
{
    if (n == 0 || n == 1)
        return 1;
    double ans = 1;
    do
    {
        ans *= n;
    } while (--n);
    return ans;
}

int main(void)
{
    int m, n;
    scanf("%d%d", &m, &n);
    printf("result = %.0lf\n", fact(n) / (fact(m) * fact(n - m)));
    return 0;
}