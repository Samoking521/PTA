#include <stdio.h>
#include <stdlib.h>

#define ERROR -1
typedef int ElementType;
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
ElementType Top(Stack S);
bool IsEmpty(Stack S);
bool IsFull(Stack S);
void Clear(Stack S);

int data[1010] = {0};

int main()
{
    int M, N, K;
    scanf("%d%d%d", &M, &N, &K);
    Stack S;
    S = CreateStack(M);
    int ok = false;
    int k;
    for (int i = 0; i < K; i++)
    {
        for (int i = 0; i < N; i++)
            scanf("%d", &data[i]);
        Clear(S);
        ok = true;
        k = 1;
        for (int i = 0; i < N;)
        {
            if (!IsEmpty(S) && data[i] == Top(S))
            {
                Pop(S);
                i++;
            }
            else
            {
                if (Push(S, k) == false)
                {
                    break;
                }
                k++;
            }
        }
        ok = IsEmpty(S) ? true : false;
        if (ok)
            printf("YES");
        else
            printf("NO");
        if (i + 1 != N)
            printf("\n");
    }
    return 0;
}

bool Push(Stack S, ElementType X)
{
    if (IsFull(S))
    {
        return false;
    }
    S->Data[++S->Top] = X;
    return true;
}

ElementType Pop(Stack S)
{
    if (IsEmpty(S))
    {
        return ERROR;
    }
    return S->Data[S->Top--];
}

ElementType Top(Stack S)
{
    if (IsEmpty(S))
    {
        return ERROR;
    }
    return S->Data[S->Top];
}

bool IsEmpty(Stack S)
{
    if (S->Top == -1)
        return true;
    else
        return false;
}

bool IsFull(Stack S)
{
    if (S->Top + 1 == S->MaxSize)
        return true;
    else
        return false;
}

void Clear(Stack S)
{
    S->Top = -1;
}