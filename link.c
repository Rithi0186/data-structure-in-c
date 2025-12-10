#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

// CREATE NODE
struct node* createNode(int value) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// INSERT AT BEGINNING
void insertAtBeginning(int value) {
    struct node *newNode = createNode(value);

    newNode->next = head;
    head = newNode;

    printf("%d inserted at beginning\n", value);
}

// INSERT AT END
void insertAtEnd(int value) {
    struct node *newNode = createNode(value);

    if (head == NULL) {
        head = newNode;
    } else {
        struct node *t = head;
        while (t->next != NULL)
            t = t->next;

        t->next = newNode;
    }
    printf("%d inserted at end\n", value);
}

// INSERT AT POSITION
void insertAtPosition(int value, int pos) {
    if (pos == 1) {
        insertAtBeginning(value);
        return;
    }

    struct node *newNode = createNode(value);
    struct node *t = head;
    int i;

    for (i = 1; i < pos - 1 && t != NULL; i++)
        t = t->next;

    if (t == NULL) {
        printf("Position out of range!\n");
        return;
    }

    newNode->next = t->next;
    t->next = newNode;

    printf("%d inserted at position %d\n", value, pos);
}

// DELETE AT BEGINNING
void deleteBeginning() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct node *temp = head;
    head = head->next;
    free(temp);

    printf("Node deleted from beginning\n");
}

// DELETE AT END
void deleteEnd() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct node *t = head, *prev = NULL;

    if (head->next == NULL) {  
        free(head);
        head = NULL;
    } else {
        while (t->next != NULL) {
            prev = t;
            t = t->next;
        }
        prev->next = NULL;
        free(t);
    }

    printf("Node deleted from end\n");
}

// DELETE AT POSITION
void deleteAtPosition(int pos) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if (pos == 1) {
        deleteBeginning();
        return;
    }

    struct node *t = head, *prev = NULL;
    int i;

    for (i = 1; i < pos && t != NULL; i++) {
        prev = t;
        t = t->next;
    }

    if (t == NULL) {
        printf("Position out of range!\n");
        return;
    }

    prev->next = t->next;
    free(t);

    printf("Node deleted at position %d\n", pos);
}

// DISPLAY
void display() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct node *t = head;
    printf("Linked List: ");

    while (t != NULL) {
        printf("%d -> ", t->data);
        t = t->next;
    }
    printf("NULL\n");
}

// MAIN PROGRAM
int main() {
    int ch, value, pos;

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete at Beginning\n");
        printf("5. Delete at End\n");
        printf("6. Delete at Position\n");
        printf("7. Display\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;

            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                printf("Enter position: ");
                scanf("%d", &pos);
                insertAtPosition(value, pos);
                break;

            case 4:
                deleteBeginning();
                break;

            case 5:
                deleteEnd();
                break;

            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteAtPosition(pos);
                break;

            case 7:
                display();
                break;

            case 8:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
