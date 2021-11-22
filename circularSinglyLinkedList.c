#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
}*tail;


void create()
{
    int val;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter the First value : ");
    scanf("%d",&val);
    newNode->data = val;
    newNode->next = newNode;
    tail = newNode;
}


int countNodes()
{
    int count =0;
    if(tail == NULL){
        return 0;
    }
    else if(tail == tail->next){
        return 1;
    }

    else{
        struct Node* ptr = tail;
        do{
            ptr = ptr->next;
            count++;
        }
        while(ptr->next != tail->next);
        return count;
    }
}


void insertAtStart()
{
    //printf("Insertion From Start Here\n");
    int val;
    if(tail == NULL)
    {
        create(tail);
    }
    else
    {
        printf("\nEnter the value you want to insert At Start: ");
        scanf("%d",&val);
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = tail->next;
        tail->next = newNode;
        printf("\n%d inserted at Start Successfully!",val);
    }
}

void insertAtEnd()
{
    //printf("Insertion From End Here\n");
    int val;
    if(tail == NULL)
    {
        create(tail);
    }
    else
    {
        printf("\nEnter the value you want to insert At End: ");
        scanf("%d",&val);
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        struct Node* ptr = tail;
        newNode->data = val;
        newNode->next = ptr->next;
        ptr->next = newNode;
        tail = newNode;
        printf("\n%d inserted at End Successfully!",val);
    }
}

void insertAtIndex()
{
    int index,val,i=0;
    int nodes = countNodes();
    printf("\nEnter Index : ");
    scanf("%d",&index);

    if(index > nodes){
        printf("Invalid Index");
        return;
    }
    else if(index == nodes){
        insertAtEnd();
    }
    else if(index == 0){
        insertAtStart();
    }
    else {  //Normal flow
        struct Node* newNode =(struct Node*)malloc(sizeof(struct Node));
        printf("Enter the value : ");
        scanf("%d",&val);
        struct Node* ptr = tail;

        do{
            ptr = ptr->next;
            i++;
        }while(i<index);

        newNode->data = val;
        newNode->next = ptr->next;
        ptr->next = newNode;
        printf("\n%d inserted Successfully!",val);
    }
}

void deleteAtStart()
{
    //printf("Deletion From Start Here\n");
    struct Node* ptr = tail;
    struct Node* toDelete = (struct Node*)malloc(sizeof(struct Node));
    if(tail == NULL){
        printf("List UnderFlown!!!");
    }
    else if(tail == tail->next) //only one node
    {
        toDelete = tail;
        printf("\n%d deleted ",toDelete->data);
        tail = NULL;
        free(toDelete);
    }
    else{
        ptr = tail;
        toDelete = ptr->next;
        ptr->next = toDelete->next;
        printf("\n%d deleted Successfully!",toDelete->data);
        free(toDelete);
    }
}

void deleteAtEnd()
{
    struct Node* ptr = tail;
    struct Node* toDelete = (struct Node*)malloc(sizeof(struct Node));
    if(tail == NULL){
        printf("List UnderFlown!!!");
    }
    else if(tail == tail->next) //only one node
    {
        toDelete = tail;
        printf("\n%d deleted Successfully!",toDelete->data);
        tail = NULL;
        free(toDelete);
    }
    else
    {
        toDelete = ptr = tail;
        do{
            ptr = ptr->next;
        }
        while(ptr->next != tail);   //at the end of loop ptr comes at 2nd last node

        ptr->next = tail->next;
        printf("%d deleted from end Successfully!",tail->data);
        tail = ptr;
        free(toDelete);
    }
}

void deleteAtIndex()
{
    int nodes = countNodes();
    int index,i=0;
    struct Node* toDelete;
    struct Node* secondLast;

    if(tail == NULL){   //lIST IS EMPTY
        printf("List UnderFlown!!!");
    }
    else{
        printf("Enter the index : ");
        scanf("%d",&index);

        if(index > nodes-1){    //Index out of bound
            printf("\nIndex Not Found!!!");
            return;
        }
        if(index == 0){ //delete at start
            deleteAtStart();
        }
        else if(index == nodes-1){
            deleteAtEnd();
        }
        else{       //normal flow
            secondLast = toDelete = tail->next;
            do{
                secondLast = toDelete;
                toDelete = toDelete->next;
                i++;
            }while(i!=index);
            secondLast->next = toDelete->next;
            printf("\n%d Deleted Successfully!",toDelete->data);
            free(toDelete);
            }
    }
}

void displayList()
{
    if(tail == NULL)
    {
        printf("List UnderFlown!!!");
        return;
    }
    struct Node* ptr = tail;
    printf("\nPRINTING\n");
    do{
        ptr = ptr->next;
        printf("%d\t",ptr->data);
    }
    while(ptr->next != tail->next);
    printf("\n==========\n");
}

int main()
{
    tail = NULL;
    int choice;
    printf("__\"Creating the List\"__\n");
    create();
    while(1)
    {
        printf("\n\tEnter 1 to insert at start\n\tEnter 2 to Insert At End\n\tEnter 3 to Insert At Any Index\n\tEnter 4 to Delete at Start\n\tEnter 5 to Delete At End\n\tEnter 6 to Delete at any Index\n\tEnter 7 to count Nodes\n\tEnter 8 to Display\n\tEnter 0 to Exit\n\tChoice :");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            insertAtStart();
            break;
        case 2:
            insertAtEnd();
            break;
        case 3:
            insertAtIndex();
            break;
        case 4:
            deleteAtStart();
            break;
        case 5:
            deleteAtEnd();
            break;
        case 6:
            deleteAtIndex();
            break;
        case 7:
            printf("\nNumber Of Nodes = %d\n",countNodes);
            break;
        case 8:
            displayList();
            break;
        case 0:
            exit(1);
            break;
        default:
            printf("\nInvalid Choice!!!");
            break;
        }
    }
    return 0;
}
