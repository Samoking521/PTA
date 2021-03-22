#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERROR -1
typedef enum
{
    false,
    true
} bool;
typedef char ElementType;
typedef int Position;
typedef struct SNode *PtrToSNode;
struct SNode
{
    ElementType *Data; /* 存储元素的数组 */
    Position Top;      /* 栈顶指针       */
    int MaxSize;       /* 堆栈最大容量   */
};
typedef PtrToSNode Stack;

Stack CreateStack(int MaxSize)
{
    Stack S = (Stack)malloc(sizeof(struct SNode));
    S->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
    S->Top = -1;
    S->MaxSize = MaxSize;
    return S;
}

int turns[4][4] = {
    {1, 1, 0, 0},
    {1, 1, 0, 0},
    {1, 1, 1, 1},
    {1, 1, 1, 1}};

bool Push(Stack S, ElementType X);
ElementType Pop(Stack S);
ElementType Top(Stack S);
bool Empty(Stack S);
void Clear(Stack S);

bool turn(char left, char right);
int parse(char op);

int main()
{
    Stack S_op;
    S_op = CreateStack(25);
    char expression[100] = {0};
    scanf("%s", expression);
    int len = strlen(expression);
    bool first = true;
    int sign = 1;
    for (int i = 0; i < len;)
    {
        if ('0' <= expression[i] && expression[i] <= '9')
        {
            float num = expression[i] - '0';
            while ('0' <= expression[i + 1] && expression[i + 1] <= '9')
            {
                num = num * 10 + expression[i + 1] - '0';
                i++;
            }
            if (expression[i + 1] == '.')
            {
                i += 2;
                float decimal = (expression[i] - '0') * 0.1;
                while ('0' <= expression[i + 1] && expression[i + 1] <= '9')
                {
                    decimal = decimal * 0.1 + expression[i + 1] - '0';
                    i++;
                }
                num += decimal;
            }
            num *= sign;
            if (first)
            {
                first = false;
                printf("%g", num);
            }
            else
                printf(" %g", num);
            i++;
            sign = 1;
        }
        else if (expression[i] == '\0')
            break;
        else
        {
            if (expression[i] == '(')
                Push(S_op, '(');
            else if (i == 0 || expression[i - 1] == '(')
            {
                sign = expression[i] == '+' ? 1 : -1;
                i++;
                continue;
            }
            else if (Empty(S_op))
                Push(S_op, expression[i]);
            else
            {
                if (expression[i] == ')')
                {
                    while (Top(S_op) != '(')
                    {
                        printf(" %c", Pop(S_op));
                    }
                    Pop(S_op);
                }
                else
                {
                    char top = Top(S_op);
                    if (turn(top, expression[i]))
                    {
                        printf(" %c", top);
                        Pop(S_op);
                        continue;
                    }
                    else
                    {
                        Push(S_op, expression[i]);
                    }
                }
            }
            i++;
        }
    }
    while (!Empty(S_op))
    {
        printf(" %c", Pop(S_op));
    }
    return 0;
}

bool Push(Stack S, ElementType X)
{
    if (S->Top + 1 == S->MaxSize)
    {
        return false;
    }
    S->Data[++S->Top] = X;
    return true;
}

ElementType Pop(Stack S)
{
    if (Empty(S))
    {
        return ERROR;
    }
    return S->Data[S->Top--];
}

ElementType Top(Stack S)
{
    if (Empty(S))
    {
        return ERROR;
    }
    return S->Data[S->Top];
}

bool Empty(Stack S)
{
    if (S->Top == -1)
        return true;
    else
        return false;
}

void Clear(Stack S)
{
    S->Top = -1;
}

bool turn(char left, char right)
{
    if (left == '(')
        return false;
    int l = parse(left);
    int r = parse(right);
    if (0 <= l && l <= 3 && 0 <= r && r <= 3)
        return turns[l][r];
    else
        return false;
}

int parse(char op)
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
    default:
        return ERROR;
    }
}