#include <stdio.h>
#include <stdlib.h>

#define SIZE 100
int top = -1, BinaryStack[SIZE];

void push(int val){
    if (top == SIZE - 1){
        printf("Stack Overflown!!!");
    }
    else{
        top++;
        BinaryStack[top] = val;
    }
}
int pop(){
    int temp;
    if (top == -1){
        printf("Stack UnderFlown!!!");
    }
    else{
        temp = BinaryStack[top];
        top--;
        return temp;
    }
}

int main()
{
    int decimal,reminder=0,temp,length=0;
    printf("Enter Decimal Number : ");
    scanf("%d",&decimal);

    while (decimal != 0){
        reminder = decimal % 2;
        decimal = decimal/2; 
        push(reminder);
        length++;
    }

   while (length!=0)
   {
       printf("%d",pop());
       length--;
   }
   
    
    

    return 0;
}