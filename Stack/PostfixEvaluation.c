#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stack
{
    int size;
    int top;
    char *arr;
};
int stackTop(struct stack *sp)
{
    return sp->arr[sp->top];
}
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(struct stack *ptr, char val)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
char pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return 1;
    else
        return 0;
}
int postfixEva(char *exp)
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    int i = 0;
    int a, b, result;
    while (exp[i] != '\0')
    {
        if (!isOperator(exp[i]))
        {
            push(sp, exp[i]);
        }
        else
        {
            if (!isEmpty(sp))
            {
                a = pop(sp) - 48;
                b = pop(sp) - 48;
                if (exp[i] == '+')
                {
                    result = b + a;
                }
                if (exp[i] == '-')
                {
                    result = b - a;
                }
                if (exp[i] == '*')
                {
                    result = b * a;
                }
                if (exp[i] == '/')
                {
                    result = b / a;
                }
                push(sp, result + 48);
            }
        }
        i++;
    }
    return (stackTop(sp) - 48);
}
int main()
{
    char *postfix = "231*+9-";
    printf("Result of %s evaluated is = %d\n", postfix, postfixEva(postfix));
    return 0;
}