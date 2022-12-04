#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 5

typedef struct node{
    int val;
    struct node* link;
}linlist;

linlist* head = NULL;
int queue[MAX_SIZE];
int front  =-1;
int rear=-1;

void Enqueuelinkedlist(int val)
{
    if(head==NULL)
    {
        linlist* temp = (linlist* )malloc(sizeof(linlist));
        temp->val = val;
        temp->link = NULL;
        head = temp;
    }
    else
    {
        linlist* temp = head ;
        while (temp->link!=NULL)
        {
            temp = temp->link;
        }
        linlist* temp1 = (linlist* )malloc(sizeof(linlist));
        temp1->val  = val;
        temp1->link = NULL ; 
        temp->link = temp1;
    }
}

void Dequeuelinkedlist()
{
    if(head==NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("%d is deleted\n" , head->val);
        head = head->link ;
    }
}

void DisplayLinkedlist()
{
    if(head == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("The Queue elements are:\n");
        linlist* temp = head;
        while (temp!=NULL)
        {
            printf("%d " , temp->val);
            temp = temp->link;
        }
        printf("\n");
    }
}


void EnqueueArray(int val)
{
    if(rear==MAX_SIZE-1)
    {
        printf("overflow\n");
    }
    
    else if(front==-1 && rear==-1)
    {
        front=rear=0;
        queue[rear] = val ;
    }
    else
    {
        queue[++rear] = val;
    }
    
}

void DequeueArray()
{
    if (front==rear==-1)
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
        front++;
    }
}

void DisplayArray()
{
    if (front==-1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("The queue elements are:\n");
        for(int i = front ; i <=rear ; i++)
        {
            printf("%d " , queue[i]);
        }
    }
}

int main()
{
    printf("\n!Queue operations using linked list and arrays!\n");
    int choice1 , choice2;
    printf("1.Linked list\n");
    printf("2.Array\n");
    printf("Enter the choice:\n");
    scanf("%d" , &choice1);
    if (choice1 == 1)
    {
        int flag=1; 
        while (flag)
        {
            printf("\n1.Enqueue");
            printf("\n2.Dequeue");
            printf("\n3.Display");
            printf("\nEnter the choice:\n");
            scanf("%d" , &choice2);
            if (choice2==1)
            {
                int val;
                printf("Enter the value to insert into the queue:\n");
                scanf("%d" , &val);
                Enqueuelinkedlist(val);
            }
            else if(choice2==2)
            {
                Dequeuelinkedlist();
            }
            else if (choice2==3)
            {
                DisplayLinkedlist();
            }
            else
            {
                printf("Invalid choice\n");
            }
            
            printf("\nDo you want to continue(yes(1) or no(0))?");
            scanf("%d", &flag);
        }
    }
    else if(choice1 ==2)
    {
        int flag=1; 
        while (flag)
        {

            printf("\n1.Enqueue");
            printf("\n2.Dequeue");
            printf("\n3.Display");
            printf("\nEnter the choice:\n");
            scanf("%d", &choice2);
            if (choice2 == 1)
            {
                int val;
                printf("Enter the value to insert into the queue:\n");
                scanf("%d", &val);
                EnqueueArray(val);
            }
            else if (choice2 == 2)
            {
                DequeueArray();
            }
            else if (choice2 == 3)
            {
                DisplayArray();
            }
            else
            {
                printf("Invalid choice\n");
            }
            printf("\nDo you want to continue(yes(1) or no(0))?");
            scanf("%d", &flag);
        }
    }

    else
    {
        printf("\nInvalid choice\n");
    }

    return 0;
}