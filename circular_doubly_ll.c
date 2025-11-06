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

        // Move to last node
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

//reverse
void reverse() {
    if (head == NULL || head->next == head) {
        printf("List reversed\n");
        return;
    }

    struct node *current = head;
    struct node *prev = NULL, *next = NULL;

    do {
        next = current->next;       // store next
        current->next = prev;       // reverse next pointer
        current->prev = next;       // also fix prev pointer (important in DLL)
        prev = current;             // move prev
        current = next;             // move current
    } while (current != head);

    // Final adjustments for circularity
    head->next = prev;
    prev->prev = head;
    
    head = prev; // new head
    printf("List reversed\n");
}

int main() {
    int choice, val;

    while (1) {
        printf("\n1.Insert\n2.Display\n3.Reverse\n4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insert(val);
                break;

            case 2:
                display();
                break;

            case 3:
                reverse();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}

