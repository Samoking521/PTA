#include <stdio.h>
#include <stdlib.h>

#define ERROR -1
typedef char ElementType;
typedef enum
{
    false,
    true
} bool;
typedef int Position;
typedef struct SNode *PtrToSNode;
struct SNode
{
    ElementType *Data; /* 存储元素的数组 */
    Position Top;      /* 栈顶指针       */
    int MaxSize;       /* 堆栈最大容量   */
};
typedef PtrToSNode Stack;

Stack CreateStack(int MaxSize)
{
    Stack S = (Stack)malloc(sizeof(struct SNode));
    S->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
    S->Top = -1;
    S->MaxSize = MaxSize;
    return S;
}

bool Push(Stack S, ElementType X);
ElementType Pop(Stack S);
bool isRight(char left, char right);

int main()
{
    Stack S;
    S = CreateStack(110);
    char letter;
    int done = false;
    int newline = false;
    while (true)
    {
        scanf("%c", &letter);
        if ('0' <= letter && letter <= '9')
        {
            newline = false;
            continue;
        }
        else if ('A' <= letter && letter <= 'Z')
        {
            newline = false;
            continue;
        }
        else if ('a' <= letter && letter <= 'z')
        {
            newline = false;
            continue;
        }
        else if (letter == '.')
        {
            if (newline == true)
                break;
            else
            {
                newline = false;
                continue;
            }
        }
        else if (letter == '\n')
            newline = true;
        else
        {
            newline = false;
            if (letter == '[' || letter == '(' || letter == '{')
                Push(S, letter);
            else if (letter == ']' || letter == ')' || letter == '}')
            {
                int top = Pop(S);
                if (top == ERROR)
                {
                    printf("NO\n?-%c", letter);
                    done = true;
                    break;
                }
                else
                {
                    if (isRight(top, letter))
                        continue;
                    else
                    {
                        if (top == '*')
                            printf("NO\n/*-?");
                        else
                            printf("NO\n%c-?", top);
                        done = true;
                        break;
                    }
                }
            }
            else if (letter == '/')
            {
                char next;
                scanf("%c", &next);
                if (next == '*')
                    Push(S, next);
                else
                    continue;
            }
            else if (letter == '*')
            {
                char next = 0;
                scanf("%c", &next);
                if (next == '/')
                {
                    int top = Pop(S);
                    if (top == ERROR)
                    {
                        printf("NO\n?-*/");
                        done = true;
                        break;
                    }
                    else
                    {
                        if (top == '*')
                            continue;
                        else
                        {
                            printf("NO\n%c-?", top);
                            done = true;
                            break;
                        }
                    }
                }
                else if (next == ']' || next == ')' || next == '}')
                {
                    int top = Pop(S);
                    if (top == ERROR)
                    {
                        printf("NO\n?-%c", next);
                        done = true;
                        break;
                    }
                    else
                    {
                        if (isRight(top, next))
                            continue;
                        else
                        {
                            if (top == '*')
                                printf("NO\n/*-?");
                            else
                                printf("NO\n%c-?", top);
                            done = true;
                            break;
                        }
                    }
                }
                else
                    continue;
            }
            else
                continue;
        }
    }
    if (done == false)
    {
        if (S->Top != -1)
            printf("NO\n%c-?", S->Data[0]);
        else
            printf("YES");
    }
    return 0;
}

bool Push(Stack S, ElementType X)
{
    if (S->Top == S->MaxSize)
    {
        return false;
    }
    S->Data[++S->Top] = X;
}

ElementType Pop(Stack S)
{
    if (S->Top == -1)
    {
        return ERROR;
    }
    return S->Data[S->Top--];
}

bool isRight(char left, char right)
{
    if (left == '(' && right == ')')
        return true;
    else if (left == '[' && right == ']')
        return true;
    else if (left == '{' && right == '}')
        return true;
    else
        return false;
}