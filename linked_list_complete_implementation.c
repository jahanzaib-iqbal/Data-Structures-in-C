#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
} * head; // Global Declaation of structure instance at creation

void insertAtStart(int val)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = val;
    ptr->next = head;
    head = ptr;
    printf("Element : %d Successfully Inserted!!!\n", val);
}

void insertAtEnd(struct Node *head, int val)
{
    if (head == NULL){ // means linked List is empty and insertion must done from start
        printf("\nInvalid node pointer !!!Insertion must be done from start\n");
        return;
    }
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = val;
    ptr->next = NULL;
    while (head->next != NULL)
        head = head->next;
    // when it comes at last node than it stores the address of new node
    head->next = ptr;
    printf("Element : %d Successfully Inserted!!!\n", val);
}

void insertAtIndex(struct Node *head, int val, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    int i = 0;

    while (i != index - 1){
        head = head->next;
        i++;
    }
    ptr->data = val;
    ptr->next = head->next;
    head->next = ptr;
    printf("Element : %d Successfully Inserted!!! at index %d \n", val, index);
}

void deleteAtStart()
{
    struct Node *toDelete = (struct Node *)malloc(sizeof(struct Node));
    if (head == NULL){      //if list is empty
        printf("List UnderFlow!!! List is empty\n");
    }
    else{
        toDelete = head;
        head = head->next;
        printf("Element : %d Deleted Successfully\n", toDelete->data);
        free(toDelete);
    }
}

void deleteAtEnd()
{
    struct Node *toDelete = (struct Node *)malloc(sizeof(struct Node));
    struct Node *secondLast = (struct Node *)malloc(sizeof(struct Node));
    secondLast = head, toDelete = head;

    if (head == NULL){ // list is empty
        printf("List UnderFlow!!! List is empty");
    }
    else if (head->next == NULL){ // when there is only one element
        head = NULL;
        printf("Element : %d Deleted Successfully\n", toDelete->data);
        free(toDelete);
    }
    else{
        while (toDelete->next != NULL){
            secondLast = toDelete;
            toDelete = toDelete->next;
        }
        printf("Element : %d Deleted Successfully\n", toDelete->data);
        free(toDelete);
        secondLast->next = NULL;
    }
}

void deleteAtIndex(int index)
{
    struct Node *toDelete = (struct Node *)malloc(sizeof(struct Node));
    struct Node *secondLast = (struct Node *)malloc(sizeof(struct Node));
    secondLast = head, toDelete = head;
    if (head == NULL){ // list is empty
        printf("List UnderFlow!!! List is empty\n");
    }
    else if (index == 0){ // Delete from Start
        head = head->next;
        printf("Element : %d Deleted Successfully\n", toDelete->data);
        free(toDelete);
    }
    else{
        for (int i = 0; i < index; i++){
            secondLast = toDelete;
            toDelete = toDelete->next;
        }
        secondLast->next = toDelete->next;
        printf("Element: %d deleted Successfullly \n", toDelete->data);
        free(toDelete);
    }
}

void countNodes(struct Node *head)
{
    if (head == NULL){
        printf("List is Empty!!! 0 Nodes in The Linklist\n");
    }
    else{
        int count = 1;
        while (head->next != NULL){
            head = head->next;
            count++;
        }
        printf("Number of Nodes in The Linklist are : %d\n", count);
    }
}

void dispay(struct Node *head)
{
    if (head == NULL){
        printf("Linkedlist UnderFlown!!! List is Empty\n");
    }
    else{
        int i = 0;
        while (head != NULL)
        {
            printf("element [%d] : %d\n", i, head->data);
            head = head->next;
            i++;
        }
    }
}

int main()
{
    head = NULL; // Initializing head as null
    int choice;

    while (1)
    {
        printf("------------------------------------------------------" );
        printf("\n\tEnter 1 to insert from start");
        printf("\n\tEnter 2 to insert from end");
        printf("\n\tEnter 3 to insert in middle at Index");
        printf("\n\tEnter 4 to Delete from start");
        printf("\n\tEnter 5 to Delete from End");
        printf("\n\tEnter 6 to Delete At index");
        printf("\n\tEnter 7 to Count Number of Nodes");
        printf("\n\tEnter 8 to display");
        printf("\n\tEnter 0 to exit");
        printf("\n\tChoice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            int val;
            printf("Enter the value you want to insert \n");
            scanf("%d", &val);
            insertAtStart(val);
            break;
        }

        case 2:
        {
            int val;
            printf("Enter the value you want to insert \n");
            scanf("%d", &val);
            insertAtEnd(head, val);
            break;
        }
        case 3:
        {
            int val, index;
            printf("Enter the index at which you want to insert : ");
            scanf("%d", &index);
            printf("Enter the value you want to insert \n");
            scanf("%d", &val);
            insertAtIndex(head, val, index);
            break;
        }
        case 4:
        {
            deleteAtStart();
            break;
        }
        case 5:
        {
            deleteAtEnd();
            break;
        }
        case 6:
        {
            int index;
            printf("Enter the index at which you want to Delete:");
            scanf("%d", &index);
            deleteAtIndex(index);
            break;
        }
        case 7:
        {
            countNodes(head);
            break;
        }
        case 8:
            dispay(head);
            break;

        case 0:
            exit(1);
            break;

        default:
            printf("Invalid Choice !!!\n");
            break;
        }
    }
    return 0;
}
