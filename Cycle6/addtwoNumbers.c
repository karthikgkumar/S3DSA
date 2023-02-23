#include <stdio.h>
#include <stdlib.h>

// Doubly linked list node
struct node {
    int data;
    struct node* next;
    struct node* prev;
};

// Function to create a new node
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to add a node at the end of the list
void addNode(struct node** head, int data) {
    struct node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Function to add two numbers represented as doubly linked lists
struct node* addLists(struct node* first, struct node* second) {
    struct node* result = NULL;
    struct node* prev = NULL;
    int carry = 0;

    while (first != NULL || second != NULL) {
        int sum = carry + (first ? first->data : 0) + (second ? second->data : 0);
        carry = (sum >= 10) ? 1 : 0;
        sum = sum % 10;
        struct node* newNode = createNode(sum);
        if (result == NULL) {
            result = newNode;
        } else {
            prev->next = newNode;
            newNode->prev = prev;
        }
        prev = newNode;
        if (first) first = first->next;
        if (second) second = second->next;
    }

    if (carry > 0) {
        struct node* newNode = createNode(carry);
        prev->next = newNode;
        newNode->prev = prev;
    }

    return result;
}

// Function to print the doubly linked list
void printList(struct node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    // Create two doubly linked lists
    struct node* first = NULL;
    struct node* second = NULL;

    // Add elements to the first list
    addNode(&first, 2);
    addNode(&first, 4);
    addNode(&first, 3);

    // Add elements to the second list
    addNode(&second, 5);
    addNode(&second, 6);
    addNode(&second, 4);

    // Add the two lists and store the result in a new list
    struct node* result = addLists(first, second);

    // Print the result
    printf("Result: ");
    printList(result);

    return 0;
}
