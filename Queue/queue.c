#include "queue.h"
#include <stdlib.h>
#include <string.h>
Queue* create(int maxSize,int elementSize){
	Queue* q = (Queue*)calloc(1,sizeof(Queue));
	q->elements = calloc(1, maxSize*elementSize);
	q->maxSize = maxSize;
	q->elementSize = elementSize;
	q->rear = -1;
	return q;
}

int isFull(Queue* q){
	return q->maxSize == q->rear+1;
}

int isEmpty(Queue* q){
	return -1 == q->rear;
}

int enqueue(Queue* q, void* element){
	int address;
	if(isFull(q))
		return 0;
	q->rear++;
	address = q->rear*q->elementSize;
	memcpy(q->elements+address, element, q->elementSize);
	return 1;
}
void* dequeue(Queue* q){
	void* deletedElement = malloc(q->elementSize);
	if(isEmpty(q))
		return 0;
	memcpy(deletedElement, q->elements, q->elementSize);
	memmove(q->elements, q->elements+q->elementSize, q->elementSize*(q->rear+1));
	q->rear++;
	return deletedElement;
}
