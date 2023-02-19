#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int row;
    int col;
    int val;
}sparse;

void readSparse(sparse a[],int s){
    int i,norows,nocols;
    a[0].val=s;
    printf("enter number of rows\n");
    scanf("%d",&norows);
    printf("enter number of columns\n");
    scanf("%d",&nocols);
    a[0].col=nocols;
    a[0].row=norows;
    printf('enter sparse matrix in sparse form \n');
    for(i=1;i<=s;i++){
        scanf("%d %d %d", &a[i].row,&a[i].col,&a[i].val);
    }
    
    
}

void printSparse(sparse a[]){
    printf("\nRows Column Value");
    for(int i = 0;i <= a[0].val;i++){
        printf("\n%d\t%d\t%d",a[i].row,a[i].col,a[i].val);
    }
}

void transparse(sparse a[],sparse trans[]){
    trans[0].col = a[0].row;
    trans[0].row = a[0].col;
    trans[0].val = a[0].val;
    int l = 1;
    if(a[0].val > 0){
        for(int i=0; i < a[0].col; i++){
            for(int j=1; j <= a[0].val; j++){
                if(a[j].col == i){
                    trans[l].row = a[j].col;
                    trans[l].col = a[j].row;
                    trans[l].val = a[j].val;
                    l++;
                }
            }
        }
    }
}

void main(){
    sparse a[100],trans[100];
    readSparse(a,1);
    transparse(a,trans);
    printf("\n\nEntered Matrix: ");
    printSparse(a);
    printf("\n\nTranspose Matrix: ");
    printSparse(trans);
}