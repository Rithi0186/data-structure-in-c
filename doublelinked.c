#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *previous;
    int data;
    struct node *next;
};

struct node *head = NULL;

// CREATE NODE
struct node* createNode(int value)
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->previous = NULL;
    newNode->next = NULL;
    return newNode;
}

// INSERT AT BEGINNING
void insertAtBeginning(int value)
{
    struct node *newNode = createNode(value);

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head->previous = newNode;
        head = newNode;
    }
    printf("%d inserted at beginning\n", value);
}

// INSERT AT END
void insertAtEnd(int value)
{
    struct node *newNode = createNode(value);

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct node *t = head;
        while (t->next != NULL)
            t = t->next;

        t->next = newNode;
        newNode->previous = t;
    }
    printf("%d inserted at end\n", value);
}

// INSERT AT POSITION
void insertAtPosition(int value, int pos)
{
    struct node *newNode = createNode(value);
    struct node *t = head;
    int i;

    if (pos == 1)
    {
        insertAtBeginning(value);
        return;
    }

    for (i = 1; i < pos - 1; i++)
    {
        if (t == NULL)
        {
            printf("Position out of range!\n");
            return;
        }
        t = t->next;
    }

    if (t->next == NULL)
    {
        insertAtEnd(value);
        return;
    }

    newNode->next = t->next;
    newNode->previous = t;
    t->next->previous = newNode;
    t->next = newNode;

    printf("%d inserted at position %d\n", value, pos);
}

// DELETE AT BEGINNING
void deletion_beginning()
{
    struct node *ptr;

    if (head == NULL)
        printf("UNDERFLOW\n");
    else if (head->next == NULL)
    {
        ptr = head;
        head = NULL;
        free(ptr);
        printf("Node deleted from beginning\n");
    }
    else
    {
        ptr = head;
        head = head->next;
        head->previous = NULL;
        free(ptr);
        printf("Node deleted from beginning\n");
    }
}

// DELETE AT END
void deleteEnd()
{
    if (head == NULL)
        printf("List is Empty! Deletion not possible!\n");
    else
    {
        struct node *temp = head;

        if (temp->next == NULL)
        {
            head = NULL;
            free(temp);
        }
        else
        {
            while (temp->next != NULL)
                temp = temp->next;

            temp->previous->next = NULL;
            free(temp);
        }
        printf("Node deleted from end\n");
    }
}

// DELETE AT POSITION
void deleteAtPosition(int pos)
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    struct node *t = head;
    int i;

    if (pos == 1)
    {
        deletion_beginning();
        return;
    }

    for (i = 1; i < pos && t != NULL; i++)
        t = t->next;

    if (t == NULL)
    {
        printf("Position out of range!\n");
        return;
    }

    if (t->next == NULL)
    {
        deleteEnd();
        return;
    }

    t->previous->next = t->next;
    t->next->previous = t->previous;
    free(t);

    printf("Node deleted at position %d\n", pos);
}

// DISPLAY
void display()
{
    if (head == NULL)
        printf("List is Empty!\n");
    else
    {
        struct node *temp = head;
        printf("\nList elements:\nNULL <--> ");
        while (temp != NULL)
        {
            printf("%d <--> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// MAIN
int main()
{
    int ch, value, pos;

    while (1)
    {
        printf("\n--- MENU ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert At Position\n");
        printf("4. Delete at Beginning\n");
        printf("5. Delete at End\n");
        printf("6. Delete at Position\n");
        printf("7. Display\n");
        printf("8. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
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
                deletion_beginning();
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
