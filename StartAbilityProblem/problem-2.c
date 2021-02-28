#include <math.h>
#include <stdio.h>

int isprime(int n)
{
    if (n == 2 || n == 3)
        return 1;
    int border = sqrt(n);
    for (int i = 2; i <= border; i++) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}
int main(void)
{
    int N;
    scanf("%d", &N);
    int ans = 0;
    int a = 2;
    int b;
    for (int i = 3; i <= N; i++) {
        if (isprime(i)) {
            if (i - a == 2)
                ans++;
            a = i;
        }
    }
    printf("%d\n", ans);
    return 0;
}