#include <stdio.h>
#include <stdlib.h>
// By JAHANZAIB IQBAL
struct Node
{
    int coefficient;
    int exponent;
    struct Node *next;
};

struct Node *insert(struct Node *head, int coeff, int expo)
{
    struct Node *temp;
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->coefficient = coeff;
    newNode->exponent = expo;
    newNode->next = NULL;

    // sorted Insertion in descending order of exponents
    if (head == NULL || expo > head->exponent)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        temp = head;
        while (temp->next != NULL && expo <= temp->next->exponent)
            temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
    }
    return head;
}

struct Node *createPoly(struct Node *head)
{
    int n, i, expo, coeff;

    printf(" How many terms you want to enter : ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter The Co-efficient of term %d :", i + 1);
        scanf("%d", &coeff);
        printf("Enter The Exponent of term %d :", i + 1);
        scanf("%d", &expo);
        head = insert(head, coeff, expo);
    }
    return head; // return the address of head of correspondig LinkedList to access the linkedList in future
}

void printPoly(struct Node *head)
{
    if (head == NULL)
    {
        printf("Polynomial is Empty\n");
    }
    else
    {
        struct Node *temp = head;
        while (temp != NULL)
        {
            printf("(%dx^%d)", temp->coefficient, temp->exponent);
            temp = temp->next;
            if (temp != NULL)
                printf(" + "); // print + after every Node
        }
    }
}

void addPoly(struct Node *head1, struct Node *head2)
{
    struct Node *ptr1 = head1;
    struct Node *ptr2 = head2;
    struct Node *head3 = NULL;

    while (ptr1 != NULL && ptr2 != NULL) // traverse both lists untill reaches at end
    {
        if (ptr1->exponent == ptr2->exponent)
        {
            head3 = insert(head3, ptr1->coefficient + ptr2->coefficient, ptr1->exponent);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

        else if (ptr1->exponent > ptr2->exponent)
        {
            head3 = insert(head3, ptr1->coefficient, ptr1->exponent);
            ptr1 = ptr1->next;
        }
        else if (ptr1->exponent < ptr2->exponent)
        {
            head3 = insert(head3, ptr2->coefficient, ptr2->exponent);
            ptr2 = ptr2->next;
        }
    }
    // insert remaining elements of first polynomial
    while (ptr1 != NULL)
    {
        head3 = insert(head3, ptr1->coefficient, ptr1->exponent);
        ptr1 = ptr1->next;
    }
    // insert remaining elements of Second polynomial
    while (ptr2 != NULL)
    {
        head3 = insert(head3, ptr2->coefficient, ptr2->exponent);
        ptr2 = ptr2->next;
    }
    printf("\nPolynomials Added Successfully !!!\nRESULT:\t");
    printPoly(head3);
}

int main()
{
    struct Node *head1 = NULL;
    struct Node *head2 = NULL;
    printf("\n==================POLYNOMIALS ADDITION==================\n");

    printf("---Enter First Polynomial--- \n");
    head1 = createPoly(head1);
    printf("\n---Enter Second Polynomial--- \n");
    head2 = createPoly(head2);

    addPoly(head1, head2);

    return 0;
}