#include <stdio.h>

#define MAXSIZE 20
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
List Delete(List L, ElementType minD, ElementType maxD);

int main()
{
    List L;
    ElementType minD, maxD;
    int i;

    L = ReadInput();
    scanf("%d %d", &minD, &maxD);
    L = Delete(L, minD, maxD);
    PrintList(L);

    return 0;
}

List ReadInput()
{
    List L = (List)malloc(sizeof(struct LNode));
    scanf("%d", &L->Last);
    L->Last -= 1;
    for (int i = 0; i <= L->Last; i++)
        scanf("%d", &L->Data[i]);
    return L;
}

void PrintList(List L)
{
    for (int i = 0; i <= L->Last; i++)
    {
        if (i != 0)
            printf(" ");
        printf("%d", L->Data[i]);
    }
}

/* 你的代码将被嵌在这里 */
List Delete(List L, ElementType minD, ElementType maxD)
{
    int queue[MAXSIZE + 1] = {0};
    int front = 0;
    int rear = 0;
    int last = -1;
    for (int i = 0; i <= L->Last; i++)
    {
        if (minD < L->Data[i] && L->Data[i] < maxD)
        {
            queue[++rear] = i;
        }
        else if (rear - front > 0)
        {
            int del = queue[++front];
            L->Data[del] = L->Data[i];
            queue[++rear] = i;
            last = del;
        }
    }
    L->Last = rear ? last : L->Last;
    return L;
}