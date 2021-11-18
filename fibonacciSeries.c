#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int arr[MAX];

void fibbonaci(int n)
{
    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i < n; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];	//Fn = Fn-1  +  Fn-2  --> 0,1,1,2,3,5,8....
    }
    printf("Printing\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
}

int main()
{
    int n;
    printf("Enter the Upper Limit for series : \n");
    scanf("%d", &n);
    fibbonaci(n);
    return 0;
}