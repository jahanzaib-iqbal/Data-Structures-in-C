#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100
int top = -1, stack[SIZE];

void push(char item)
{
    if (top == SIZE - 1)
    {
        printf("Stack overflow");
    }
    else
    {
        top++;
        stack[top] = item;
    }
}
void pop()
{
    if (top == -1)
        printf("stack underflow ");
    else
    {
        char temp = stack[top];
        top--;
    }
}

int main()
{
    char input[SIZE];
    printf("Enter Expression : ");
    fgets(input, SIZE, stdin);

    for (int i = 0; i < strlen(input); i++)
    {

        if (input[i] == '(' || input[i] == '{' || input[i] == '[')
        {
            push(input[i]);
            continue;
        }
        else if (input[i] == ')' || input[i] == '}' || input[i] == ']')
        {
            if (input[i] == ')')
            {
                if (stack[top] == '(')
                    pop();
                else
                {
                    printf("Expression is Not Balanced!!\n");
                    break;
                }
            }

            if (input[i] == '}')
            {
                if (stack[top] == '{')
                    pop();
                else
                {
                    printf("Expression is Not Balanced!!\n");
                    break;
                }
            }

            if (input[i] == ']')
            {
                if (stack[top] == '[')
                    pop();
                else
                {
                    printf("Expression is Not Balanced!!\n");
                    break;
                }
            }
        }
    }
    if (top == -1)
    {
        printf("Expression is Balanced\n");
    }

    return 0;
}