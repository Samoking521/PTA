#include <stdio.h>
#include <stdlib.h>

#define ERROR -1
struct PNode
{
    int size;
    char start;
    char mid;
    char end;
};
typedef struct PNode *ElementType;
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
bool Empty(Stack S);
void Clear(Stack S);

int main()
{
    Stack S;
    int N;
    scanf("%d", &N);
    S = CreateStack(N * N);
    struct PNode solve_0 = {N, 'a', 'b', 'c'};
    Push(S, &solve_0);
    while (!Empty(S))
    {
        ElementType pSolve = Pop(S);
        if (pSolve->size == 1)
            printf("%c -> %c\n", pSolve->start, pSolve->end);
        else
        {
            struct PNode solve_1 = {pSolve->size - 1, pSolve->mid, pSolve->start, pSolve->end};
            Push(S, &solve_1);
            struct PNode solve_2 = {1, pSolve->start, pSolve->mid, pSolve->end};
            Push(S, &solve_2);
            struct PNode solve_3 = {pSolve->size - 1, pSolve->start, pSolve->end, pSolve->mid};
            Push(S, &solve_3);
        }
    }
    return 0;
}

bool Push(Stack S, ElementType X)
{
    if (S->Top + 1 == S->MaxSize)
    {
        return false;
    }
    ElementType pToX = (ElementType)malloc(sizeof(struct PNode));
    pToX->size = X->size;
    pToX->start = X->start;
    pToX->mid = X->mid;
    pToX->end = X->end;
    S->Data[++S->Top] = pToX;
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