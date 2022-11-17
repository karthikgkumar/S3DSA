
#include<stdio.h>
#include<ctype.h>
#include<string.h>
int stack[20];
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

void push(int x)
{
    stack[++top] = x;
}

int pop()
{
    return stack[top--];
}

int main()
{
    char exp[100];
    char *e;
    int n1,n2,n3,num,ch;
    printf("1.Evaluate postfix expression");
    printf("2.Evaluate prefix expression");
    printf("enter the choice 1/2");
    scanf("%d",&ch);
    if (ch==1){
    printf("Enter the postfix expression :: ");
    scanf("%s",exp);
    e = exp;
    while(*e != '\0')
    {
        if(isdigit(*e))
        {
            num = *e - 48;
            push(num);
        }
        else
        {
            n1 = pop();
            n2 = pop();
            switch(*e)
            {
            case '+':
            {
                n3 = n1 + n2;
                break;
            }
            case '-':
            {
                n3 = n2 - n1;
                break;
            }
            case '*':
            {
                n3 = n1 * n2;
                break;
            }
            case '/':
            {
                n3 = n2 / n1;
                break;
            }
            }
            push(n3);
        }
        e++;
    }
    printf("\nThe result of expression  =  %d\n\n",pop());
    return 0;
     }
if(ch==2){
    printf("Enter the prefix expression :: ");
    scanf("%s",exp);
    int l=strlen(exp);
    reverse(exp,0,l-1);
    e = exp;
    while(*e != '\0')
    {
        if(isdigit(*e))
        {
            num = *e - 48;
            push(num);
        }
        else
        {
            n1 = pop();
            n2 = pop();
            switch(*e)
            {
            case '+':
            {
                n3 = n1 + n2;
                break;
            }
            case '-':
            {
                n3 = n2 - n1;
                break;
            }
            case '*':
            {
                n3 = n1 * n2;
                break;
            }
            case '/':
            {
                n3 = n2 / n1;
                break;
            }
            }
            push(n3);
        }
        e++;
    }
    printf("\nThe result of expression=  %d\n\n",pop());
    return 0;

}
}