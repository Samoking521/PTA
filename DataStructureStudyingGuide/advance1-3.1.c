#include <stdio.h>

#define MAXSIZE 100010
int arr1[MAXSIZE] = {0};
int arr2[MAXSIZE] = {0};

int main(void)
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &arr1[i]);
    for (int i = 0; i < N; i++)
        scanf("%d", &arr2[i]);
    int p, q, ans;
    p = 0;
    q = 0;
    for (int i = 0; i < (2 * N + 1) / 2; i++)
    {
        if (arr1[p] <= arr2[q])
        {
            ans = arr1[p];
            p++;
        }
        else
        {
            ans = arr2[q];
            q++;
        }
    }
    printf("%d", ans);
    return 0;
}