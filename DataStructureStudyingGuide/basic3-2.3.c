#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;

typedef struct Node *PtrToNode;
struct Node
{
    ElementType Data; /* 存储结点数据 */
    PtrToNode Next;   /* 指向下一个结点的指针 */
};
typedef PtrToNode List; /* 定义单链表类型 */

void ReadInput(List L1, List L2);    /* 裁判实现，细节不表 */
void PrintSublist(PtrToNode StartP); /* 裁判实现，细节不表 */
PtrToNode Suffix(List L1, List L2);

int main()
{
    List L1, L2;
    PtrToNode P;

    L1 = (List)malloc(sizeof(struct Node));
    L2 = (List)malloc(sizeof(struct Node));
    L1->Next = L2->Next = NULL;
    ReadInput(L1, L2);
    P = Suffix(L1, L2);
    PrintSublist(P);

    return 0;
}

void ReadInput(List L1, List L2)
{
    char s1[] = "loading";
    char s2[] = "being";

    PtrToNode last = L1;
    for (int i = 0; i < 7; i++)
    {
        PtrToNode p = (PtrToNode)malloc(sizeof(struct Node));
        p->Data = s1[i];
        p->Next = NULL;

        last->Next = p;
        last = last->Next;
    }

    last = L2;
    for (int i = 0; i < 2; i++)
    {
        PtrToNode p = (PtrToNode)malloc(sizeof(struct Node));
        p->Data = s2[i];
        p->Next = NULL;

        last->Next = p;
        last = last->Next;
    }

    PtrToNode pL1 = L1->Next;
    while (pL1->Data != 'i')
        pL1 = pL1->Next;
    last->Next = pL1;
}

void PrintSublist(PtrToNode StartP)
{
    PtrToNode p = StartP;
    while (p)
    {
        printf("%c", p->Data);
        p = p->Next;
    }
}

/* 你的代码将被嵌在这里 */
/*复杂度为O(M*N)
PtrToNode Suffix(List L1, List L2)
{
    PtrToNode StartP;
    PtrToNode pL1 = L1->Next;
    int ok = 1;
    for (; ok && pL1 != NULL; pL1 = pL1->Next)
    {
        PtrToNode pL2 = L2->Next;
        for (; ok && pL2 != NULL; pL2 = pL2->Next)
        {
            if (pL1 == pL2)
            {
                ok = 0;
                StartP = pL1;
            }
        }
    }
    return StartP;
}
*/
/*复杂度为O(M+N)*/
PtrToNode Suffix(List L1, List L2)
{
    int M = 0;
    PtrToNode pL1 = L1->Next;
    while (pL1)
    {
        pL1 = pL1->Next;
        M++;
    }
    int N = 0;
    PtrToNode pL2 = L2->Next;
    while (pL2)
    {
        pL2 = pL2->Next;
        N++;
    }

    pL1 = L1->Next;
    pL2 = L2->Next;
    if (M >= N)
    {
        int delta = M - N;
        while (delta--)
            pL1 = pL1->Next;
    }
    else
    {
        int delta = N - M;
        while (delta--)
            pL2 = pL2->Next;
    }
    for (; pL1 != pL2;)
    {
        pL1 = pL1->Next;
        pL2 = pL2->Next;
    }
    return pL1;
}