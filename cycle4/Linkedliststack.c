#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int data;
    struct node *next;
}*top,*newnode,*ptr;
 
int topelement();
void push(int data);
void pop();
void empty();
void display();

void stack_count();
void create();
 
int count = 0;
 
void main()
{
    int no, ch, e;
 
    printf("\n 1 - Push");
    printf("\n 2 - Pop");
    printf("\n 3 - Display");
    printf("\n 4 - Peek");
    printf("\n 5 - Stack Count");
    printf("\n 6 -Exit");
 
    create();
 
    while (1)
    {
        printf("\n Enter choice : ");
        scanf("%d", &ch);
 
        switch (ch)
        {
        case 1:
            printf("Enter data : ");
            scanf("%d", &no);
            push(no);
            break;
        case 2:
            pop();
            break;
        case 3:
        	display();
            break;
            
        case 4:
            if (top == NULL)
                printf("No elements in stack");
            else
            {
                e = topelement();
                printf("\n Top element : %d", e);
            }
            break;
        case 5:
        	stack_count();
            break;
        case 6:
        	exit(0);
        
        default :
            printf(" Wrong choice, Please enter correct choice  ");
            break;
        }
    }
}
 
/* Create empty stack */
void create()
{
    top = NULL;
}
 
/* Count stack elements */
void stack_count()
{
    printf("\n No. of elements in stack : %d", count);
}
 
/* Push data into stack */
void push(int data)
{

        newnode=(struct node *)malloc(1*sizeof(struct node));
        newnode->data = data;
        newnode->next = top;
        top=newnode;
    count++;
}
 
/* Display stack elements */
void display()
{
    ptr = top;
 
    if (top == NULL)
    {
        printf("Stack is empty");
        return;
    }
    else{
	
    printf("top");
    while (ptr != NULL)
    {
        printf("->%d ", ptr->data);
        ptr = ptr->next;
    }
	}
 }
 
/* Pop Operation on stack */
void pop()
{
    ptr= top;
 
    if (ptr == NULL)
    {
        printf("\n Error : Trying to pop from empty stack");
        return;
    }
    else {
	
	printf("\n Popped value : %d", top->data);
        top= top->next;
         free(ptr);
            
    count--;
		}
   

}
 
/* Return top element */
int topelement()
{
    return(top->data);
}
 
/* Check if stack is empty or not */
void empty()
{
    if (top == NULL)
        printf("\n Stack is empty");
    else
        printf("\n Stack is not empty with %d elements", count);
}
 

