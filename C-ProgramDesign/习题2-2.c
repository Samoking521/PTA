#include <stdio.h>
int main(void)
{
    int x;
    scanf("%d", &x);
    if (x < 0)
        printf("Invalid Value!\n");
    else if (x <= 50)
        printf("cost = %.2lf\n", 0.53 * x);
    else
        printf("cost = %.2lf\n", 0.53 * 50 + 0.58 * (x - 50));
    return 0;
}