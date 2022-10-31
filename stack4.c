#include <stdio.h>
#define MAX 100
int stack[MAX],top=-1;
void push(int data)
{
    if(top==MAX-1)
        printf("\nStack Overflow");
    else if(top==-1)
        stack[++top]=data;
    else
    {
        int tempstack[MAX],temptop=-1;
        while(data>stack[top]&&top!=-1)
        {
            int del=stack[top--];
            tempstack[++temptop]=del;
        }
        stack[++top]=data;
        while(temptop>=0)
        {
            int del=tempstack[temptop--];
            stack[++top]=del;
        }
    }    
}
void pop()
{
    int del;
    if(top==-1)
        printf("\nStack empty.");
    else
    {
        del=stack[top--];
        printf("\nDeleted : %d",del);
    }    
}
void display()
{
    if(top==-1)
        printf("\nStack empty!!\n");
    else
    {
        printf("\n");
        for(int i=top;i>=0;i--)
        {
            printf("%d\n",stack[i]);
        }
    }    
}
int main()
{
    int ch,element;
    do
    {
        printf("\n1.Push");
        printf("\n2.Pop");
        printf("\n3.Display stack");
        printf("\n4.Exit");
        printf("\n\nChoose operation : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("\nEnter element to be inserted  ");
                scanf("%d",&element);
                push(element);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;    
        }
    }while(ch<4);
    return 0;
}
