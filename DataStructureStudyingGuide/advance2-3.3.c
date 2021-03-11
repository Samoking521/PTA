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

List Read();
void Print(List L);
List Merge(List L1, List L2);

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    return 0;
}

List Read()
{
    int N;
    List L = (List)malloc(sizeof(struct Node));
    List last = L;
    while (scanf("%d", &N) == 1)
    {
        if (N == -1)
            break;
        List node = (List)malloc(sizeof(struct Node));
        node->Data = N;
        node->Next = NULL;

        last->Next = node;
        last = node;
    }
    return L;
}

void Print(List L)
{
    List p = L->Next;
    if (p)
        while (p)
        {
            printf("%d", p->Data);
            if (p->Next)
                printf(" ");
            p = p->Next;
        }
    else
        printf("NULL");
    printf("\n");
}

List Merge(List L1, List L2)
{
    List L = (List)malloc(sizeof(struct Node));
    L->Next = NULL;
    List last = L;
    List p = L1->Next;
    List q = L2->Next;
    while (p && q)
    {
        if (p->Data < q->Data)
            p = p->Next;
        else if (p->Data > q->Data)
            q = q->Next;
        else
        {
            List node = (List)malloc(sizeof(struct Node));
            node->Data = p->Data;
            node->Next = NULL;

            last->Next = node;
            last = node;

            p = p->Next;
            q = q->Next;
        }
    }
    return L;
}
