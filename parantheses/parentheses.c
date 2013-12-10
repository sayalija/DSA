#include <stdlib.h>
#include "parentheses.h"
#include <string.h>
Stack* create(int maxSize,int elementSize){
	Stack* s = (Stack*)calloc(1,sizeof(Stack));
	s->elements = calloc(1, maxSize*elementSize);
	s->maxSize = maxSize;
	s->elementSize = elementSize;
	s->top = -1;
	return s;
}

int isFull(Stack* s){
	return s->maxSize == s->top+1;
}

int isEmpty(Stack* s){
	return -1 == s->top;
}

int push(Stack* s, void* element){
	int address;
	if(isFull(s))
		return 0;
	s->top++;
	address = s->top*s->elementSize;
	memcpy(s->elements+address, element, s->elementSize);
	return 1;
}

void* pop(Stack* s){
	int address;
	void* popElement = calloc(1, s->elementSize);
	if(isEmpty(s))
		return 0;
	address = s->top*s->elementSize;
	memcpy(popElement, s->elements+address, s->elementSize);
	s->top--;
	return popElement;
}

void* peek(Stack *s){
	int address;
	void* topElement = calloc(1, s->elementSize);
	if(isEmpty(s))
		return 0;
	address = s->top*s->elementSize;
	memcpy(topElement, s->elements+address, s->elementSize);
	return topElement;
}