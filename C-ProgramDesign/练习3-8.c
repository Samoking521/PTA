#include <stdio.h>
int main(void)
{
    printf("[1] apple\n");
    printf("[2] pear\n");
    printf("[3] orange\n");
    printf("[4] grape\n");
    printf("[0] exit\n");
    int input;
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &input);
        if (input)
        {
            switch (input)
            {
            case 1:
                printf("price = 3.00\n");
                break;
            case 2:
                printf("price = 2.50\n");
                break;
            case 3:
                printf("price = 4.10\n");
                break;
            case 4:
                printf("price = 10.20\n");
                break;
            default:
                printf("price = 0.00\n");
                break;
            }
        }
        else
            break;
    }
    return 0;
}