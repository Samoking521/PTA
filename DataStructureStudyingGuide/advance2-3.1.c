#include <stdio.h>

#define MAX 110

int Person[MAX] = {0};
int flag[MAX] = {0};

int main()
{
    int D, P;
    scanf("%d%d", &D, &P);
    Person[P - 2] = D - 1;
    Person[P - 1] = 1;
    Person[P] = 0;
    int money;
    int tickets;
    int min;
    int min_pos;
    for (int i = 4; i <= P; i++)
    {
        money = D;
        tickets = i / 2;
        memset(flag, 0, sizeof(flag));
        for (int j = tickets; j > 0; j--)
        {
            min = D;
            for (int k = P - i + 2; k <= P; k++)
            {
                if (flag[k])
                    continue;
                if (Person[k] < min)
                {
                    min = Person[k];
                    min_pos = k;
                }
            }
            Person[min_pos]++;
            flag[min_pos] = 1;
            money -= Person[min_pos];
        }
        for (int j = P - i + 2; j <= P; j++)
        {
            if (flag[j] == 0)
                Person[j] = 0;
        }
        Person[P - i + 1] = money;
    }
    printf("%d\n", Person[1]);
    return 0;
}
