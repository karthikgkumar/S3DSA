// 1. Queue - Implement using array and Linked List
// Queue a First-In-First-Out (FIFO) data structure. In a FIFO data structure, the first
// element added to the queue will be the first one to be removed. This is equivalent
// to the requirement that whenever an element is added, all elements that were
// added before have to be removed before the new element can be invoked. A
// queue is an example of a linear data structure.

// Queues provide services in computer science and operations research where
// various entities such as data, objects, or events are stored and held to be
// processed later. In these contexts, the queue performs the function of a buffer.


#include<stdio.h>
#include<stdlib.h>
#define N 5

int queue[N];
int front  =-1;
int rear=-1;

void EnqueueArray(int val)
{
    if(front==-1 && rear==-1)
    {
        front=rear=0;
        queue[rear] = val ;
    }
    else if((rear+1)%N==front){
        printf("queue is full");
    }
    else
    {
        rear=(rear+1)%N;
        queue[rear] = val;
    }
    
}

void DequeueArray()
{
    if (front==-1 && rear==-1)
    {
        printf("Queue is empty\n");
    }
    
    else if (front == rear)
    {
        printf("%d is deleted" , queue[front]);
        front = rear = -1;
    }
    else
    {
        printf("%d is deleted" , queue[front]);
        front=(front+1)%N;
    }
}

void DisplayArray()
{
    int i=front;
    if (front==-1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("The queue elements are:\n");
        while(i!=rear)
        {
            printf("%d " , queue[i]);
            i=(i+1)%N;
            
        }
         printf("%d " , queue[rear]);
    }
}

int main()
{
     int ch,element;
    do
    {
        printf("\n\nChoose operation");
        printf("\n1.Enqueue");
        printf("\n2.Dequeue");
        printf("\n3.Display ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("\nEnter element to insert\n");
            scanf("%d",&element);
            EnqueueArray(element);
            break;

            case 2:
                DequeueArray();
                break;

            case 3:
                DisplayArray();
                break;
       
        }
    }while(ch<4);
    return 0;
}