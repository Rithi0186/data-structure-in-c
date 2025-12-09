#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;

// Create node
struct node* createNode(int value) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory Not Allocated\n");
        return NULL;
    }
    newnode->data = value;
    newnode->next = NULL;
    return newnode;
}

// PUSH operation
void push(int value) {
    struct node *newnode = createNode(value);
    newnode->next = top;
    top = newnode;
    printf("%d pushed to stack\n", value);
}

// POP operation
void pop() {
    if (top == NULL) {
        printf("Stack Underflow (Empty Stack)\n");
        return;
    }

    struct node *temp = top;
    printf("%d popped from stack\n", temp->data);
    top = top->next;
    free(temp);
}

// PEEK operation
void peek() {
    if (top == NULL) {
        printf("Stack is Empty\n");
        return;
    }
    printf("Top element = %d\n", top->data);
}

// DISPLAY stack
void display() {
    if (top == NULL) {
        printf("Stack is Empty\n");
        return;
    }

    struct node *temp = top;
    printf("Stack elements:\n");
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- STACK MENU ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
