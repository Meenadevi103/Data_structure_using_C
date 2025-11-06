#include<stdio.h>
#include<malloc.h>
typedef struct node{     // Define the structure for a stack node
	int data;
	struct node *next;
}node;
struct node *top = NULL;   // Pointer to the top of the stack
int isEmpty(){               // Check if the stack is empty
	if(top==NULL){
	
	return 1;
}
	else{
		return 0;
	}
}
// Function to push an element onto the stack
void push(int a){
	node *newnode;
	newnode = (node*)malloc(sizeof(node));  // create new node
	if(newnode == NULL){
		printf("Stack overflow");   // memory not allocated
	}
	newnode->data = a;      // store data
	newnode->next = top;    // link new node to previous top
	top = newnode;          // update top to new node
}

// Function to display stack elements
void display(){
	node *temp = top;
	if(isEmpty()){
       printf("Stack is empty\n");
       return;
   }
    printf("Stack elements: ");
	while(temp != NULL){
		printf("%d  ", temp->data); // print each element
		temp = temp->next;          // move to next node
	}
	printf("\n");
}

// Function to pop (delete) top element
int pop(){
	if(isEmpty()){
		printf("Stack Underflow");
		return 0;
	}

	node *temp = top;   // store current top
	top = top->next;   // move top to next node
	int val = temp->data; // store deleted value
	free(temp);          // free memory
	return val;          // return deleted value
}

// Function to see top element without removing it
int peek(){
	int val;
	if(isEmpty()){
		printf("Stack Underflow");
		return 0;
	}
	else{
		node *t=top;
		val=t->data;
		return val;
	}
}

int main(){
	int ch, a;

	while(1){
		printf("\n1. Push\n2. Display\n3. Pop\n4. Peek\n5. Exit\n");
		printf("Enter your choice:\n");
		scanf("%d", &ch);
		switch (ch){
			case 1:
				printf("Enter the element to push:\n");
				scanf("%d", &a);
				push(a);
				break;
			case 2:
				display();
				break;
			case 3:
				a = pop();
				printf("Deleted element is: %d\n", a);
				break;
			case 4:
				a = peek();
				printf("Top element is: %d\n", a);
				break;
			case 5:
				exit(0) ;
			default:
				printf("Invalid choice\n");
		}
	}
	return 0;
}

