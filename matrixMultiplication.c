#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rows1, rows2, columns1, columns2;
    printf("Enter rows and Columns of first matrix: ");
    scanf("%d %d", &rows1, &columns1);
    int first[rows1][columns1];

    printf("Enter all elements of First Matrix : \n");
    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < columns1; j++)
        {
            scanf("%d", &first[i][j]);
        }
    }
    printf("First Matrix is : \n");
    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < columns1; j++)
        {
            printf("%d\t", first[i][j]);
        }
        printf("\n");
    }

    printf("Enter rows and Columns of Second matrix: ");
    scanf("%d %d", &rows2, &columns2);
    int second[rows2][columns2];
    if (columns1 == rows2)
    {
        printf("Enter all elements of Second Matrix : \n");
        for (int i = 0; i < rows2; i++)
        {
            for (int j = 0; j < columns2; j++)
            {
                scanf("%d", &second[i][j]);
            }
        }
        printf("Second Matrix is : \n");
        for (int i = 0; i < rows2; i++)
        {
            for (int j = 0; j < columns2; j++)
            {
                printf("%d\t", second[i][j]);
            }
            printf("\n");
        }

        //Matrix Multiplication
        int sum = 0, result[rows1][columns2];

        for (int i = 0; i < rows1; i++)
        {
            for (int j = 0; j < columns2; j++)
            {
                for (int k = 0; k < rows2; k++)
                {
                    sum = sum + first[i][k] * second[k][j];
                }
                result[i][j] = sum;
                sum = 0;
            }
        }

        //Printing the result
        printf("Result of multiplication: \n=================================\n");
        for (int i = 0; i < rows1; i++)
        {
            for (int j = 0; j < columns2; j++)
            {
                printf("%d\t", result[i][j]);
            }
            printf("\n");
        }
        printf("=================================\n");
    }
    else
        printf("Multiplication of these Two matrices is not possible!\n");
    return 0;
}