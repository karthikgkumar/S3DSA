#include <stdio.h>
#include <stdlib.h>

struct Node{

    int data;
    struct Node* next;
};

struct Node* head=NULL;

void IsEmpty(int elem){//Only if the LL is empty

    struct Node* newNode=malloc(sizeof(struct Node));

    head=newNode;
    head->data=elem;
    head->next=NULL;

}

void InsertBack(int elem){

    struct Node* newNode=malloc(sizeof(struct Node));
    struct Node* temp_ptr;

    if (head==NULL){//if no element is there in the list
        IsEmpty(elem);
    }

    else{
        temp_ptr=head;

        if(temp_ptr->next==NULL){//that means only 1 element is there in the list

            temp_ptr->next=newNode;
            newNode->data=elem;
            newNode->next=head;      
        }

        else{

            while(temp_ptr->next!=head){
                temp_ptr=temp_ptr->next;
            }

            newNode->data=elem;
            temp_ptr->next=newNode;
            newNode->next=head;
        }
    }
}

void InsertFront(int elem){

    struct Node* newNode=malloc(sizeof(struct Node));
    struct Node* temp;
    struct Node* ptr;

    if (head==NULL){
        IsEmpty(elem);
    }

    else{
        
        newNode->data=elem;
        newNode->next=head; //the old head

        temp=head->next;
        ptr=head;

        while(temp!=head && temp!=NULL){
            temp=temp->next;
            ptr=ptr->next;
        }

        ptr->next=newNode;
        head=newNode;



    }
}

void InsertAnyPos(int elem,int next_elem){

    struct Node* newNode=malloc(sizeof(struct Node));

    struct Node* temp1;
    struct Node* temp2;

    int flag=0;

    
    if (head==NULL){
        IsEmpty(elem);
    }

    else{

        temp1=head;

        while(temp1->next!=head){ 

            if (temp1->data==next_elem){
                flag=1;
                break;
            }

            else{

                if(temp1->next==NULL){
                    break;
                }

                else{
                    temp1=temp1->next;
                }
            }
        }

        if (flag==1){

            temp2=temp1->next;
            temp1->next=newNode;
            newNode->data=elem;

            if(temp2==NULL){
                newNode->next=head;
            }

            else{
                newNode->next=temp2;
            }
        }

        else{
            printf("\nThe element does not exist! ");
        }
        
    }
}

void DeleteBack(){

    struct Node* ptr;
    struct Node* prev;

    if(head==NULL){
        printf("\nThe CLL is empty! ");
    }

    else{

        prev=head;
        ptr=head->next;

        if (ptr==NULL){//only 1 element in the list
            free(head);
            head=NULL;
        }

        else if(ptr->next==head){//2 elements in the list
            free(ptr);
            head->next=NULL;
            ptr=NULL;

        }

        else{

            while(ptr->next!=head){
                prev=prev->next;
                ptr=ptr->next;

            }

            prev->next=head;
            free(ptr);
            ptr=NULL;
        }

    }
}

void DeleteFront(){

    struct Node* ptr;
    struct Node* temp;


    if(head==NULL){
        printf("\nThe CLL is empty!");
    }

    else{

        temp=head;
        ptr=head;

        if (head->next==NULL){//Only 1 element
            free(head);
            head=NULL;
        }

        else if ((head->next)->next==head){//2 elements in the LL
            head=head->next;//Updating head
            head->next=NULL;
            free(temp);
        }

        else{

            while(ptr->next!=head){
                ptr=ptr->next;
            }//Updating ptr until "last" node of LL

            head=head->next; //Updating head
            ptr->next=head; //Linking last node to head

            free(temp);//Old Head
            temp=NULL;
        }
    }

}

void DeleteAnyNumber(int del_elem){

    struct Node* ptr_prev;
    struct Node* ptr;

    int flag=0;

    if(head==NULL){
        printf("\nLL is empty!");
    }

    else{

        ptr_prev=head;
        ptr=head->next;

        while(ptr!=head){

            if(ptr->data==del_elem){
                flag=1;
                break;
            }

            else{

                if(ptr==NULL){
                    break;
                }

                else{
                    ptr_prev=ptr_prev->next;
                    ptr=ptr->next;
                }
            }
        }

        if (flag==1){

            if(ptr==NULL){
                free(ptr_prev);
                ptr_prev=NULL;
            }

            else if(ptr->next==head){
                ptr_prev->next=NULL;
                free(ptr);
                ptr=NULL;
            }

            else{
                ptr_prev->next=ptr->next;
                ptr->next=NULL;
                free(ptr);
                ptr=NULL;
            }

        }

        else{
            printf("\nThe element does not exist! ");
        }



    }

}

void Display(){
    
    if (head==NULL){
        printf("\nLL Empty\n");
    }

    else{

        struct Node* ptr=head->next;

        printf("%d ",head->data);

        while(ptr!=head && ptr!=NULL){
            printf("%d ",ptr->data);
            ptr=ptr->next;
        }
    
    }

}

int main(){

    int choice;
    int c;
    int elem;

    int next_elem;

    do{

        printf("\n1.Insert");
        printf("\n2.Delete");
        printf("\n3.Display");
        printf("\n4.Exit");

        printf("\n\nChoice: ");
        scanf("%d",&choice);

        switch(choice){

            case 1:

                printf("\n1.Insert Back");
                printf("\n2.Insert Front");
                printf("\n3.Insert wrt next Number");

                printf("\n\nEnter Choice: ");
                scanf("%d",&c);

                printf("\nEnter the element: ");
                scanf("%d",&elem);

                switch(c){

                    case 1:
                        InsertBack(elem);
                        break;
                    
                    case 2:
                        InsertFront(elem);
                        break;
                    
                    case 3:
                        printf("\nEnter the Number after it needs to be inserted: ");
                        scanf("%d",&next_elem);
                        InsertAnyPos(elem,next_elem);
                        break;

                    default:
                        printf("\nInvalid Choice!");

                }

            break;
            
            case 2:

                printf("\n1 Delete Back");
                printf("\n2 Delete Front");
                printf("\n3 Delete according to Number");

                printf("\n\nEnter Choice: ");
                scanf("%d",&c);

                switch(c){

                    case 1:
                        DeleteBack(elem);
                        break;
                    
                    case 2:
                        DeleteFront(elem);
                        break;
                    
                    case 3:
                        printf("\nEnter the Number to be deleted: ");
                        scanf("%d",&next_elem);
                        DeleteAnyNumber(next_elem);
                        break;

                    default:
                        printf("\nInvalid Choice!");
                }

            break;

            case 3:
                Display();
                break;
            
            case 4:
                printf("\n");
                break;
            
            default:
                printf("\nInvalid Choice!");
                break;

        }

    }while (choice!=4);

}