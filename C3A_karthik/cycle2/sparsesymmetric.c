#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int row;
    int col;
    int val;
}sparse;

void readtoSparse(sparse a[],int count){
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
}

void printSparse(sparse a[]){
    printf("\nRows Column Value");
    for(int i = 0;i <= a[0].val;i++){
        printf("\n%d\t%d\t%d",a[i].row,a[i].col,a[i].val);
    }
}

void sparsesym(sparse a[]){
    int flag;
    int i,j;
    for(i=1;i<=a[0].val;i++){
        flag = 0;
        for(j=1;j<=a[0].val;j++){
            if(a[i].col == a[j].row && a[i].row == a[j].col)
             {
                if(a[i].val == a[j].val)
                {
                    flag = 1;
                    break;
                }
                else{
                    break;
                }
             }
        }
        if(flag == 0){
            printf("Not Sparse Symmetric");
            return;
        }
    }
    printf("Sparse Symmetric");
}

void main(){
    sparse a[100];
    readtoSparse(a,1);
    sparsesym(a);
}