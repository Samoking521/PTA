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
void Print(List L); /* 细节在此不表；空链表将输出NULL */

List Merge(List L1, List L2);

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
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
    if (p == NULL)
        printf("NULL");
    while (p)
    {
        printf("%d ", p->Data);
        p = p->Next;
    }
    printf("\n");
}

/* 你的代码将被嵌在这里 */
List Merge(List L1, List L2)
{
    List L = (List)malloc(sizeof(struct Node));
    List last = L;
    while (L1->Next && L2->Next)
    {
        if (L1->Next->Data <= L2->Next->Data)
        {
            last->Next = L1->Next;
            last = last->Next;
            L1->Next = L1->Next->Next;
        }
        else
        {
            last->Next = L2->Next;
            last = last->Next;
            L2->Next = L2->Next->Next;
        }
    }
    if (L1->Next)
    {
        last->Next = L1->Next;
        L1->Next = NULL;
    }
    if (L2->Next)
    {
        last->Next = L2->Next;
        L2->Next = NULL;
    }
    return L;
}