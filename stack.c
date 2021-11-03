#include <stdio.h>
#include <stdlib.h>
#define size 100

int main()
{

    int stack[size] = {0}, top = -1;
    int choice;
    do
    {
        printf("\n==========================================\n\t Enter 1 to insert \n\t Enter 2 to delete \n\t Enter 3 to display\n\t Enter 0 to exit \n\t choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            if (top == size - 1)
            {
                printf("Stack is full!!!!\n");
                break;
            }
            else
            {
                int val;
                printf("Enter the value that you want to insert : ");
                scanf("%d", &val);
                top++;
                stack[top] = val;
                printf("\n====================================\nStack After Insertion :   ");

                for (int i = top; i >= 0; i--)
                {
                    printf("%d\t", stack[i]);
                }
            }
            break;
        }
        case 2:
        {
            if (top == -1)
            {
                printf("\nStack is under flown(empty) !!!\n");
            }
            else
            {
                int temp;
                temp = stack[top];
                top--;
                printf("\n==========================================\nStack After deletion :   ");
                for (int i = top; i >= 0; i--)
                {
                    printf("%d\t", stack[i]);
                }
            }
            break;
        }
        case 3:
        {
            // display(stack,top,size);
            if (top == -1)
                printf("\nStack is empty\n");
            else
            {
                printf("\n=========================\nPrinting Stack\n===============================\n   ");
                for (int i = top; i >= 0; i--)
                {
                    printf("%d\t", stack[i]);
                }
            }
            printf("\n");
            break;
        }
        case 0:
        {
            exit(0);
            break;
        }
        default:
        {
            printf("\nInvalid Choice!!!\n");
            break;
        }
        }

    } while (choice != 0);

    return 0;
}
