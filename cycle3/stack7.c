//7) Convert a given infix expression to postfix/prefix

#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
char stack[MAX],postfix[MAX],infix[MAX],prefix[MAX];
int top = -1;

void reverse(char str1[], int index, int size)
{
    char temp;

    temp = str1[index];
    str1[index] = str1[size - index];
    str1[size - index] = temp;

    if (index == size / 2)
    {
        return;
    }
    reverse(str1, index + 1, size);
}

void push(char x)
{
     if(top==MAX-1)
        printf("Stack Overflow\n");
    else
    stack[++top] = x;
}

char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

int priority(char symbol)
{
    switch(symbol)
    {
        case '+':
            return 1;
        case '-':
            return 1;

        case '*':

        case '/':
            return 2;
        case '^':
           return 3;
        default:
            return 0;


    }
}
int isEmpty(){
    if (top==-1)
       return 1;
    else
       return 0;

}


void intopost(){
    int i,j=0;
    char symbol,next;
    for(i=0;i<strlen(infix);i++){
        symbol=infix[i];
        // if(space(symbol)==1)
        {

        
        switch(symbol){
            case '(':
               push(symbol);
               break;
            case ')':
               while((next=pop())!='(')
                   postfix[j++]=next;
                   break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
               while(!isEmpty() && priority(stack[top])>=priority(symbol))
                    postfix[j++]=pop();
               push(symbol);
               break;
            default:
                postfix[j++]=symbol;
        }

        }
    }
    while(!isEmpty())
    {
        postfix[j++]=pop();
    }
    postfix[j]='\0';
}
int intopre(){
    int i,j=0;
    int symbol,next;
    int size = strlen(infix);
    reverse(infix,0,size-1);
    for(i=0;i<strlen(infix);i++)
     {
        symbol=infix[i];
        // if(space(symbol)==1)
        {

        
        switch(symbol){
            case '(':
            while((next=pop())!=')')
                   prefix[j++]=next;
                   break;
              
            case ')':
               push(symbol);
               break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
               while(!isEmpty() && priority(stack[top])>priority(symbol))
                    prefix[j++]=pop();
               push(symbol);
               break;
            default:
                prefix[j++]=symbol;
        }

        }
    }
    while(!isEmpty())
    {
        prefix[j++]=pop();
    }
    int l=strlen(prefix);
        reverse(prefix,0,l-1);

        printf("\nthe length of the expression is %d",l);
    prefix[j]='\0';
    

}
    void postprint()
    {
        int i;
        printf("\nthe equivalent postfix expression is ");
        
        for(i=0;postfix[i]!='\0';i++)
        {
            printf("%c",postfix[i]);
        }
        printf("\n");
        
        
    }

    void preprint()
    {
        int i;
        printf("\nthe equivalent prefix expression is ");
        
        
       for(i=0;prefix[i]!='\0';i++)
        {
            printf("%c",prefix[i]);
        }
        printf("\n");
        
        
    }


int main()
{
    
   
    printf("Enter the infix expression : ");
    gets(infix);
    intopost();
    postprint();
    intopre();
    preprint();


     
    
    return 0;
}
