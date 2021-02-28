#include <stdio.h>
int main(void)
{
    int year;
    scanf("%d", &year);
    if (year <= 2000 || year >= 2101)
        printf("Invalid year!\n");
    else if (2001 <= year && year <= 2003)
        printf("None\n");
    else
    {
        for (int i = 2004; i <= year && i < 2100; i += 4)
            printf("%d\n", i);
    }
    return 0;
}