#include <stdio.h>
int main(void)
{
    int num[3];
    scanf("%d%d%d", &num[0], &num[1], &num[2]);
    for (int i = 0; i < 3; i++)
    {
        for (int j = i; j < 3; j++)
        {
            if (num[i] > num[j])
            {
                int tmp = num[i];
                num[i] = num[j];
                num[j] = tmp;
            }
        }
    }
    for (int i = 0; i < 3; i++)
    {
        printf("%d", num[i]);
        if (i != 2)
            printf("->");
        else
            printf("\n");
    }
    return 0;
}