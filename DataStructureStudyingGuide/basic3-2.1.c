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

List Read();
void Print(List L);

List Derivation(List L);

int main()
{
    List L;
    L = Read();
    List L_ans = Derivation(L);
    Print(L_ans);
    return 0;
}

List Read()
{
    List L = (List)malloc(sizeof(struct Node));
    List last = L;
    int base, index;
    while (scanf("%d%d", &base, &index) == 2)
    {
        List node = (List)malloc(sizeof(struct Node));
        node->Next = NULL;
        node->base = base;
        node->index = index;

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

List Derivation(List L)
{
    List p = L;
    while (p->Next)
    {
        if (p->Next->index == 0)
            p->Next = NULL;
        else
        {
            p->Next->base = p->Next->base * p->Next->index;
            p->Next->index = p->Next->index - 1;
            p = p->Next;
        }
    }
    return L;
}
