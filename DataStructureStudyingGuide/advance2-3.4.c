#include <stdio.h>
#include <math.h>

void solve(int last, int N);
int isPrime(int N);
int first = 1;

int main()
{
    long int N;
    scanf("%d", &N);
    if (N == 1)
        printf("1=1\n");
    else
    {
        printf("%d=", N);
        solve(1, N);
    }
    return 0;
}

void solve(int last, int N)
{
    if (N == 1)
        return;
    for (int i = last + 1; i <= N; i++)
    {
        if (isPrime(i))
        {
            int n = N;
            int p = 0;
            while (n % i == 0)
            {
                p++;
                n /= i;
            }
            if (p)
            {
                if (first)
                    first = 0;
                else
                    printf("*");
                if (p == 1)
                    printf("%d", i);
                else
                    printf("%d^%d", i, p);
                solve(i, n);
                break;
            }
        }
    }
}

int isPrime(int N)
{
    if (N == 2 || N == 3)
        return 1;
    int res = 1;
    for (int i = 2; i <= sqrt(N); i++)
        if (N % i == 0)
        {
            res = 0;
            break;
        }
    return res;
}
