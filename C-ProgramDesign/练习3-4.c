#include <stdio.h>
int main(void)
{
    int letter = 0;
    int blank = 0;
    int digit = 0;
    int other = 0;
    int c;
    for (int i = 0; i < 10; i++)
    {
        c = getchar();
        if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'))
            letter++;
        else if (c == ' ' || c == '\n')
            blank++;
        else if ('0' <= c && c <= '9')
            digit++;
        else
            other++;
    }
    printf("letter = %d, blank = %d, digit = %d, other = %d\n", letter, blank, digit, other);
    return 0;
}