#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*newnode;
struct Node *tail=NULL; 
int length=1;
struct Node *createnode(){
    int data;
    newnode=(struct Node *)malloc(sizeof(struct Node));
    printf("enter data\n");
    scanf("%d",&data);
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}

void insertbeg(){
    newnode=createnode();
    if(tail==NULL){
        printf("%d newnode \n",newnode->data);
        
        tail=newnode;
        tail->next=newnode;
    }
    else{
        printf("%d newnode \n",newnode->data);
        newnode->next=tail->next;
        tail->next=newnode;
    }
    length++;

}

void insertend(){
    newnode=createnode();
    if(tail==NULL){
        tail=newnode;
        tail->next=newnode;
    }
    else{
        newnode->next=tail->next;
        tail->next=newnode;
        tail=newnode;
    }
    length++;

}

void insertpos(int length){

    struct Node *ptr;
    int pos,i=1;
    printf("enter pos\n");
    scanf("%d",&pos);
    if(pos<0 || pos>length){
        printf("invalid \n");
    }
    else if (pos==1)
    {
        insertbeg();
    }
    else if (pos==length)
    {
        insertend();
    }
    else{
        newnode=createnode();
        ptr=tail->next;
        while (i<pos-1)
        {
            ptr=ptr->next;
            i++;
        }
        newnode->next=ptr->next;
        ptr->next=newnode;
    }

    
    
    
}


void deletefront(){

    if (tail==NULL)
    {
        printf("Empty\n");
    }
    tail->next=tail->next->next;
    

}

void deleteend(){
    struct Node *ptr=tail->next;
    if (tail==NULL)
    {
        printf("Empty\n");
    }
    while (ptr->next!=tail)
    {
        ptr=ptr->next;
    }
   
    ptr->next=tail->next;
    tail->next=NULL;
    tail=ptr;

}

void deletepos(){

}


void display(){
    struct Node *temp=tail ->next;
    if(tail==NULL){
        printf("empty\n");
    }

    while (temp->next!=tail)
    {
        printf("%d ->",temp->data);
        temp=temp->next;
    }
    if(tail==tail->next){
        printf("%d \n",temp->data);
    }
    else{printf("%d->",temp->data);
    temp=temp->next;
    printf("%d \n",temp->data);}
}

void main(){
    int ch=1;
    
    while (ch!=9)
    {   
        printf("1.Insert at front \n2.Insert at end\n 3.Insert at any pos\n4.Delete front\n5.Delete end\n6.Delete any pos \n7.display\n8.Exit \n");
        printf("enter choice\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            insertbeg();
            break;
            case 2:
            insertend();
            break;
            case 3:
            insertpos(length);
            break;
            case 4:
            deletefront();
            break;
            case 5:
            deleteend();
            break;
            case 6:
            deletepos();
            break;
            case 7:
            display();
            break;
            case 8:
            exit(0);
            default:
            printf("wrong choice \n");
        }
    }
    
}