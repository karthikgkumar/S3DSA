#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int row;
    int col;
    int val;
} sparse;

void readToSparse(sparse a[], int count) {
    int m, n, element, k = 1;
    float sparsity;
    printf("Enter no. of rows of matrix %d: ", count);
    scanf("%d", &m);
    printf("Enter no. of columns of matrix %d: ", count);
    scanf("%d", &n);
    a[0].row = m;
    a[0].col = n;
    printf("Enter elements of matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &element);
            if (element != 0) {
                a[k].row = i;
                a[k].col = j;
                a[k].val = element;
                k++;
            }
        }
    }
    a[0].val = k - 1;
}

void printSparse(sparse a[]) {
    printf("\nRows Column Value\n");
    for (int i = 0; i <= a[0].val; i++) {
        printf("%d\t%d\t%d\n", a[i].row, a[i].col, a[i].val);
    }
}

void sparseSym(sparse a[]) {
    int flag;
    for (int i = 1; i <= a[0].val; i++) {
        flag = 0;
        for (int j = 1; j <= a[0].val; j++) {
            if (a[i].col == a[j].row && a[i].row == a[j].col) {
                if (a[i].val == a[j].val) {
                    flag = 1;
                    break;
                } else {
                    break;
                }
            }
        }
        if (flag == 0) {
            printf("Not Sparse Symmetric\n");
            return;
        }
    }
    printf("Sparse Symmetric\n");
}

int main() {
    sparse a[100];
    readToSparse(a, 1);
    sparseSym(a);
    return 0;
}
