#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
} node;

node *head = NULL;

// Insert at end
void insert(int value) {
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = value;

    if (head == NULL) {
        head = newnode;
        head->next = head;
        head->prev = head;
    } else {
        node *temp = head;

        while (temp->next != head)
            temp = temp->next;

        temp->next = newnode;
        newnode->prev = temp;
        newnode->next = head;
        head->prev = newnode;
    }
    printf("Inserted %d\n", value);
}

// Display
void display() {
    if (head == NULL) {
        printf("List Empty\n");
        return;
    }

    node *temp = head;
    printf("List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Delete by value
void delete(int value) {
    if (head == NULL) {
        printf("List Empty\n");
        return;
    }

    node *temp = head;

    // Case: Only one node
    if (head->data == value && head->next == head) {
        head = NULL;
        free(temp);
        printf("Deleted %d\n", value);
        return;
    }

    // search value
    while (temp->data != value && temp->next != head)
        temp = temp->next;

    if (temp->data != value) {
        printf("Value not found\n");
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    if (temp == head)
        head = head->next;

    free(temp);
    printf("Deleted %d\n", value);
}

// Reverse
void reverse() {
    if (head == NULL || head->next == head) {
        printf("List reversed\n");
        return;
    }

    node *temp = head, *prev = NULL, *next = NULL;

    do {
        next = temp->next;
        temp->next = prev;
        temp->prev = next;
        prev = temp;
        temp = next;
    } while (temp != head);

    head->next = prev;
    prev->prev = head;
    head = prev;

    printf("List reversed\n");
}

int main() {
    int ch, val;

    while (1) {
        printf("\n1.Insert\n2.Display\n3.Delete\n4.Reverse\n5.Exit\nEnter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: printf("Enter value: "); scanf("%d", &val); insert(val); break;
            case 2: display(); break;
            case 3: printf("Enter value: "); scanf("%d", &val); delete(val); break;
            case 4: reverse(); break;
            case 5: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}

