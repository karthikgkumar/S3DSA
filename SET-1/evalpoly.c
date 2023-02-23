#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int exp;
    float coeff;
} polynomial;

void readPoly(polynomial a[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("Enter coefficient and exponent of term in order: ");
        scanf("%f %d", &a[i].coeff, &a[i].exp);
    }
}

void printPoly(polynomial a[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%6.2fx^%d", a[i].coeff, a[i].exp);
        if (i != n - 1) {
            printf(" + ");
        }
        if (a[i].exp < 0) {
            printf("can't be evaluated due to negative exponent");
            exit(1);
        }
    }
    printf("\n");
}

int evalPoly(polynomial a[], int n, int x) {
    int result = 0, i;
    for (i = 0; i < n; i++) {
        result += a[i].coeff * pow(x, a[i].exp);
    }
    return result;
}

int main() {
    polynomial a[100];
    int n1, x;
    printf("Enter no. of terms of the polynomial: ");
    scanf("%d", &n1);
    readPoly(a, n1);
    printf("Entered polynomial is: ");
    printPoly(a, n1);
    printf("Enter value of x: ");
    scanf("%d", &x);
    printf("Value of polynomial = %d\n", evalPoly(a, n1, x));
    return 0;
}
