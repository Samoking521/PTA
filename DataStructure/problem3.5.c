#include <stdio.h>
#include <stdlib.h>

#define ERROR -1

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node
{
    ElementType Data;
    PtrToNode Next;
};
typedef PtrToNode List;

List Read();        /* 细节在此不表 */
void Print(List L); /* 细节在此不表 */

ElementType Find(List L, int m);

int main()
{
    List L;
    int m;
    L = Read();
    scanf("%d", &m);
    printf("%d\n", Find(L, m));
    Print(L);
    return 0;
}

List Read()
{
    List L = (List)malloc(sizeof(struct Node));
    L->Next = NULL;
    List last = L;
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        List pNode = (List)malloc(sizeof(struct Node));
        scanf("%d", &pNode->Data);
        pNode->Next = NULL;
        last->Next = pNode;
        last = last->Next;
    }
    return L;
}

void Print(List L)
{
    List p = L;
    while (p->Next)
    {
        if (p != L)
            printf(" ");
        printf("%d", p->Next->Data);
        p = p->Next;
    }
}

/* 你的代码将被嵌在这里 */
ElementType Find(List L, int m)
{
    List stack = (List)malloc(sizeof(struct Node));
    stack->Next = NULL;
    List p = L;
    while (p->Next)
    {
        List pNode = (List)malloc(sizeof(struct Node));
        pNode->Data = p->Next->Data;
        pNode->Next = stack->Next;
        stack->Next = pNode;

        p = p->Next;
    }

    p = stack;
    while (m && p->Next)
    {
        p = p->Next;
        m--;
    }
    if (m)
        return ERROR;
    else
        return p->Data;
}