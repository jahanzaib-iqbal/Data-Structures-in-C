#include <stdio.h>
#include <stdlib.h>

#define SIZE 100
char operatorStack[SIZE];
int top = -1;

void push(char item)        //function to push 
{
    if (top == SIZE - 1){
        printf("Stack Overflown !!! Unable to push");
    }
    else{
        top++;
        operatorStack[top] = item;
    }
}

char pop()      //function to pop
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

int isOperand(char symbol)  //check whether a character is operand 
{
    if ((symbol >= 'a' && symbol <= 'z') || (symbol >= 'A' && symbol <= 'Z') || (symbol >= 48 && symbol <= 57))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isoperator(char symbol)     //check whether a character is Operator
{
    if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '^')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Precedence(char symbol)     //check the priority of the operator
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

int main()
{
    char infix[SIZE], postfix[SIZE], symbol, temp;
    int i,j = 0;
    printf("\n============================\n");
    printf("Enter a infix Expression : ");
    fgets(infix,SIZE,stdin);

    while (infix[i] != '\0')
    {

        symbol = infix[i];
        if (isOperand(symbol)){ // A - Z || a - Z || 0 - 9
            postfix[j] = symbol;
            j++;
        }
        if (symbol == '('){
            push(symbol);
        }
        if (isoperator(symbol)){
            while (Precedence(operatorStack[top]) >= Precedence(symbol)){
                temp = pop();
                postfix[j] = temp;
                j++;
            }
            push(symbol);
        }
        if (symbol == ')'){
            while (operatorStack[top] != '('){
                temp = pop();
                postfix[j] = temp;
                j++;
            }
            temp = pop();
        }
        i++;
    }
    while (top != -1 ){     //to pop the charecters from Operator stack untill it becomes empty
        temp = pop();
        postfix[j] = temp;
        j++;
    }
    postfix[j] = '\0';
    printf("\npostfix expression is %s", postfix);

    return 0;
}
