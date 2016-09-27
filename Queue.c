#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node *next;
};

struct Queue {
	struct Node *front, *rear;
};

void initialize(struct Queue *temp) {
	temp->front = NULL;
	temp->rear = NULL;
}

int isemptyqueue(struct Queue *temp) {
	if(temp->front == NULL && temp->rear == NULL)
		return 1;
	else
		return 0;
}

void enqueue(struct Queue *temp, int data) {
	struct Node *n;
	n = (struct Node *) malloc(sizeof(struct Node));
	n->data = data;
	n->next = NULL;
	
	if(isemptyqueue(temp)) {
		temp->front = n;
		temp->rear = n;
	} else {
		(temp->rear)->next = n;
		temp->rear = n;
		printf("Enqueued: %d\n", n->data);
	}
}

void dequeue(struct Queue *temp) {
	struct Node *n;
	
	if(isemptyqueue(temp))
		printf("Queue is Empty.\n");
	else {
		n = temp->front;
		printf("Dequeued: %d\n", n->data);
		temp->front = n->next;
	}
	free(n);
}

void display(struct Queue *temp) {
	struct Node *n;
	
	if(isemptyqueue(temp)){
		printf("Queue is Empty.\n");
	} else {
		n = temp->front;
		while(n != NULL) {
			printf("%d\t", n->data);
			n = n->next;
		}
		printf("\n");
	}
}

int main() {
	struct Queue q;
	
	initialize(&q);
	enqueue(&q, 23);
	enqueue(&q, 20);
	enqueue(&q, 13);
	enqueue(&q, 52);
	enqueue(&q, 27);
	enqueue(&q, 10);
	display(&q);
	dequeue(&q);
	display(&q);
	dequeue(&q);
	display(&q);
	dequeue(&q);
	display(&q);
	enqueue(&q, 87);
	display(&q);
	enqueue(&q, 30);
	display(&q);
	
	return 0;
}
