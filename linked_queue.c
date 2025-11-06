#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *front = NULL;
Node *rear = NULL;

// Function to check if queue is empty
int isEmpty() {
    return front == NULL;
}

// Function to enqueue (insert element)
void enqueue(int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Queue Overflow (Memory not available)\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {  // Queue is empty
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("%d enqueued to queue.\n", value);
}

// Function to dequeue (remove element)
void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow (Queue is empty)\n");
        return;
    }
    Node *temp = front;
    printf("%d dequeued from queue.\n", temp->data);
    front = front->next;

    if (front == NULL) // If queue becomes empty
        rear = NULL;

    free(temp);
}

// Function to display the queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    Node *temp = front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n=== Queue Operations Using Linked List ===\n");
        printf("1. Enqueue (Insert)\n");
        printf("2. Dequeue (Delete)\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

