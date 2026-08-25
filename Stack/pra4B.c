#include <stdio.h>
#include <math.h>

int stack[100];
int top = -1;

void push(int value)
{
    stack[++top] = value;
}

int pop()
{
    return stack[top--];
}

int calculate(char op, int op1, int op2)
{
    int r;

    switch(op)
    {
        case '+':
            r = op2 + op1;
            break;

        case '-':
            r = op2 - op1;
            break;

        case '*':
            r = op2 * op1;
            break;

        case '/':
            r = op2 / op1;
            break;

        case '^':
            r = (int)pow(op2, op1);
            break;

        default:
            r = 0;
    }

    return r;
}

int main()
{
    char post[50];
    int i = 0;
    int p1, p2, r;

    printf("Enter postfix expression:");
    scanf("%s", post);

    while(post[i] != '\0')
    {
        if(isdigit(post[i]))
        {
            push(post[i] - '0');
        }
        else
        {
            p1 = pop();
            p2 = pop();

            r = calculate(post[i], p1, p2);

            push(r);
        }

        i++;
    }

    printf("Result = %d\n", pop());

    return 0;
}