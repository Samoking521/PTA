#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node
{
    ElementType base;
    ElementType index;
    PtrToNode Next;
};
typedef PtrToNode List;

List Read();        /* 细节在此不表 */
void Print(List L); /* 细节在此不表 */

List Add(List L1, List L2);
List Multiply(List L1, List L2);

int main()
{
    List L1, L2;
    L1 = Read();
    L2 = Read();
    List L_Mul = Multiply(L1, L2);
    List L_Add = Add(L1, L2);
    Print(L_Mul);
    Print(L_Add);
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
        scanf("%d%d", &node->base, &node->index);
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
    {
        printf("0 0\n");
        return;
    }
    while (p)
    {
        if (p != L->Next)
            printf(" ");
        printf("%d %d", p->base, p->index);
        p = p->Next;
    }
    printf("\n");
}

/* 你的代码将被嵌在这里 */
List Add(List L1, List L2)
{
    List p = L1->Next;
    List q = L2->Next;
    List L = (List)malloc(sizeof(struct Node));
    L->Next = NULL;
    List last = L;
    while (p && q)
    {
        List pNode = (List)malloc(sizeof(struct Node));
        pNode->Next = NULL;
        if (p->index > q->index)
        {
            pNode->index = p->index;
            pNode->base = p->base;

            p = p->Next;
        }
        else if (p->index < q->index)
        {
            pNode->index = q->index;
            pNode->base = q->base;

            q = q->Next;
        }
        else
        {
            if (p->base + q->base == 0)
            {
                free(pNode);
                p = p->Next;
                q = q->Next;
                continue;
            }
            else
            {
                pNode->index = p->index;
                pNode->base = p->base + q->base;

                p = p->Next;
                q = q->Next;
            }
        }
        last->Next = pNode;
        last = last->Next;
    }
    while (p)
    {
        List pNode = (List)malloc(sizeof(struct Node));
        pNode->Next = NULL;
        pNode->base = p->base;
        pNode->index = p->index;

        last->Next = pNode;
        last = last->Next;
        p = p->Next;
    }
    while (q)
    {
        List pNode = (List)malloc(sizeof(struct Node));
        pNode->Next = NULL;
        pNode->base = q->base;
        pNode->index = q->index;

        last->Next = pNode;
        last = last->Next;
        q = q->Next;
    }
    return L;
}

List Multiply(List L1, List L2)
{
    List p = L1->Next;

    List L = (List)malloc(sizeof(struct Node));
    L->Next = NULL;
    List last = L;
    while (p)
    {
        List q = L2->Next;
        List pRow = (List)malloc(sizeof(struct Node));
        pRow->Next = NULL;
        List pLast = pRow;
        while (q)
        {
            List pNode = (List)malloc(sizeof(struct Node));
            pNode->base = p->base * q->base;
            pNode->index = p->index + q->index;
            pNode->Next = NULL;

            pLast->Next = pNode;
            pLast = pLast->Next;
            q = q->Next;
        }
        L = Add(L, pRow);
        p = p->Next;
    }
    return L;
}