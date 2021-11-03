#include <iostream>
using namespace std;

#define MAX 10
int dequeue[MAX],rear=-1,front=-1;

void insertFromRear(){
    int val;
    cout<<"Enter the Number you want to insert at rear : ";
    cin>>val;
    if( (front ==0 && rear == MAX -1) || rear == front-1){
        cout<<"DE Queue OerFlown"<<endl;
    }
    else if(front == -1 && rear == -1){
        front =0,rear=0;
        dequeue[rear] = val;
        cout<<val<<" inserted successfully at rear"<<endl;
    }
    else{
        rear = (rear + 1) % MAX;
        dequeue[rear] = val;
        cout<<val<<" inserted successfully at rear"<<endl;
    }
}

void insertFromFront(){
    int val;
    cout<<"Enter the value you want to insert at front : ";
    cin>>val;
    if((front == 0 && rear == MAX-1) || front == rear +1 ){
        cout<<"DE Queue Overflown!"<<endl;
    }
    else if(front == -1 && rear ==-1){
        front =0, rear =0;
        dequeue[front] = val;
        cout<<val<<" inserted successfully at front"<<endl;
    }
    else if(front == 0){
        front = MAX-1;
        dequeue[front] = val;
        cout<<val<<" inserted successfully at front"<<endl;
    }
    else{
        front --;
        dequeue[front] = val;
        cout<<val<<" inserted successfully at front"<<endl;
    }   
}

void deleteFromFront(){
    int temp;
    if(front == -1 && rear == -1){
        cout<<"DE Queue UnderFlown!"<<endl;
    }
    if(front ==0 && rear ==0){
        temp = dequeue[front];
        front =-1,rear=-1;
        cout<<temp<<" Deleted successfully at front"<<endl;
    }
    else if(front == rear){
        temp = dequeue[front];
        front =-1,rear=-1;
        cout<<" Deleted successfully at front"<<endl;
    }
    else{
        temp = dequeue[front];
        front = (front+1) %MAX;
        cout<<temp<<" Deleted successfully at front"<<endl;
    }
}

void deleteFromRear(){
    int temp;
    if(front == -1 && rear == -1){
        cout<<"DE Queue UnderFlown!"<<endl;
    }
    if(front ==0 && rear ==0){
        temp = dequeue[rear];
        front =-1,rear=-1;
        cout<<temp<<" Deleted successfully at front"<<endl;
    }
    else if(front == rear){
        temp = dequeue[rear];
        front =-1,rear=-1;
        cout<<temp<<" Deleted successfully at front"<<endl;
    }
    if(rear == 0){
        temp = dequeue[rear];
        rear = MAX-1;
        cout<<temp<<" Deleted successfully at front"<<endl;
    }
    else{
        int temp = dequeue[rear];
        rear --;
        cout<<temp<<" Deleted successfully at front"<<endl;
    }
}

void display(){
    if(front==-1 && rear ==-1){
        cout<<"DE Queue is Empty"<<endl;
    }
    else{
        cout<<"Front : "<<front<<"\tRear : "<<rear<<endl;
        for (int i = front ; i != rear; i= (i+1)%MAX){
            cout<<dequeue[i]<<"\t";
        }
        cout<<dequeue[rear]<<"\t"<<endl;
        cout<<"Printing Finshed!"<<endl;
    }
}

void getFront(){
    if(front==-1 && rear == -1){
        cout<<"DE Queue is Empty"<<endl;
    }
    else{
        cout<<"Element at front : "<<dequeue[front]<<endl;
    }
}

void getRear(){
    if(front==-1 && rear == -1){
        cout<<"DE Queue is Empty"<<endl;
    }
    else{
        cout<<"Element at Rear : "<<dequeue[rear]<<endl;
    }
}

int main(){
    cout<<"================================================================="<<endl;
    cout<<"                 DOUBLE ENDED QUEUE BY JAHANZAIB                 "<<endl;
    cout<<"================================================================="<<endl;
    int choice;
    while (true)
    {
        cout<<"Enter\n\t1 to Insert from Rear"<<endl;
        cout<<"\t2 to Insert from Front"<<endl;
        cout<<"\t3 to Delete from Front"<<endl;
        cout<<"\t4 to Delete from Rear"<<endl;
        cout<<"\t5 to Get element at Front"<<endl;
        cout<<"\t6 to Get element at Raear"<<endl;
        cout<<"\t7 to DISPLAY "<<endl;
        cout<<"\t0 to EXIT"<<endl;
        cout<<"\tchoice >: ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            insertFromRear();
            break;
        
        case 2:
            insertFromFront();
            break;
        
        case 3:
            deleteFromFront();
            break;
        
        case 4:
            deleteFromRear();
            break;
        
        case 5:
            getFront();
            break;
        
        case 6:
            getRear();
            break;
        
        case 7:
            display();
            break;
        
        case 0:
            exit(0);
            break;
        
        default:
            cout<<"Invalid Choice!!!"<<endl;
            break;
        }
    }
    
    return 0;
}
