#include <stdio.h>
#include <string.h>
int cards1[60];
int cards2[60];
int turn[60];
void shuffling()
{
    for (int i = 1; i <= 54; i++) {
        cards2[turn[i]] = cards1[i];
    }
    for (int i = 1; i <= 54; i++) {
        int tmp = cards1[i];
        cards1[i] = cards2[i];
        cards2[i] = tmp;
    }
}
char parseletter(int n)
{
    char s;
    if (1 <= n && n <= 13) {
        s = 'S';
    } else if (14 <= n && n <= 26) {
        s = 'H';
    } else if (27 <= n && n <= 39) {
        s = 'C';
    } else if (40 <= n && n <= 52) {
        s = 'D';
    } else {
        s = 'J';
    }
    return s;
}
int parsenum(int n)
{
    int s;
    if (1 <= n && n <= 13) {
        s = n;
    } else if (14 <= n && n <= 26) {
        s = n - 13;
    } else if (27 <= n && n <= 39) {
        s = n - 26;
    } else if (40 <= n && n <= 52) {
        s = n - 39;
    } else {
        s = n - 52;
    }
    return s;
}
int main(void)
{
    memset(cards1, 0, sizeof(cards1));
    memset(cards2, 0, sizeof(cards2));
    memset(turn, 0, sizeof(turn));
    int K;
    scanf("%d", &K);
    for (int i = 1; i <= 54; i++) {
        scanf("%d", &turn[i]);
        cards1[i] = i;
    }
    for (int i = 0; i < K; i++)
        shuffling();
    for (int i = 1; i <= 54; i++) {
        printf("%c", parseletter(cards1[i]));
        printf("%d", parsenum(cards1[i]));
        if (i != 54)
            printf(" ");
        else
            printf("\n");
    }
    return 0;
}