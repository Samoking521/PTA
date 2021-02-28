#include <stdio.h>
#include <math.h>
int main(void)
{
    int N;
    scanf("%d", &N);
    int ans = N > 0 ? 1 : N < 0 ? -1
                                : 0;
    printf("sign(%d) = %d\n", N, ans);
    return 0;
}