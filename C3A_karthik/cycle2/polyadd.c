#include<stdio.h>

typedef struct{
    int exp;
    int coeff;
}polynomial;


void readPoly(polynomial a[],int start,int end){
    int i,k=0;
    for(i=start;i<=end;i++,k++)
    {
        printf("Enter coefficient and exponent of term %d in order of increasing exponents: ",k+1);
        scanf("%d",&a[i].coeff);
        scanf("%d",&a[i].exp);
    }
}

void printPoly(polynomial a[],int start,int end){
    int i,k=0;
    for(i=start;i<=end;i++,k++)
    {
        printf("%dx^%d",a[i].coeff,a[i].exp);
        if(i!=end){
            printf(" + ");
        }
    }
    printf("\n");
}




void polySum(polynomial a[],polynomial sum[],int startA,int endA,int startB,int endB,int startD, int *end){
    int i=0,j=0;
    int endD  = *end;
    void addA(){
            a[endD].exp = a[startA].exp;
            a[endD].coeff = a[startA].coeff;
            startA++;
            endD++;
    }

    void addB(){
            a[endD].exp = a[startB].exp;
            a[endD].coeff = a[startB].coeff;
            startB++;
            endD++;
    }
    while(startA<=endA && startB <= endB){
        if(a[startA].exp < a[startB].exp){
            addA();
        }
        else if (a[startA].exp > a[startB].exp){
            addB();
        }
        else {
            a[endD].exp = a[startB].exp;
            a[endD].coeff = a[startA].coeff + a[startB].coeff;
            startA++;
            startB++;
            endD++;
        }
    }

    while (startA<=endA)
    {
        addA();
    }

    while (startB<=endB)
    {
        addB();
    }
    *end = endD-1;
}

void main(){
    polynomial a[100],sum[100];
    int n1,n2,startA,endA,startB,endB,startD,endD;
    printf("Enter no. of terms of first polynomial : ");
    scanf("%d",&n1);
    startA = 0;
    endA = n1-1;
    startB = n1;
    printf("Enter no. of terms of second polynomial : ");
    scanf("%d",&n2);
    endB = n1+n2-1;
    startD = n1+n2;
    endD = startD;
    readPoly(a,startA,endA);
    readPoly(a,startB,endB);
    polySum(a,sum,startA,endA,startB,endB,startD,&endD);
    printPoly(a,startA,endA);
    printPoly(a,startB,endB);
    printf("Sum is : ");
    printPoly(a,startD,endD);
}