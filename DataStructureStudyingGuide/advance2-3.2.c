#include <stdio.h>

#define MAX 110

int num[5] = {0};
int num_turn[24][4] = {
    {1, 2, 3, 4},
    {1, 2, 4, 3},
    {1, 3, 2, 4},
    {1, 3, 4, 2},
    {1, 4, 2, 3},
    {1, 4, 3, 2},
    {2, 1, 3, 4},
    {2, 1, 4, 3},
    {2, 3, 1, 4},
    {2, 3, 4, 1},
    {2, 4, 1, 3},
    {2, 4, 3, 1},
    {3, 1, 2, 4},
    {3, 1, 4, 2},
    {3, 2, 1, 4},
    {3, 2, 4, 1},
    {3, 4, 1, 2},
    {3, 4, 2, 1},
    {4, 1, 2, 3},
    {4, 1, 3, 2},
    {4, 2, 1, 3},
    {4, 2, 3, 1},
    {4, 3, 1, 2},
    {4, 3, 2, 1},
};
int op_turn[64][3] = {
    {0, 0, 0},
    {0, 0, 1},
    {0, 0, 2},
    {0, 0, 3},
    {0, 1, 0},
    {0, 1, 1},
    {0, 1, 2},
    {0, 1, 3},
    {0, 2, 0},
    {0, 2, 1},
    {0, 2, 2},
    {0, 2, 3},
    {0, 3, 0},
    {0, 3, 1},
    {0, 3, 2},
    {0, 3, 3},
    {1, 0, 0},
    {1, 0, 1},
    {1, 0, 2},
    {1, 0, 3},
    {1, 1, 0},
    {1, 1, 1},
    {1, 1, 2},
    {1, 1, 3},
    {1, 2, 0},
    {1, 2, 1},
    {1, 2, 2},
    {1, 2, 3},
    {1, 3, 0},
    {1, 3, 1},
    {1, 3, 2},
    {1, 3, 3},
    {2, 0, 0},
    {2, 0, 1},
    {2, 0, 2},
    {2, 0, 3},
    {2, 1, 0},
    {2, 1, 1},
    {2, 1, 2},
    {2, 1, 3},
    {2, 2, 0},
    {2, 2, 1},
    {2, 2, 2},
    {2, 2, 3},
    {2, 3, 0},
    {2, 3, 1},
    {2, 3, 2},
    {2, 3, 3},
    {3, 0, 0},
    {3, 0, 1},
    {3, 0, 2},
    {3, 0, 3},
    {3, 1, 0},
    {3, 1, 1},
    {3, 1, 2},
    {3, 1, 3},
    {3, 2, 0},
    {3, 2, 1},
    {3, 2, 2},
    {3, 2, 3},
    {3, 3, 0},
    {3, 3, 1},
    {3, 3, 2},
    {3, 3, 3},
};

double cal(double a, double b, int op);
void print(int i, int j, int k);
char parseop(int j);

int main()
{
    for (int i = 1; i <= 4; i++)
        scanf("%d", &num[i]);
    double tmp1, tmp2, ans;
    for (int i = 0; i < 24; i++)
    {
        for (int j = 0; j < 64; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                if (k == 0)
                {
                    tmp1 = cal(num[num_turn[i][0]], num[num_turn[i][1]], op_turn[j][0]);
                    tmp2 = cal(tmp1, num[num_turn[i][2]], op_turn[j][1]);
                    ans = cal(tmp2, num[num_turn[i][3]], op_turn[j][2]);
                }
                else if (k == 1)
                {
                    tmp1 = cal(num[num_turn[i][0]], num[num_turn[i][1]], op_turn[j][0]);
                    tmp2 = cal(num[num_turn[i][2]], num[num_turn[i][3]], op_turn[j][2]);
                    ans = cal(tmp1, tmp2, op_turn[j][1]);
                }
                else if (k == 2)
                {
                    tmp1 = cal(num[num_turn[i][1]], num[num_turn[i][2]], op_turn[j][1]);
                    tmp2 = cal(num[num_turn[i][0]], tmp1, op_turn[j][0]);
                    ans = cal(tmp2, num[num_turn[i][3]], op_turn[j][2]);
                }
                else if (k == 3)
                {
                    tmp1 = cal(num[num_turn[i][1]], num[num_turn[i][2]], op_turn[j][1]);
                    tmp2 = cal(tmp1, num[num_turn[i][3]], op_turn[j][2]);
                    ans = cal(num[num_turn[i][0]], tmp2, op_turn[j][0]);
                }
                else if (k == 4)
                {
                    tmp1 = cal(num[num_turn[i][2]], num[num_turn[i][3]], op_turn[j][2]);
                    tmp2 = cal(num[num_turn[i][1]], tmp1, op_turn[j][1]);
                    ans = cal(num[num_turn[i][0]], tmp2, op_turn[j][0]);
                }
                if (ans == 24)
                {
                    print(i, j, k);
                    return 0;
                }
            }
        }
    }
    printf("-1\n");
    return 0;
}

double cal(double a, double b, int op)
{
    switch (op)
    {
    case 0:
        return a + b;
    case 1:
        return a - b;
    case 2:
        return a * b;
    case 3:
        return b == 0 ? -1 : a / b;
    }
}

void print(int i, int j, int k)
{
    if (k == 0)
        printf("((");
    else if (k == 1 || k == 2)
        printf("(");
    printf("%d", num[num_turn[i][0]]);
    printf("%c", parseop(op_turn[j][0]));
    if (k == 3)
        printf("((");
    else if (k == 2 || k == 4)
        printf("(");
    printf("%d", num[num_turn[i][1]]);
    if (k == 0 || k == 1)
        printf(")");
    printf("%c", parseop(op_turn[j][1]));
    if (k == 1 || k == 4)
        printf("(");
    printf("%d", num[num_turn[i][2]]);
    if (k == 2)
        printf("))");
    else if (k == 0 || k == 3)
        printf(")");
    printf("%c", parseop(op_turn[j][2]));
    printf("%d", num[num_turn[i][3]]);
    if (k == 4)
        printf("))");
    else if (k == 1 || k == 3)
        printf(")");
    printf("\n");
}

char parseop(int j)
{
    switch (j)
    {
    case 0:
        return '+';
    case 1:
        return '-';
    case 2:
        return '*';
    case 3:
        return '/';
    }
}