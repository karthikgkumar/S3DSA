// polynomial multiplication
#include <stdio.h>
#include<stdlib.h>
typedef struct poly
{
    float coeff;
    int expo;
    struct poly *next;
} Node;
Node *head =NULL, *head1 = NULL, *head2 =NULL, *head3 = NULL;
Node *ptr1, *ptr2;

Node *insert(Node *head, float coeff, int expo)
{
    Node *newnode =(Node*) malloc(sizeof(Node));
    newnode->coeff = coeff;
    newnode->expo = expo;
    newnode->next = NULL;
    Node *temp = head;
    if (head == NULL || expo > head->expo)
    {
        newnode->next = head;
        head = newnode;
        return head;
    }
    while (temp->next != NULL && temp->next->expo > expo)
    {
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
    return head;
}

Node* create_poly(Node *head)
{
    int n, i;
    float coeff;
    int expo;
    printf("enter the polynomials terms\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("enter the coefficient for %d \n ", i + 1);
        scanf("%f", &coeff);
        printf("enter the exponent for %d\n", i + 1);
        scanf("%d", &expo);
        head = insert(head, coeff, expo);
    }
    return head;
}

void print(Node *head)
{
    if (head == NULL)
    {
        printf("no polynomial\n");
    }
    else
    {
        Node* temp;
        temp=head;
        while (temp != NULL)
        {
            printf("%.2fx^%d", temp->coeff, temp->expo);
            temp = temp->next;
            if (temp != NULL)
            {
                printf("+");
            }
            else
                printf("\n");
        }
    }
}


Node  *poly_multi(Node *head1, Node *head2)
{
    int res1, res2;
    ptr1 = head1;
    while (ptr1 != NULL)
    {
        ptr2 = head2;
        while (ptr2 != NULL)
        {
            res1 = ptr1->coeff * ptr2->coeff;
            res2 = ptr1->expo + ptr2->expo;
            head3=insert(head3, res1, res2);
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
    return head3;
}

int  main()
{
    head1=create_poly(head1);
    print(head1);
    head2=create_poly(head2);
    print(head2);
    poly_multi(head1, head2);
    print(head3);
    return 0;
}