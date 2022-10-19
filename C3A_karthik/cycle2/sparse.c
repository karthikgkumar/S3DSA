#include<stdio.h>

typedef struct{
    int row;
    int col;
    int val;
}sparse;

float readtoSparse(sparse a[]){
    int m,n,spar=0,element,k=1;
    float sparsity;
    printf("Enter no. of rows of matrix: ");
    scanf("%d",&m);
    printf("Enter no. of columns of matrix: ");
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

void main(){
    sparse a[100];
    float sparsity = readtoSparse(a);
    printf("Sparse representation is :");
    printSparse(a);
    printf("\nSparsity of the matrix is : %0.2f%%",sparsity*100);
}