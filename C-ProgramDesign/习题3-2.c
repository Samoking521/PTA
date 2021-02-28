#include <stdio.h>
int main(void)
{
    int speed, limit;
    scanf("%d%d", &speed, &limit);
    if (limit * 1.1 > speed)
        printf("OK\n");
    else
    {
        int per = (speed - limit) / (double)limit;
        if (per >= 50)
            printf("Exceed %d%%. License Revoked\n", per);
        else
            printf("Exceed %d%%. Ticket 200\n", per);
    }
    return 0;
}