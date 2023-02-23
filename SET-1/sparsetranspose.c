#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int row;
    int col;
    int val;
} sparse;

void readSparse(sparse a[], int s) {
    int i, norows, nocols;
    printf("Enter number of rows: ");
    scanf("%d", &norows);
    printf("Enter number of columns: ");
    scanf("%d", &nocols);
    a[0].row = norows;
    a[0].col = nocols;
    a[0].val = s;
    printf("Enter sparse matrix in sparse form:\n");
    for(i = 1; i <= s; i++) {
        scanf("%d %d %d", &a[i].row, &a[i].col, &a[i].val);
    }
}

void printSparse(sparse a[]) {
    printf("\nRows Column Value\n");
    for(int i = 0; i <= a[0].val; i++) {
        printf("%d\t%d\t%d\n", a[i].row, a[i].col, a[i].val);
    }
}

void transposeSparse(sparse a[], sparse trans[]) {
    int numTerms = a[0].val;
    trans[0].row = a[0].col;
    trans[0].col = a[0].row;
    trans[0].val = numTerms;
    if(numTerms > 0) {
        int currentB, i, j;
        currentB = 1;
        for(i = 0; i < a[0].col; i++) {
            for(j = 1; j <= numTerms; j++) {
                if(a[j].col == i) {
                    trans[currentB].row = a[j].col;
                    trans[currentB].col = a[j].row;
                    trans[currentB].val = a[j].val;
                    currentB++;
                }
            }
        }
    }
}

int main() {
    sparse a[100], trans[100];
    readSparse(a, 1);
    transposeSparse(a, trans);
    printf("\nEntered Matrix: ");
    printSparse(a);
    printf("\nTranspose Matrix: ");
    printSparse(trans);
    return 0;
}
