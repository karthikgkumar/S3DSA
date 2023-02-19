#include <stdio.h>
#include <math.h>
#define max 100
typedef struct
{
    float coeff;
    int exp;
} poly;
poly terms[max];
int avail = 0;
int starta, startb, finisha, finishb, startd, finishd;
void polyadd(int starta, int startb, int finisha, int finishb, int startd, int *finishd);
void attach(float coeff, int exp, int index);
int main()
{
    int i;
    starta = avail;
    printf("Enter the number of terms in polynomial1:");
    scanf("%d", &finisha);
    finisha--;
    printf("\nEnter the coeffecients and exponents in DESCENDING order");
    for (i = starta; i <= finisha; i++)
    {
        printf("\nCoeffecient :");
        scanf("%f", &terms[i].coeff);
        printf("Exponent :");
        scanf("%d", &terms[i].exp);
        avail++;
    }

    printf("Enter the number of terms in polynomial2:");
    scanf("%d", &i);
    finishb = finisha + i;
    printf("\nEnter the coeffecients and exponents in DESCENDING order");
    for (i = finisha + 1; i <= finishb; i++)
    {
        printf("\nCoeffecient :");
        scanf("%f", &terms[i].coeff);
        printf("Exponent :");
        scanf("%d", &terms[i].exp);
        avail++;
    }
    // printing first polynomial
    printf("\nExpression 1 = %.2fx^%d ", terms[0].coeff, terms[0].exp);
    for (i = 1; i <= finisha; i++)
    {
        printf("+ %.2fx^%d", terms[i].coeff, terms[i].exp);
    }

    // printing second polynomial
    printf("\nExpression 2 = %.2fx^%d ", terms[finisha + 1].coeff, terms[finisha + 1].exp);
    for (i = finisha + 2; i <= finishb; i++)
    {
        printf("+ %.2fx^%d", terms[i].coeff, terms[i].exp);
    }
    printf("\n");

    startd = avail;
    finishd = avail - 1;
    startb = finisha + 1;
    polyadd(starta, startb, finisha, finishb, startd, &finishd);
    printf("The resultant expression is: %.2fx^%d", terms[startd].coeff, terms[startd].exp);
    for (i = startd + 1; i <= finishd; i++)
    {
        printf("+ %.2fx^%d ", terms[i].coeff, terms[i].exp);
    }
    printf("\n");
    return 0;
}

void polyadd(int starta, int startb, int finisha, int finishb, int startd, int *finishd)
{
    while (starta <= finisha && startb <= finishb)
    {
        if (terms[starta].exp == terms[startb].exp)
        {
            float coefficient = terms[startb].coeff + terms[starta].coeff;
            if (coefficient)
            {
                attach(coefficient, terms[startb].exp, startd);
                starta++;
                startb++;
                startd++;
                *finishd = *finishd + 1;
            }
        }
        else if (terms[starta].exp > terms[startb].exp)
        {
            attach(terms[starta].coeff, terms[starta].exp, startd);
            starta++;
            startd++;
            *finishd = *finishd + 1;
        }
        else if (terms[starta].exp < terms[startb].exp)
        {
            attach(terms[startb].coeff, terms[startb].exp, startd);
            startb++;
            startd++;
            *finishd = *finishd + 1;
        }
    }
    while (starta <= finisha)
    {
        attach(terms[starta].coeff, terms[starta].exp, startd);
        starta++;
        startd++;
        *finishd = *finishd + 1;
    }
    while (startb <= finishb)
    {
        attach(terms[startb].coeff, terms[startb].exp, startd);
        startb++;
        startd++;
        *finishd = *finishd + 1;
    }
}

void attach(float coeff, int exp, int index)
{
    terms[index].coeff = coeff;
    terms[index].exp = exp;
}