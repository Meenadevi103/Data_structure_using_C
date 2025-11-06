#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *prev;
    struct node *next;
} node;

node *head = NULL;

// Insert at end
void insert(int value) {
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = value;
    newnode->prev = newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newnode;
        newnode->prev = temp;
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
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Reverse (final working version)
void reverse() {
    node *current = head, *prev = NULL, *next = NULL;

    while (current != NULL) {
        next = current->next;   // store next node
        current->next = prev;   // reverse pointer
        current->prev = next;   // update prev pointer
        prev = current;         // move prev
        current = next;         // move forward
    }

    head = prev;   // new head
    printf("List reversed\n");
    display();
}

// Delete by value
void del(int value) {
    if (head == NULL) {
        printf("List Empty\n");
        return;
    }

    node *temp = head;

    while (temp != NULL && temp->data != value)
        temp = temp->next;

    if (temp == NULL) {
        printf("Value not found\n");
        return;
    }

    if (temp == head) {
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
    } else {
        temp->prev->next = temp->next;
        if (temp->next != NULL)
            temp->next->prev = temp->prev;
    }

    free(temp);
    printf("Deleted %d\n", value);
}

// Sum
void sum() {
    node *temp = head;
    int s = 0;
    while (temp != NULL) {
        s += temp->data;
        temp = temp->next;
    }
    printf("Sum = %d\n", s);
}

// Sort
void sort() {
    node *i, *j;
    int tmp;

    if (head == NULL)
        return;

    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                tmp = i->data;
                i->data = j->data;
                j->data = tmp;
            }
        }
    }
    printf("List sorted\n");
}

int main() {
    int ch, val;
    while (1) {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Search\n5.Reverse\n6.Sum\n7.Sort\n8.Exit\nEnter your choice : ");
        scanf("%d", &ch);

        switch (ch) {
        case 1: printf("Enter value: "); scanf("%d", &val); insert(val); break;
        case 2: printf("Enter value: "); scanf("%d", &val); del(val); break;
        case 3: display(); break;
        case 5: reverse(); break;
        case 6: sum(); break;
        case 7: sort(); break;
        case 8: exit(0);
        default: printf("Invalid choice\n");
        }
    }
}

