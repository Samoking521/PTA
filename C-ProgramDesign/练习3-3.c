#include <stdio.h>
int main(void)
{
    int n, score;
    int sum = 0;
    int cnt = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &score);
        sum += score;
        if (score >= 60)
            cnt++;
    }
    if (n)
        printf("average = %.1lf\n", (double)sum / n);
    else
        printf("average = 0.0\n");
    printf("count = %d\n", cnt);
    return 0;
}