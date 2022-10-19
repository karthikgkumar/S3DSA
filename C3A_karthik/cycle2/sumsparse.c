#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int row;
    int col;
    int val;
}sparse;

float readtoSparse(sparse a[],int count){
    int m,n,spar,element,k=1;
    float sparsity;
    printf("Enter no. of rows of matrix %d: ",count);
    scanf("%d",&m);
    printf("Enter no. of columns of matrix %d:",count);
    scanf("%d",&n);
    a[0].row = m;
    a[0].col = n;
    printf("Enter elements of matrix: \n");
    for(int i =0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&element);
            if(element != 0){
                spar++;
                a[k].row = i;
                a[k].col = j;
                a[k].val = element;
                k++;
            }
        }
    }
    a[0].val = k-1;
    sparsity = (float)(m*n-spar)/(m*n);
    return sparsity;
}

void printSparse(sparse a[]){
    printf("\nRows Column Value");
    for(int i = 0;i <= a[0].val;i++){
        printf("\n%d\t%d\t%d",a[i].row,a[i].col,a[i].val);
    }
}

void sumofSparse(sparse a[],sparse b[],sparse sum[]){
    int i=1,j=1,l=1;
    if(a[0].row != b[0].row || a[0].col != b[0].col)
    {
        printf("Cannot find sum");
        exit(0);
    }
    sum[0].row = a[0].row;
    sum[0].col = a[0].col;

    void addA(){
        sum[l].row = a[i].row;
        sum[l].col = a[i].col;
        sum[l].val = a[i].val;
        i++;
        l++;
    }

    void addB(){
        sum[l].row = b[j].row;
        sum[l].col = b[j].col;
        sum[l].val = b[j].val;
        j++;
        l++;
    }

    while(i<=a[0].val && j <= b[0].val){
        if(a[i].row < b[j].row || (a[i].row == b[j].row && a[i].col < b[j].col)){
            addA();
        }
        else if(a[i].row > b[j].row || (a[i].row == b[j].row && a[i].col > b[j].col)){
            addB();
        }
        else if(a[i].row == b[j].row && a[i].col == b[j].col){
            sum[l].row= a[j].row;
            sum[l].col = a[i].col;
            sum[l].val = a[i].val + b[j].val;
            i++;
            j++;
            l++;
        }
    }

    while (i<=a[0].val)
    {
        addA();
    }

    while (j<=b[0].val)
    {
        addB();
    }
    sum[0].val = l-1;
}

void main(){
    sparse a[100],b[100],sum[100];
    readtoSparse(a,1);
    readtoSparse(b,2);
    sumofSparse(a,b,sum);
    printf("\n\nFirst matrix: ");
    printSparse(a);
    printf("\n\nSecond matrix: ");
    printSparse(b);
    printf("\n\nSum:");
    printSparse(sum);
}