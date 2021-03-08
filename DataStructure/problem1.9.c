#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 10
typedef enum
{
    false,
    true
} bool;
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode
{
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput();       /* 裁判实现，细节不表。元素从下标0开始存储 */
void PrintList(List L); /* 裁判实现，细节不表 */
bool Insert(List L, ElementType X);

int main()
{
    List L;
    ElementType X;

    L = ReadInput();
    scanf("%d", &X);
    if (Insert(L, X) == false)
        printf("Insertion failed.\n");
    PrintList(L);

    return 0;
}

List ReadInput()
{
    List L = (List)malloc(sizeof(struct LNode));
    memset(L, 0, sizeof(struct LNode));
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &(L->Data[i]));
    }
    L->Last = N - 1;
    return L;
}

void PrintList(List L)
{
    for (Position i = 0; i <= L->Last; i++)
    {
        printf("%d", L->Data[i]);
        if (i != L->Last)
            printf(" ");
        else
            printf("\n");
    }
    printf("Last = %d\n", L->Last);
}

/* 你的代码将被嵌在这里 */
bool Insert(List L, ElementType X)
{
    if (L->Last >= MAXSIZE - 1)
        return false;
    Position p = 0;
    while (X < L->Data[p])
        p++;
    if (X == L->Data[p])
        return false;
    Position last = L->Last;
    if (p > last)
        L->Data[p] = X;
    else
    {
        while (last != p)
        {
            L->Data[last + 1] = L->Data[last];
            last--;
        }
        L->Data[p + 1] = L->Data[p];
        L->Data[p] = X;
    }
    L->Last += 1;
    return true;
}