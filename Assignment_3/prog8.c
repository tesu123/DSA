#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

void push(char x)
{
    if (top >= MAX_SIZE - 1)
    {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = x;
}

char pop()
{
    if (top < 0)
    {
        return '\0';
    }
    return stack[top--];
}

int isMatchingPair(char opening, char closing)
{
    if (opening == '(' && closing == ')')
        return 1;
    if (opening == '{' && closing == '}')
        return 1;
    if (opening == '[' && closing == ']')
        return 1;
    return 0;
}

int isBalanced(char *expr)
{
    for (int i = 0; expr[i]; i++)
    {
        if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[')
        {
            push(expr[i]);
        }
        else if (expr[i] == ')' || expr[i] == '}' || expr[i] == ']')
        {
            if (top == -1 || !isMatchingPair(pop(), expr[i]))
            {
                return 0;
            }
        }
    }
    return (top == -1);
}

int main()
{
    char expr[MAX_SIZE];
    printf("Enter an expression: ");
    fgets(expr, MAX_SIZE, stdin);
    expr[strcspn(expr, "\n")] = '\0';

    if (isBalanced(expr))
    {
        printf("Balanced brackets\n");
    }
    else
    {
        printf("Unbalanced brackets\n");
    }

    return 0;
}