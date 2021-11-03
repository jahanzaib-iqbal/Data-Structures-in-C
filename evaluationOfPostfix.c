#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define SIZE 30
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

void pop()      //function to pop
{
    char temp;
    if (top == -1){
        printf("Stack Underflown!!! Unable to pop");
    }
    else{
        temp = operatorStack[top];
        top--;
    }
}


int main()
{
    char postfix[SIZE], symbol, temp;
    int size;
    
    printf("\n=============================\n");
    printf("Enter a Postfix Expression: ");
    fgets(postfix,SIZE,stdin);
    size = strlen(postfix) -1;

    for (int i = 0; i < size; i++){

        symbol = postfix[i];
        if (symbol >= '0' && symbol <= '9'){      //0 - 9
           int n;
            n = symbol - '0';       //to convert char into int
            push(n);
        }

        else{
            int numOne, numTwo, result;

            if (symbol == '+'){
                numTwo = operatorStack[top];
                pop();
                numOne = operatorStack[top];
                pop();

                result = numOne + numTwo;
                push(result);
            }

            else if (symbol == '-'){
                numTwo = operatorStack[top];
                pop();
                numOne = operatorStack[top];
                pop();

                result = numOne - numTwo;
                push(result);
            }
            else if (symbol == '*'){
                numTwo = operatorStack[top];
                pop();
                numOne = operatorStack[top];
                pop();

                result = numOne * numTwo;
                push(result);
            }
            else if (symbol == '/'){
                numTwo = operatorStack[top];
                pop();
                numOne = operatorStack[top];
                pop();

                result = numOne / numTwo;
                push(result);
            }
            else if (symbol == '^'){
                numTwo = operatorStack[top];
                pop();
                numOne = operatorStack[top];
                pop();
                
                result = pow(numOne, numTwo);
                push(result);
            }
        }
    }

    if (top == 0){      //because in the end only one number remains that is the total result of evaluation
        printf("Evaluation of PSN is: %d",operatorStack[top]);
    }
    else{
        printf("Invalid PSN Expresson!!!!");
    }


    return 0;
}
