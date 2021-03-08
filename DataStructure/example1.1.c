#include <stdio.h>
int main(void)
{
    int K, num;
    scanf("%d", &K);
    int sum = 0;
    int max = 0;
    for (int i = 0; i < K; i++)
    {
        scanf("%d", &num);
        sum += num;
        if (sum >= max)
            max = sum;
        else if (sum < 0)
            sum = 0;
    }
    printf("%d", max);
    return 0;
}