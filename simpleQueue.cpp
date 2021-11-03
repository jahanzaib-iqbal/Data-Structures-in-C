#include <iostream>
using namespace std;
#define MAX 10

int queue[MAX];
int front = -1, rear = -1;

void enqueue()
{
    int val;
    cout << "Enter the value you want to add: ";
    cin >> val;
    if (rear == MAX - 1)
    {
        cout << "Queue Overflown" << endl;
    }
    if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = val;
    }
    else
    {
        rear++;
        queue[rear] = val;
    }
}
void dequeue()
{
    int temp;
    if ((front == -1 && rear == -1))
    {
        cout << "Queue Underflown" << endl;
    }
    if (front == rear)
    { // Only one element
        temp = queue[rear];
        front = rear = -1;
    }
    else
    {
        temp = queue[front];
        front = front + 1;
    }
}
void display()
{
    if ((front == -1 && rear == -1))
        cout << "Queue is Empty";
    else
    {
        for (int i = front; i <= rear; i++)
        {
            cout << queue[i] << "\t";
        }
        cout << "Finnished Print" << endl;
    }
}
int main()
{

    int choice;
    while (1)
    {
        cout << "\n1.Insert element to queue " << endl;
        cout << "2.Delete element from queue " << endl;
        cout << "3.Display all elements of queue " << endl;
        cout << "0.Quit " << endl;
        cout << "Enter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 0:
            exit(1);
        }
    }

    return 0;
}