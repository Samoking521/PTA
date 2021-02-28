#include <stdio.h>
int main(void)
{
    int score;
    scanf("%d", &score);
    if (score >= 90)
        printf("A\n");
    else if (80 <= score && score < 90)
        printf("B\n");
    else if (70 <= score && score < 80)
        printf("C\n");
    else if (60 <= score && score < 70)
        printf("D\n");
    else
        printf("E\n");
    return 0;
}