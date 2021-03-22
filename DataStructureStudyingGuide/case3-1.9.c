#include <stdio.h>
#include <stdlib.h>

#define ERROR -1
typedef int ElementType;
typedef enum
{
    false,
    true
} bool;
typedef int Position;
typedef struct QNode *PtrToQNode;
struct QNode
{
    ElementType *Data;    /* 存储元素的数组   */
    Position Front, Rear; /* 队列的头、尾指针 */
    int MaxSize;          /* 队列最大容量     */
};
typedef PtrToQNode Queue;

Queue CreateQueue(int MaxSize)
{
    Queue Q = (Queue)malloc(sizeof(struct QNode));
    Q->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
    Q->Front = Q->Rear = 0;
    Q->MaxSize = MaxSize + 1;
    return Q;
}

bool AddQ(Queue Q, ElementType X);
ElementType DeleteQ(Queue Q);
bool IsFull(Queue Q);
bool IsEmpty(Queue Q);

int main()
{
    Queue QA, QB;
    int N;
    scanf("%d", &N);
    QA = CreateQueue(N);
    QB = CreateQueue(N);
    ElementType X;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &X);
        if (X % 2 == 1)
            AddQ(QA, X);
        else
            AddQ(QB, X);
    }
    int ticks = 0;
    int first = 1;
    while (!IsEmpty(QA) || !IsEmpty(QB))
    {
        ticks++;
        X = DeleteQ(QA);
        if (X != ERROR)
            if (first)
            {
                printf("%d", X);
                first = 0;
            }
            else
                printf(" %d", X);
        if (ticks % 2 == 0)
        {
            X = DeleteQ(QB);
            if (X != ERROR)
                if (first)
                {
                    printf("%d", X);
                    first = 0;
                }
                else
                    printf(" %d", X);
        }
    }
    return 0;
}

bool AddQ(Queue Q, ElementType X)
{
    if (IsFull(Q))
    {
        return false;
    }
    Q->Rear = (Q->Rear + 1) % Q->MaxSize;
    Q->Data[Q->Rear] = X;
    return true;
}

ElementType DeleteQ(Queue Q)
{
    if (IsEmpty(Q))
    {
        return ERROR;
    }
    Q->Front = (Q->Front + 1) % Q->MaxSize;
    return Q->Data[Q->Front];
}

bool IsFull(Queue Q)
{
    return ((Q->Rear + 1) % Q->MaxSize == Q->Front);
}

bool IsEmpty(Queue Q)
{
    return (Q->Front == Q->Rear);
}