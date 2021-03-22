#include <stdio.h>
#include <stdlib.h>

#define ERROR -1
typedef char ElementType;
typedef enum
{
    false,
    true
} bool;
typedef int Position;
typedef struct SNode *PtrToSNode;
struct SNode
{
    ElementType *Data; /* 存储元素的数组 */
    Position Top;      /* 栈顶指针       */
    int MaxSize;       /* 堆栈最大容量   */
};
typedef PtrToSNode Stack;

char op[110] = {0};

Stack CreateStack(int MaxSize)
{
    Stack S = (Stack)malloc(sizeof(struct SNode));
    S->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
    S->Top = -1;
    S->MaxSize = MaxSize;
    return S;
}

bool Push(Stack S, ElementType X);
ElementType Pop(Stack S);
bool Empty(Stack S);
void Clear(Stack S);

int main()
{
    Stack S;
    int N, M;
    scanf("%d%d", &N, &M);
    S = CreateStack(M);
    bool error;
    for (int i = 0; i < N; i++)
    {
        memset(op, 0, sizeof(op));
        scanf("%s", &op);
        error = false;
        Clear(S);
        for (int j = 0; error == false; j++)
        {
            if (op[j] == 'S')
            {
                if (!Push(S, 1))
                    error = true;
            }
            else if (op[j] == 'X')
            {
                if (Pop(S) == ERROR)
                    error = true;
            }
            else
                break;
        }
        if (!Empty(S))
            error = true;
        if (error)
            printf("NO");
        else
            printf("YES");
        if (i != N - 1)
            printf("\n");
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