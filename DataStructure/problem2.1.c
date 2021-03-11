#include <stdio.h>
#include <string.h>

#define MAX 10

struct Node
{
    int Data[MAX];
    int top;
};
typedef struct Node *Stack;

char str[MAX];

int opturn[4][4] = {
    {1, 1, 1, 1},
    {1, 1, 1, 1},
    {1, 1, 1, 1},
    {1, 1, 1, 1}};

int error = 0;

void Push(Stack S, int num);
int Pop(Stack S);
int Top(Stack S);

int Test(int op1, int op2);
int ParseOP(int op);
int Cal(int op, int num1, int num2);

int main()
{
    Stack num = (Stack)malloc(sizeof(struct Node));
    Stack op = (Stack)malloc(sizeof(struct Node));
    num->top = -1;
    op->top = -1;
    scanf("%s", str);
    int ans = 0;
    int i = 0;
    while (1)
    {
        if (error)
            break;
        if (str[i] == '=')
        {
            while (op->top != -1)
            {
                int b = Pop(num);
                int a = Pop(num);
                int c = Cal(Pop(op), a, b);
                Push(num, c);
            }
            break;
        }
        else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
        {
            if (op->top == -1 || Test(Top(op), str[i]) == -1)
            {
                Push(op, str[i]);
                i++;
            }
            else
            {
                int b = Pop(num);
                int a = Pop(num);
                int c = Cal(Pop(op), a, b);
                Push(num, c);
                continue;
            }
        }
        else if ('0' <= str[i] && str[i] <= '9')
        {
            int n = str[i] - '0';
            while ('0' <= str[i + 1] && str[i + 1] <= '9')
            {
                n = n * 10 + str[i + 1] - '0';
                i++;
            }
            Push(num, n);
            i++;
        }
        else
        {
            error = 1;
        }
    }
    if (error)
        printf("ERROR\n");
    else
        printf("%d\n", Top(num));
    return 0;
}

void Push(Stack S, int num)
{
    S->Data[++(S->top)] = num;
}

int Pop(Stack S)
{
    return S->Data[(S->top)--];
}

int Top(Stack S)
{
    return S->Data[S->top];
}

int Test(int op1, int op2)
{
    return opturn[ParseOP(op1)][ParseOP(op2)];
}

int ParseOP(int op)
{
    switch (op)
    {
    case '+':
        return 0;
    case '-':
        return 1;
    case '*':
        return 2;
    case '/':
        return 3;
    }
}

int Cal(int op, int num1, int num2)
{
    switch (op)
    {
    case '+':
        return num1 + num2;
    case '-':
        return num1 - num2;
    case '*':
        return num1 * num2;
    case '/':
        if (num2 == 0)
            return error = 1;
        else
            return num1 / num2;
    }
}