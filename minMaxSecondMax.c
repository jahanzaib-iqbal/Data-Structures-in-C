#include <stdio.h>
#include <stdlib.h>
#define CAPACITY 100

int max(int arr[], int size)
{
    int max = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

int min(int arr[], int size)
{
    int min = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < min)
        {
           min = arr[i];
        }
    }
    return min;
}

int secondMax(int arr[], int size)
{
    int max = 0, secondMax = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max)
        {
            secondMax = max;
            max = arr[i];
        }
        else if (arr[i] < max && arr[i] > secondMax)
        {
            secondMax = arr[i];
        }
    }
    return secondMax;
}

int main()
{
    int arr[CAPACITY], size, choice;

    printf("Enter Number of Elements you want to enter : ");
    scanf("%d", &size);

    for (int i = 0; i < size; i++)
    {
        printf("Enter Element at index %d : ", i);
        scanf("%d", &arr[i]);
    }
    do
    {
        printf("\tPress 1 to Find Maximum Number\n");
        printf("\tPress 2 to Find Minimum Number\n");
        printf("\tPress 3 to Find Second Maximum Number\n");
        printf("\tPress 0 to Exit\n");
        printf("\t>> : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            exit(0);
            break;

        case 1:
            printf("\nMaximum number : %d\n",max(arr, size));
            break;

        case 2:
            printf("\nMinimum number : %d\n",min(arr, size));
            break;

        case 3:
            printf("\nSecond Maximum number : %d\n",secondMax(arr, size));
            break;

        default:
            printf("INVALID CHOICE !!!");
            break;
        }
    } while (choice != 0);

    return 0;
}