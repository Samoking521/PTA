#include <stdio.h>
#include <string.h>
char num1[30];
char num2[30];
int index1[10];
int index2[10];
void parse(char* num, int* index)
{
    int n = strlen(num);
    for (int i = 0; i < n; i++)
        index[num[i] - '0']++;
}
void transpose(char* num)
{
    int n = strlen(num);
    for (int i = 0; i < n / 2; i++) {
        char tmp = num[i];
        num[i] = num[n - i - 1];
        num[n - i - 1] = tmp;
    }
}
void cal()
{
    transpose(num1);
    int n = strlen(num1);
    int c = 0;
    for (int i = 0; i < n; i++) {
        num2[i] = (2 * (num1[i] - '0') + c) % 10 + '0';
        c = (2 * (num1[i] - '0') + c) / 10;
    }
    if (c)
        num2[n] = c + '0';
}
int main(void)
{
    memset(num1, 0, sizeof(num1));
    memset(num2, 0, sizeof(num2));
    memset(index1, 0, sizeof(index1));
    memset(index2, 0, sizeof(index2));
    scanf("%s", num1);
    parse(num1, index1);
    cal();
    parse(num2, index2);
    int result = 1;
    for (int i = 0; i < 10; i++) {
        if (index1[i] != index2[i])
            result = 0;
    }
    if (result)
        printf("Yes\n");
    else
        printf("No\n");
    transpose(num2);
    int n = strlen(num2);
    for (int i = 0; i < n; i++)
        printf("%c", num2[i]);
    printf("\n");
    return 0;
}