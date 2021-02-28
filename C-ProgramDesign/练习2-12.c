#include <stdio.h>
#include <math.h>
int main(void)
{
    int lower, upper;
    scanf("%d%d", &lower, &upper);
    if (lower > upper)
    {
        printf("Invalid.\n");
    }
    else
    {
        printf("fahr celsius\n");
        for (int i = lower; i <= upper; i += 2)
        {
            printf("%d%6.1f\n", i, 5 * (i - 32) / 9.0);
        }
    }
    return 0;
}