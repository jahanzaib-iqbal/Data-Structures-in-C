#include<stdio.h>
#define SIZE 100

void transpose(int arr[SIZE][SIZE],int row,int column){
    int temp[SIZE][SIZE];
    for(int i =0;i<row;i++){
        for(int j =0;j<column;j++){
            temp[j][i] = arr[i][j];
        }
    }
    printf("\nNew Matrix \n");
    for(int i =0;i<column;i++){
        for(int j =0;j<row;j++){
            printf("%d\t ",temp[i][j]);
        }
        printf("\n");
    }

}
int main(){
    int arr[SIZE][SIZE],column,rows;
    printf("Enter number of rows and columns : ");
    scanf("%d %d",&rows,&column);
    printf("\nEnter the elements of matrix :\n");
    for(int i =0;i<rows;i++){
        for(int j =0;j<column;j++){
            printf("(%d , %d ): ",i,j);
            scanf("%d",&arr[i][j]);
        }
    }
    printf("\nOriginal Matrix\n");
    for(int i =0;i<rows;i++){
        for(int j =0;j<column;j++){
            printf("%d\t ",arr[i][j]);
        }
        printf("\n");
    }
    transpose(arr,rows,column);


    return 0;
}
