#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct Node *PtrToNode;
struct Node
{
    ElementType Data; /* 存储结点数据 */
    PtrToNode Next;   /* 指向下一个结点的指针 */
};
typedef PtrToNode List; /* 定义单链表类型 */

List ReadInput();       /* 裁判实现，细节不表 */
void PrintList(List L); /* 裁判实现，细节不表 */
void K_Reverse(List L, int K);

int main()
{
    List L;
    int K;

    L = ReadInput();
    scanf("%d", &K);
    K_Reverse(L, K);
    PrintList(L);

    return 0;
}

List ReadInput()
{
    int N;
    scanf("%d", &N);
    List L = (List)malloc(sizeof(struct Node));
    L->Next = NULL;
    List last = L;
    for (int i = 0; i < N; i++)
    {
        List p = (List)malloc(sizeof(struct Node));
        scanf("%d", &p->Data);
        p->Next = NULL;
        last->Next = p;
        last = last->Next;
    }
    return L;
}

void PrintList(List L)
{
    List p = L->Next;
    int first = 1;
    while (p)
    {
        if (first)
        {
            printf("%d", p->Data);
            first = 0;
        }
        else
            printf(" %d", p->Data);
        p = p->Next;
    }
}

/* 你的代码将被嵌在这里 */
void K_Reverse(List L, int K)
{
    List pCheck = L->Next;
    int cnt = K;
    while (pCheck && cnt--)
    {
        pCheck = pCheck->Next;
    }
    if (cnt > 0)
        return L;
    int i = 0;
    List old = NULL;
    List new = L->Next;
    List head = L;
    while (1)
    {
        if (i == K)
        {
            i = 0;
            head->Next->Next = new;
            List tmp = head->Next;
            head->Next = old;
            head = tmp;
            old = NULL;
            List pCheck = head->Next;
            int cnt = K;
            while (pCheck && cnt--)
            {
                pCheck = pCheck->Next;
            }
            if (cnt > 0)
                break;
            else
                continue;
        }
        else
        {
            List pNode = new->Next;
            new->Next = old;
            old = new;
            new = pNode;
        }
        i++;
    }
    return;
}