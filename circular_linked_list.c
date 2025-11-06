#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

// Insert at end
void insert(int value) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;

    if(head == NULL) {
        head = newNode;
        newNode->next = head; 
        return;
    }

    struct node *temp = head;
    while(temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
}

// Delete by value
void delete(int value) {
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *temp = head, *prev = NULL;

    // If first node is to be deleted
    if(head->data == value) {
        if(head->next == head) {  // only 1 node
            free(head);
            head = NULL;
            return;
        }
        struct node *last = head;
        while(last->next != head)
            last = last->next;

        last->next = head->next;
        head = head->next;
        free(temp);
        return;
    }

    // Other nodes
    do {
        prev = temp;
        temp = temp->next;
    } while(temp != head && temp->data != value);

    if(temp == head) {
        printf("Value not found\n");
    } else {
        prev->next = temp->next;
        free(temp);
    }
}

// Search
void search(int value) {
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *temp = head;
    int pos = 1;

    do {
        if(temp->data == value) {
            printf("%d found at position %d\n", value, pos);
            return;
        }
        temp = temp->next;
        pos++;
    } while(temp != head);

    printf("%d not found\n", value);
}

// Sum
void sum() {
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }
    int total = 0;
    struct node *temp = head;

    do {
        total += temp->data;
        temp = temp->next;
    } while(temp != head);

    printf("Sum = %d\n", total);
}

// Max
void max() {
    if(head == NULL) {
        printf("Empty list\n");
        return;
    }

    int maximum = head->data;
    struct node *temp = head->next;

    while(temp != head) {
        if(temp->data > maximum)
            maximum = temp->data;
        temp = temp->next;
    }

    printf("Maximum = %d\n", maximum);
}

// Sort ascending
void sort() {
    if(head == NULL)
        return;

    struct node *i = head, *j;
    int tempData;

    do {
        j = i->next;
        while(j != head) {
            if(i->data > j->data) {
                tempData = i->data;
                i->data = j->data;
                j->data = tempData;
            }
            j = j->next;
        }
        i = i->next;
    } while(i->next != head);
}

//reverse
void reverse(){
	struct node *current=head;
	struct node *prev=NULL,*next=NULL;
	do{
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
	}while(current!=head);
	head->next=prev;
	head=prev;
}
// Display
void display() {
    if(head == NULL) {
        printf("List empty\n");
        return;
    }

    struct node *temp = head;

    printf("List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while(temp != head);
    printf("HEAD\n");
}

// Menu
int main() {
    int choice, value;

    while(1) {
        printf("\n--- Circular Linked List Menu ---\n");
        printf("1. Insert\n2. Delete\n3. Search\n4. Display\n5. Reverse Display\n");
        printf("6. Sum\n7. Maximum\n8. Sort\n9. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                delete(value);
                break;
            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(value);
                break;
            case 4:
                display();
                break;
            case 5:
                reverse();
                break;
            case 6:
                sum();
                break;
            case 7:
                max();
                break;
            case 8:
                sort();
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

