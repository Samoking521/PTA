#include <stdio.h>
#include <math.h>

#define MAX 10010

int num[MAX] = {0};

int main()
{
    int N;
    int sum = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &num[i]);
        sum += num[i];
    }
    double avg = sum / (double)N;
    double ans = 0;
    for (int i = 0; i < N; i++)
    {
        ans += (num[i] - avg) * (num[i] - avg);
    }
    ans /= N;
    printf("%.5f\n", sqrt(ans));
    return 0;
}
