#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*newnode;
struct Node *tail=NULL; 
int length=0;
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
        
        tail=newnode;
        tail->next=newnode;
    }
    else{
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

void insertpos(){

    struct Node *ptr;
    int pos,i=1;
    printf("enter pos\n");
    scanf("%d",&pos);
    if(pos<0 || pos>length+1){
        printf("invalid \n");
    }
    else if (pos==1)
    {
        insertbeg();
    }
    else if (pos==length+1)
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
        length++;
    }

    
    
    
}


void deletefront(){
    if (tail==NULL)
    {
        printf("Empty\n");
    }
    else if(length==1){
        printf("%d deleted \n",tail->data);
        tail=NULL;
        length--;
    }
    else{
        printf("%d deleted \n",tail->next->data);
        tail->next=tail->next->next;
        length--;

    }
      

}

void deleteend(){
    
    if (tail==NULL)
    {
        printf("Empty\n");
    }
    else if(length==1){
        printf("%d deleted \n",tail->data);
        tail=NULL;
    }
    else{
        struct Node *ptr=tail->next;
        while (ptr->next!=tail)
        {
            ptr=ptr->next;
        }
        printf("%d deleted \n",tail->data);
        ptr->next=tail->next;
        tail->next=NULL;
        tail=ptr;
        length--;
    }
    

}

void deletepos(){

    
    int pos,i=1;
    printf("enter pos\n");
    scanf("%d",&pos);
    if(pos<0 || pos>length+1){
        printf("invalid \n");
    }
    else if (pos==1)
    {
        deletefront();
    }
    else if (pos==length+1)
    {
        deleteend();
    }
    else{
        struct Node *prev,*other;
        prev=tail->next;
        while (i<pos-1)
        {
            prev=prev->next;
            i++;
        }
        printf("%d deleted \n",prev->next->data);
        other=prev->next->next;
        prev->next->next=NULL;
        prev->next=other;
        length--;
    }

    


}


void display(){
    
    if(tail==NULL){
        printf("empty\n");
    }
    else{
        struct Node *temp=tail ->next;
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

    
}

void main(){
    int ch=1;
    
    while (ch!=9)
    {   
        printf("1.Insert at front \n2.Insert at end\n3.Insert at any pos\n4.Delete front\n5.Delete end\n6.Delete any pos \n7.display\n8.Exit \n");
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
            insertpos();
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