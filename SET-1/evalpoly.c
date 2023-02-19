#include<stdio.h>
#include<math.h>
#include<stdlib.h>

typedef struct{
    int exp;
    float coeff;
}polynomial;


void readPoly(polynomial a[],int start,int end){
    int i;
    for(i=start;i<=end;i++)
    {
        printf("Enter coefficient and exponent of term in order :");
        scanf("%f",&a[i].coeff);
        scanf("%d",&a[i].exp);
    }
}

void printPoly(polynomial a[],int start,int end){
    int i;
    for(i=start;i<=end;i++)
    {
        printf("%6.2fx^%d",a[i].coeff,a[i].exp);
        if(i!=end){
            printf(" + ");
        }
        if (a[i].exp< 0)
        {
        	printf("cant be evaluated due to negative exponent");
            exit(1);
        }
        /*  printing proper polynomial function */
    }
    printf("\n");
}

int evalPoly(polynomial a[],int start,int end,int x){
    int result = 0;
    while(start<=end){
        result += a[start].coeff * pow(x,a[start].exp);
        start++;
    }
    return result;
}


void main(){
    polynomial a[100];
    int n1,x,startA,endA;
    printf("Enter no. of terms of the polynomial: ");
    scanf("%d",&n1);
    startA = 0;
    endA = n1-1;
    readPoly(a,startA,endA);
    printf("Entered polynomial is : ");
    printPoly(a,startA,endA);
    printf("Enter value of x: ");
    scanf("%d",&x);
    printf("Value of Polynomial = %d",evalPoly(a,startA,endA,x));
}
