#include <stdio.h>
#include <stdlib.h>

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

List Insert(List L, ElementType X);

int main()
{
    List L;
    ElementType X;
    L = Read();
    scanf("%d", &X);
    L = Insert(L, X);
    Print(L);
    return 0;
}

List Read()
{
    int N;
    scanf("%d", &N);
    List L = (List)malloc(sizeof(struct Node));
    List last = L;
    for (int i = 0; i < N; i++)
    {
        List node = (List)malloc(sizeof(struct Node));
        scanf("%d", &node->Data);
        node->Next = NULL;

        last->Next = node;
        last = node;
    }
    return L;
}

void Print(List L)
{
    List p = L->Next;
    while (p)
    {
        printf("%d ", p->Data);
        p = p->Next;
    }
}

/* 你的代码将被嵌在这里 */
List Insert(List L, ElementType X)
{
    List p = L;
    while (p->Next && p->Next->Data < X)
        p = p->Next;
    List node = (List)malloc(sizeof(struct Node));
    node->Data = X;
    node->Next = p->Next;
    p->Next = node;
    return L;
}