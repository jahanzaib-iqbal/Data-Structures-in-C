// FA20-BSE-091   JAHANZAIB IQBAL
#include <stdio.h>
#include <stdlib.h>
#define CAPACITY 100
void printArray(int arr[],int size );
int insertElement(int arr[],int size );
int deleteAtIndex(int arr[],int size );
int deleteAtValue(int arr[],int size );
void searchByIndex(int arr[],int size );
int searchByValue(int arr[], int size,int val);

int main(){
   
    

    int arr[CAPACITY] , size;

    printf("\n\t\t=======================\n");
    printf("\t\t         WELCOME       \n");
    printf("\t\t=======================\n\n");

    // Assigning elements to array\n
    printf("Enter how many elements you want yo put in array : ");
    scanf("%d",&size);
    for (int i = 0; i < size; i++)
    {
        printf("Enter element at index %d: ",i);
        scanf("%d",&arr[i]);
    }
    
    int choice,success =0,searchValue;


    do{
    printf("\n-------------------\nEnter\n\t1-> to insert at Index\n\t2-> to Delete at Index\n\t3-> to delete by Value\n\t4-> to Search by Index\n\t5-> to Search by Value\n\t6-> to Traverse/print\n\t0-> to exit\n\tChoice :  ");    
    scanf("%d",&choice);
    
    switch (choice)
    {
    case 0:
        printf("\n\t===================\n\n\t   FINISHED :)\n\n\t====================");
        system(0);
        break;

    case 1:
        success = insertElement(arr,size);
        if(success != -1 ){
            printf("\nNumber Inserted Successfully!\n");
            size +=1;
        }
        else if(success = -1)
            printf("\nFailed to inset Number\n");
        break;
    
    case 2:
        success = deleteAtIndex(arr,size);
        if(success != -1 ){
            printf("\nNumber Deleted Successfully !\n");
            size -=1;
        }
        else if(success = -1)
            printf("\nFAILED TO DELETE !\n");
        break;
    
    case 3:
        success = deleteAtValue(arr,size);
        if (success == 1)
        {
            printf("Number Deleted Successfully !");
            size -=1;
        }
        else if(success == -1){
            printf("DELETION FAILED, No such element exists");
        }
        
        break;
    
    case 4:
        searchByIndex(arr,size);
        break;
    
    case 5:
       
        printf("\nEnter the Value at which you want to search: ");
        scanf("%d",&searchValue);
        int searchIndex = searchByValue(arr,size,searchValue);
            if(searchIndex != -1 ){
                printf("\nNumber %d is FOUND at index : %d\n",searchValue,searchIndex);
            }
            else if(success = -1)
                printf("\nNUMBER %d DO NOT FOUND !\n",searchValue);
        break;
    
    case 6:
        printArray(arr,size);
        break;
    
    default:
        printf("Invalid Input !!!!");
        break;
    }
    }while (choice!=0);

    return 0;
}


void printArray(int arr[], int size){
    printf("\n");
    if(size ==0)
        printf("ARRAY IS EMPTY !\n");
    for(int i =0; i<size; i++){
        printf("index[%d] = %d\n",i,arr[i]);
    }

}


int insertElement(int arr[],int size ){
    int index, element;
    
    if(size >= CAPACITY){
        printf("No more elements can be inserted, Array is full!!!\n");
        return -1;
    }
    else{
        printf("Enter the index at which you want to add : ");
        scanf("%d",&index );

        if(index <0 || index > size ){
            printf("Warning! No Such Location Exist INVALID INDEX\n");
            return -1;
        }
        else{
            printf("Enter the value you want to add at index %d: ",index);
            scanf("%d",&element);    

            for (int i = size-1 ; i >= index ; i--)
            {
                arr[i+1] = arr[i];
            }
            arr[index] = element;
            return 1;
            printf("Number inserted Succcessfully!");
        }
    }
}


int deleteAtIndex(int arr[],int size ){
    
    int index;
    printf("Enter the index at which you want to Delete : ");
    scanf("%d",&index);
    if(size > CAPACITY){
        printf("\nINVALID INDEX ... No Such Location Exist\n");
        printf("Invalid Index!!!\n");
    }
    else{
        if(index <0 || index >= size ){
            printf("\nINVALID INDEX ... No Such Location Exist\n");
            return -1;
        }
        else{
            for (int i= index ; i < size-1; i++)
            {
                arr[i] = arr[i+1];
            }
            return 1;

        }
    }
  
}


int deleteAtValue(int arr[],int size ){
    
    int val,success,index;

    printf("\nEnter the Value which you want to delete: ");
    scanf("%d",&val );
    
    int indexOfSearch = searchByValue(arr,size, val);
    if(indexOfSearch != -1){
        for (int i= indexOfSearch ; i < size-1; i++)
            {
                arr[i] = arr[i+1];
            }
        return 1;           
    }
    if (indexOfSearch == -1)
    {
        return -1;
    }
    

}


int searchByValue(int arr[], int size,int val){
   
    int success,index;
    for (int i = 0; i < size ; i++)
    {
        if(arr[i]==val){
            index = i;
            break;
        }
        else if(arr[i] !=val){
            index = -1;
        }
       
    }
    
    return index;
    
}


void searchByIndex(int arr[],int size ){
 
    int index;
    printf("Enter the index at which you want to search: ");
    scanf("%d",&index );
    if(index >= size || index<0){
        printf("\nINVALID INDEX, No such index exits !!!\n");
    }
    else if(index >=0 && index <=size){
        printf("Element at index %d is %d ",index, arr[index]);
    }
    else
        printf("\nINVALID INDEX, No such index exits !!!\n");

}
