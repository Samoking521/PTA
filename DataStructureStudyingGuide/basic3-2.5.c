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

void AddQ(ElementType item, Stack S1, Stack S2);
ElementType DeleteQ(Stack S1, Stack S2);

int main()
{
    int N1, N2;
    scanf("%d%d\n", &N1, &N2);
    if (N1 > N2)
    {
        int tmp = N1;
        N1 = N2;
        N2 = tmp;
    }
    Stack S1, S2;
    S1 = CreateStack(N1);
    S2 = CreateStack(N2);
    char op;
    int item;
    while (1)
    {
        scanf("%c", &op);
        if (op == 'T')
            break;
        else if (op == 'D')
        {
            ElementType X = DeleteQ(S1, S2);
            if (X != ERROR)
                printf("%d\n", X);
        }
        else if (op == 'A')
        {
            scanf("%d ", &item);
            AddQ(item, S1, S2);
        }
        else
            continue;
    }
    return 0;
}

void AddQ(ElementType item, Stack S1, Stack S2)
{
    if (IsFull(S1))
    {
        if (IsEmpty(S2))
        {
            ElementType X = Pop(S1);
            while (X != ERROR)
            {
                Push(S2, X);
                X = Pop(S1);
            }
        }
        else
        {
            printf("ERROR:Full\n");
            return;
        }
    }
    Push(S1, item);
}

ElementType DeleteQ(Stack S1, Stack S2)
{
    if (IsEmpty(S1) && IsEmpty(S2))
    {
        printf("ERROR:Empty\n");
        return ERROR;
    }
    else if (!IsEmpty(S2))
    {
        ElementType X = Pop(S2);
        return X;
    }
    else
    {
        ElementType X = Pop(S1);
        while (!IsEmpty(S1))
        {
            Push(S2, X);
            X = Pop(S1);
        }
        return X;
    }
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