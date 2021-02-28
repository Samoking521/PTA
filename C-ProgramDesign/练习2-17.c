#include <stdio.h>
#include <math.h>
int main(void)
{
    int n;
    scanf("%d", &n);
    int pow = 1;
    for (int i = 0; i <= n; i++)
    {
        printf("pow(3,%d) = %d\n", i, pow);
        pow *= 3;
    }
    return 0;
}