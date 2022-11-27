//Implement multiple stacks(2 stacks) using an array. Consider memory
//efficient implementation

#include<stdio.h>
#define MAX 5
int stack[MAX],top1=-1,top2=MAX;
void push(int stackno,int data)
{
     if (stackno==1)
    {
        if (top1==top2 - 1)
        {
            printf("\nStack 1 full");
        }
        else
        {
            stack[++top1]=data;
        }
    }
    else if(stackno==2)
    {
        if (top2==top1+1)
        {
            printf("\nStack 2 full");
        }
        else
        {
            stack[--top2]=data;
        }
    }
}
int pop(int stackno)
{
    if (stackno==1)
    {
        if (top1==-1)
        {
            printf("\nStack 1 empty");
            return -1;
        }
        return stack[top1--];
    }
    else if(stackno==2)
    {
        if (top2==MAX)
        {
            printf("\nStack 2 empty");
            return -1;
        }
        return stack[top2++];
    }
}
void display(int stackno)
{
    if (stackno==1)
    {
        if (top1==-1)
        {
            printf("\nStack 1 empty");
            return;
        }
        printf("\nElements of stack 1\n");
        for(int i=top1;i>=0;i--)
            printf("%d ",stack[i]);
    }
    else if(stackno==2)
    {
        if (top2==MAX)
        {
            printf("\nStack 2 empty");
            return;
        }
        printf("\nElements of stack 2\n");
        for(int i=top2;i<=MAX-1;i++)
            printf("%d ", stack[i]);
    }
}
int main()
{
    int stackno, ch, element, popped;
    printf("\nEnter stack number (1 or 2) ");
    scanf("%d", &stackno);
    do
    {
        printf("\n\nChoose operation");
        printf("\n1.Push");
        printf("\n2.Pop");
        printf("\n3.Display");
        printf("\n4.Change stack number");
        printf("\n5.EXIT\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter element to insert ");
            scanf("%d",&element);
            push(stackno,element);
            break;
        case 2:
            popped=pop(stackno);
            printf("\nPopped element %d ",popped);
            break;
        case 3:
            display(stackno);
            break;
        case 4:
            printf("\nEnter stack number (1 or 2)");
            scanf("%d", &stackno);
            break;
        }
    } while(ch<5);
    return 0;
}
