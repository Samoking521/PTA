#include <stdio.h>

#define MAX 1010

int num[MAX] = {0};

int main()
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &num[i]);
    int A1, A2, A3;

    A1 = -1;
    for (int i = 0; i < N; i++)
        if (num[i] % 3 == 0 && num[i] > A1)
            A1 = num[i];
    if (A1 == -1)
        printf("NONE ");
    else
        printf("%d ", A1);

    A2 = 0;
    for (int i = 0; i < N; i++)
        if (num[i] % 3 == 1)
            A2++;
    if (A2 == 0)
        printf("NONE ");
    else
        printf("%d ", A2);

    A3 = 0;
    int cnt = 0;
    for (int i = 0; i < N; i++)
        if (num[i] % 3 == 2)
        {
            A3 += num[i];
            cnt++;
        }
    if (A3 == 0)
        printf("NONE");
    else
        printf("%.1f", A3 / (double)cnt);
    return 0;
}
