#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 20
typedef struct {
	int *base;
	int front;
	int rear;
}Queue;

void init(Queue *q){
	if(!(q->base = (int*)malloc(MAX_SIZE*sizeof(int)))){
		exit(1);
	}
	q->front = q->rear = 0;
}

int QueueLen(Queue *q){
	return (q->front - q->rear + MAX_SIZE)%MAX_SIZE;
}

void enQueue(Queue *q, int data){
	if(q->front == (q->rear+1)%MAX_SIZE){
		return;
	}
	q->base[q->rear] = data;
	q->rear = (q->rear+1)%MAX_SIZE;
}

int deQueue(Queue *q){
	if(q->rear == q->front){
		return 0;
	}
	int tmp = q->base[q->front];
	q->front = (q->front + 1)%MAX_SIZE;
	return tmp;
}

int main(){
	Queue queue, *q = &queue;
	init(q);
	enQueue(q, 1);
	enQueue(q, 2);
	enQueue(q, 3);
	enQueue(q, 4);
	printf("%d", deQueue(q));
	printf("%d", deQueue(q));
	printf("%d", deQueue(q));
	printf("%d", deQueue(q));
	return 0;
}