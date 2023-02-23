#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int row;
    int col;
    int val;
} sparse;

void readSparse(sparse a[], int s) {
    int i, norows, nocols;
    a[0].val = s;
    printf("Enter number of rows: ");
    scanf("%d", &norows);
    printf("Enter number of columns: ");
    scanf("%d", &nocols);
    a[0].col = nocols;
    a[0].row = norows;
    printf("Enter sparse matrix in sparse form:\n");
    for (i = 1; i <= s; i++) {
        scanf("%d %d %d", &a[i].row, &a[i].col, &a[i].val);
    }
}

void printSparse(sparse a[]) {
    printf("\nRows Column Value");
    for (int i = 0; i <= a[0].val; i++) {
        printf("\n%d\t%d\t%d", a[i].row, a[i].col, a[i].val);
    }
}

void sparseSum(sparse a[], sparse b[], sparse sum[]) {
    int i = 1, j = 1, l = 1;
    if (a[0].row != b[0].row || a[0].col != b[0].col) {
        printf("Cannot find sum");
        exit(0);
    }
    sum[0].row = a[0].row;
    sum[0].col = a[0].col;

    void addA() {
        sum[l].row = a[i].row;
        sum[l].col = a[i].col;
        sum[l].val = a[i].val;
        i++;
        l++;
    }

    void addB() {
        sum[l].row = b[j].row;
        sum[l].col = b[j].col;
        sum[l].val = b[j].val;
        j++;
        l++;
    }

    while (i <= a[0].val && j <= b[0].val) {
        if (a[i].row < b[j].row || (a[i].row == b[j].row && a[i].col < b[j].col)) {
            addA();
        } else if (a[i].row > b[j].row || (a[i].row == b[j].row && a[i].col > b[j].col)) {
            addB();
        } else if (a[i].row == b[j].row && a[i].col == b[j].col) {
            sum[l].row = a[i].row;
            sum[l].col = a[i].col;
            sum[l].val = a[i].val + b[j].val;
            i++;
            j++;
            l++;
        }
    }

    while (i <= a[0].val) {
        addA();
    }

    while (j <= b[0].val) {
        addB();
    }

    sum[0].val = l - 1;
}

int main(){
    sparse a[100],b[100],sum[100];
    int s1,s2;
    printf("Enter number of non-zero elements in matrix 1: ");
    scanf("%d",&s1);
    readSparse(a,s1);
    printf("Enter number of non-zero elements in matrix 2: ");
    scanf("%d",&s2);
    readSparse(b,s2);
    sparseSum(a,b,sum);
    printf("\n\nFirst matrix: ");
    printSparse(a);
    printf("\n\nSecond matrix: ");
    printSparse(b);
    printf("\n\nSum:");
    printSparse(sum);
    return 0;
}
