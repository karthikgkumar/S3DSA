#include <stdio.h>
#include <stdlib.h>

typedef struct structure
{
    int data;
    struct structure *next;
} node;
node *head=NULL, *rear=NULL;
int count=0;

node *createnode(item)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data=item;
    newnode->next=NULL;
    return newnode;
}

void enqueue(item){
    node *newnode = createnode(item);
    if(head==NULL){
        head=newnode;
        rear=newnode;
    }
    else{
        rear->next=newnode;
        count++;
    }
}

void dequeue(){
    
}

void main()
{
    int item, ch;
    printf("enter choice\n");
    scanf("%d", &ch);
    while (ch < 8)
    {
        switch (ch)
        {
        case 1:
            printf("Enter item\n");
            scanf("%d", &item);
            enqueue(item);
            break;
        case 2:
            dequeue();
        case 3:
            reverse();
        case 4:
            display();

        default:
            printf("wrong choice\n");
            break;
        }
        printf("enter choice\n");
        scanf("%d", &ch);
    }
}