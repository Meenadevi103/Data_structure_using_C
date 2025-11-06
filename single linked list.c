#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
typedef struct node node;

node *head = NULL;

// Insert at Beginning
void insertBeg(int a) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = a;
    newNode->next = head;
    head = newNode;
    printf("%d inserted at beginning.\n", a);
}

// Insert at End
void insertEnd(int a) {
    node *t;
    if (head == NULL) {
        head = (node *)malloc(sizeof(node));
        head->data = a;
        head->next = NULL;
    } else {
        t = head;
        while (t->next != NULL) {
            t = t->next;
        }
        t->next = (node *)malloc(sizeof(node));
        t->next->data = a;
        t->next->next = NULL;
    }
    printf("%d inserted at end.\n", a);
}

// Insert after specified element
void insertSpec(int a, int key) {
    node *t = head;

    while (t != NULL && t->data != key) {
        t = t->next;
    }

    if (t == NULL) {
        printf("Element %d not found.\n", key);
    } else {
        node *newNode = (node *)malloc(sizeof(node));
        newNode->data = a;
        newNode->next = t->next;
        t->next = newNode;
        printf("%d inserted after %d.\n", a, key);
    }
}

// Delete from Beginning
void deleteBeg() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    node *temp = head;
    head = head->next;
    printf("Deleted %d from beginning.\n", temp->data);
    free(temp);
}

// Delete from End
void deleteEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    node *t = head, *prev = NULL;

    if (head->next == NULL) {
        printf("Deleted %d from end.\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    while (t->next != NULL) {
        prev = t;
        t = t->next;
    }

    printf("Deleted %d from end.\n", t->data);
    prev->next = NULL;
    free(t);
}

// Delete specific element
void deleteSpec(int key) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    node *t = head, *prev = NULL;

    if (head->data == key) {
        head = head->next;
        printf("Deleted %d from list.\n", key);
        free(t);
        return;
    }

    while (t != NULL && t->data != key) {
        prev = t;
        t = t->next;
    }

    if (t == NULL) {
        printf("Element %d not found.\n", key);
    } else {
        prev->next = t->next;
        printf("Deleted %d from list.\n", key);
        free(t);
    }
}

// Reverse list
void rev() {
    node *prev = NULL, *current = head, *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
    printf("List reversed successfully.\n");
}

// Sort list
void sortList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    node *i, *j;
    int temp;
    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    printf("List sorted.\n");
}

// Find and replace
void findAndReplace(int oldVal, int newVal) {
    node *t = head;
    int found = 0;
    while (t != NULL) {
        if (t->data == oldVal) {
            t->data = newVal;
            found = 1;
        }
        t = t->next;
    }
    if (found)
        printf("%d replaced with %d.\n", oldVal, newVal);
    else
        printf("%d not found in list.\n", oldVal);
}

// Count nodes
void countNodes() {
    int count = 0;
    node *t = head;
    while (t != NULL) {
        count++;
        t = t->next;
    }
    printf("Total nodes: %d\n", count);
}

// Sum of nodes
void sumList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    node *t = head;
    int sum = 0;
    while (t != NULL) {
        sum += t->data;
        t = t->next;
    }

    printf("Sum of all nodes = %d\n", sum);
}

// Mean of nodes
void meanList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    node *t = head;
    int sum = 0, count = 0;

    while (t != NULL) {
        sum += t->data;
        count++;
        t = t->next;
    }

    float mean = (float)sum / count;
    printf("Mean of nodes = %.2f\n", mean);
}

// Display
void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    node *t = head;
    printf("Linked List: ");
    while (t != NULL) {
        printf("%d -> ", t->data);
        t = t->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, val, key, oldVal, newVal;

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert After Specified Element\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete Specified Element\n");
        printf("7. Display\n");
        printf("8. Reverse Linked List\n");
        printf("9. Sort Linked List\n");
        printf("10. Sum of Nodes\n");
        printf("11. Mean of Nodes\n");
        printf("12. Find and Replace\n");
        printf("13. Count Nodes\n");
        printf("14. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insertBeg(val);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &val);
                insertEnd(val);
                break;

            case 3:
                printf("Enter value: ");
                scanf("%d", &val);
                printf("Insert after which element? ");
                scanf("%d", &key);
                insertSpec(val, key);
                break;

            case 4:
                deleteBeg();
                break;

            case 5:
                deleteEnd();
                break;

            case 6:
                printf("Enter value to delete: ");
                scanf("%d", &key);
                deleteSpec(key);
                break;

            case 7:
                display();
                break;

            case 8:
                rev();
                break;

            case 9:
                sortList();
                break;

            case 10:
                sumList();
                break;

            case 11:
                meanList();
                break;

            case 12:
                printf("Enter value to find: ");
                scanf("%d", &oldVal);
                printf("Enter new value: ");
                scanf("%d", &newVal);
                findAndReplace(oldVal, newVal);
                break;

            case 13:
                countNodes();
                break;

            case 14:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

