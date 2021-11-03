#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define SIZE 100
char operatorStack[SIZE];
int top = -1;

void push(char item) // function to push
{
    if (top == SIZE - 1){
        printf("Stack Overflown !!! Unable to push");
    }
    else{
        top++;
        operatorStack[top] = item;
    }
}


char pop() // function to pop
{
    char temp;
    if (top == -1){
        printf("Stack Underflown!!! Unable to pop");
    }
    else{
        temp = operatorStack[top];
        top--;
    }
    return temp;
}


int isOperand(char symbol) // check whether a character is operand
{
    if ((symbol >= 'a' && symbol <= 'z') || (symbol >= 'A' && symbol <= 'Z') || (symbol >= 48 && symbol <= 57)){
        return 1;
    }
    else{
        return 0;
    }
}
int isoperator(char symbol) // check whether a character is Operator
{
    if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '^'){
        return 1;
    }
    else{
        return 0;
    }
}


int Precedence(char symbol) // check the priority of the operator
{
    switch (symbol)
    {
    case '^':
        return 3;
        break;
    case '*':
    case '/':
        return 2;
        break;
    case '-':
    case '+':
        return 1;
        break;
    case '(':
        return 0;
        break;
    }
}


void infixToPrefix(char infix[])
{
    char postfix[SIZE], prefix[SIZE], symbol, temp;
    int i, j = 0;
    while (infix[i] != '\0')        //reversed infix to postfix
    {
        symbol = infix[i];
        if (isOperand(symbol)){      // A - Z || a - Z || 0 - 9
            postfix[j] = symbol;
            j++;
        }
        if (symbol == '('){
            push(symbol);
        }
        if (isoperator(symbol)){
            while (Precedence(operatorStack[top]) >= Precedence(symbol))
            {
                temp = pop();
                postfix[j] = temp;
                j++;
            }
            push(symbol);
        }
        if (symbol == ')')
        {
            while (operatorStack[top] != '(')
            {
                temp = pop();
                postfix[j] = temp;
                j++;
            }
            temp = pop();
        }
        i++;
    }
    while (top != -1){       // to pop the charecters from Operator stack untill it becomes empty
        temp = pop();
        postfix[j] = temp;
        j++;
    }
    postfix[j] = '\0';

    i = 0, j = 0;       //loop iterators 
    int postLength = strlen(postfix);

    for (i = postLength - 1; i >= 0; i--)       //Reversing the postfix of reversed infix and store in infix
    {
        prefix[j] = postfix[i];
        j++;
    }
    prefix[j] = '\0';
    printf("\n\t\tprefix expression is : %s\n\n", prefix);
}


int main()
{
    char infix[SIZE], postfix[SIZE], infixReverse[SIZE], symbol, temp;
    int i, j = 0;
    printf("\n===================================== INFIX TO PREFIX CONVERTION =====================================\n");
    printf("\n\t\tEnter a infix Expression : ");
    fgets(infix, SIZE, stdin);
    int length = strlen(infix) - 1;         // last character is '\0' so it is excluded from length

    for (i = length - 1; i >= 0; i--)       // Reversing the input string
    {
        if (infix[i] == '('){           //reversing the brackets
            infixReverse[j] = ')';
            j++;
        }
        else if (infix[i] == ')'){
            infixReverse[j] = '(';
            j++;
        }
        else{
            infixReverse[j] = infix[i];
            j++;
        }
    }
    infixReverse[j] = '\0';

    infixToPrefix(infixReverse);

    return 0;
}
