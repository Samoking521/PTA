#include <stdio.h>
#include <stdlib.h>

#define ERROR -100
typedef enum
{
    op,
    num
} Tag;
typedef struct Node *PtrToNode;
struct Node
{
    Tag tag;
    char opname;
    double value;
    PtrToNode Next;
};
typedef PtrToNode List;

List Read();
void Print(List L);
double Cal(char op, double a, double b);

int main()
{
    List L;
    L = Read();
    List pNode = L->Next;
    int error = 0;
    while (pNode->Next)
    {
        PtrToNode p = pNode;
        while (!(p->tag == op && p->Next->tag == num && p->Next->Next->tag == num))
            p = p->Next;
        double ans = Cal(p->opname, p->Next->value, p->Next->Next->value);
        if (ans != ERROR)
        {
            PtrToNode tmp = p->Next->Next->Next;
            free(p->Next->Next);
            free(p->Next);
            p->Next = tmp;

            p->tag = num;
            p->value = ans;
        }
        else
        {
            error = 1;
            break;
        }
    }
    if (error)
        printf("ERROR");
    else
        Print(L);
    return 0;
}

List Read()
{
    List L = (List)malloc(sizeof(struct Node));
    List last = L;

    char input[100] = {0};
    gets(input);
    int sign = 1;
    for (int i = 0; input[i] != '\0';)
    {
        if (input[i] == ' ')
        {
            i++;
            continue;
        }
        else if ('0' <= input[i] && input[i] <= '9')
        {
            double value = input[i] - '0';
            while ('0' <= input[i + 1] && input[i + 1] <= '9')
            {
                i++;
                value = value * 10 + input[i] - '0';
            }
            i++;
            if (input[i] == '.')
            {
                i++;
                double index = 0.1;
                double f = (input[i] - '0') * index;
                while ('0' <= input[i + 1] && input[i + 1] <= '9')
                {
                    i++;
                    index *= 0.1;
                    f = f + (input[i] - '0') * index;
                }
                i++;
                value += f;
            }
            value = value * sign;
            sign = 1;
            List p = (List)malloc(sizeof(struct Node));
            p->Next = NULL;
            p->tag = num;
            p->value = value;
            last->Next = p;
            last = last->Next;
        }
        else
        {
            if ('0' <= input[i + 1] && input[i + 1] <= '9')
            {
                if (input[i] == '+')
                    sign = 1;
                else if (input[i] == '-')
                    sign = -1;
                i++;
                continue;
            }
            List p = (List)malloc(sizeof(struct Node));
            p->Next = NULL;
            p->tag = op;
            p->opname = input[i];
            last->Next = p;
            last = last->Next;
            i++;
        }
    }
    return L;
}

void Print(List L)
{
    List p = L->Next;
    if (p == NULL)
    {
        return;
    }
    printf("%.1f", p->value);
}

double Cal(char op, double a, double b)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return b == 0 ? ERROR : a / b;
    }
}