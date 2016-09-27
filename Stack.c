#include<stdio.h>
#include<stdlib.h>

struct Node {
	struct Node *next;
	int data;
};

struct stack {
	struct Node *top;
};

void initialize(struct stack *temp) {
	temp->top = NULL;
}

int isemptystack(struct stack *temp) {
	if(temp->top == NULL)
		return 1;
	else
		return 0;
}

void push(struct stack *temp, int data) {
	struct Node *n;
	
	n = (struct Node *) malloc(sizeof(struct Node));
	n->data = data;
	n->next = NULL;
	if(isemptystack(temp)){
		temp->top = n;
	} else {
		n->next = temp->top;
		temp->top = n;
		printf("Pushed Data is: %d\n", n->data);
	}
}

void pop(struct stack *temp) {
	struct Node *n;
	
	if(isemptystack(temp))
		printf("Stack is Empty.\n");
	else{
		n = temp->top;
		temp->top = n->next;
		printf("Poped Data is: %d\n", n->data);
	}
	free(n);
}

void display(struct stack *temp) {
	struct Node *n;
	
	if(isemptystack(temp))
		printf("Stack is Empty.\n");
	else {
		n = temp->top;
		while(n != NULL){
			printf("%d\t", n->data);
			n = n->next;
		}
	}
	printf("\n");
}

int main() {
	struct stack s;
	
	initialize(&s);
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);
	push(&s, 4);
	push(&s, 5);
	display(&s);
	pop(&s);
	display(&s);
	pop(&s);
	display(&s);
	pop(&s);
	display(&s);
	push(&s, 7);
	push(&s, 8);
	push(&s, 9);
	display(&s);
	pop(&s);
	display(&s);
	
	return 0;
}
