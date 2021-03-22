#include <stdio.h>
#include <stdlib.h>

#define ERROR -1
typedef int ElementType;
typedef enum
{
    push,
    pop,
    inject,
    eject,
    end
} Operation;
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
typedef PtrToQNode Deque;

Deque CreateDeque(int MaxSize)
{ /* 注意：为区分空队列和满队列，需要多开辟一个空间 */
    Deque D = (Deque)malloc(sizeof(struct QNode));
    MaxSize++;
    D->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
    D->Front = D->Rear = 0;
    D->MaxSize = MaxSize;
    return D;
}

bool Push(ElementType X, Deque D);
ElementType Pop(Deque D);
bool Inject(ElementType X, Deque D);
ElementType Eject(Deque D);

Operation GetOp();        /* 裁判实现，细节不表 */
void PrintDeque(Deque D); /* 裁判实现，细节不表 */

int main()
{
    ElementType X;
    Deque D;
    int N, done = 0;

    scanf("%d", &N);
    D = CreateDeque(N);
    while (!done)
    {
        Operation op = GetOp();
        switch (op)
        {
        case push:
            scanf("%d", &X);
            if (!Push(X, D))
                printf("Deque is Full!\n");
            break;
        case pop:
            X = Pop(D);
            if (X == ERROR)
                printf("Deque is Empty!\n");
            else
                printf("%d is out\n", X);
            break;
        case inject:
            scanf("%d", &X);
            if (!Inject(X, D))
                printf("Deque is Full!\n");
            break;
        case eject:
            X = Eject(D);
            if (X == ERROR)
                printf("Deque is Empty!\n");
            else
                printf("%d is out\n", X);
            break;
        case end:
            PrintDeque(D);
            done = 1;
            break;
        }
    }
    return 0;
}

Operation GetOp()
{
    char op[10];
    scanf("%s", op);
    if (op[0] == 'P' && op[1] == 'o')
        return pop;
    else if (op[0] == 'P' && op[1] == 'u')
        return push;
    else if (op[0] == 'I')
        return inject;
    else if (op[0] == 'E' && op[1] == 'j')
        return eject;
    else
        return end;
}

void PrintDeque(Deque D)
{
    printf("Inside Deque:");
    Position i = D->Front;
    while (i != D->Rear)
    {
        printf(" %d", D->Data[i]);
        i = (i + 1) % D->MaxSize;
    }
    printf("\n");
}

/* 你的代码将被嵌在这里 */
bool Push(ElementType X, Deque D)
{
    if ((D->Rear + 1) % D->MaxSize == D->Front)
        return false;
    D->Front = (D->Front - 1 + D->MaxSize) % D->MaxSize;
    D->Data[D->Front] = X;
    return true;
}

ElementType Pop(Deque D)
{
    if (D->Front == D->Rear)
        return ERROR;
    ElementType X = D->Data[D->Front];
    D->Front = (D->Front + 1) % D->MaxSize;
    return X;
}

bool Inject(ElementType X, Deque D)
{
    if ((D->Rear + 1) % D->MaxSize == D->Front)
        return false;
    D->Data[D->Rear] = X;
    D->Rear = (D->Rear + 1) % D->MaxSize;
    return true;
}

ElementType Eject(Deque D)
{
    if (D->Front == D->Rear)
        return ERROR;
    D->Rear = (D->Rear - 1 + D->MaxSize) % D->MaxSize;
    return D->Data[D->Rear];
}