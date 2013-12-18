#include "stack.h"
#include <stdlib.h>
#include <string.h>

Stack* create(int maxSize){
Stack* s = calloc(1,sizeof(Stack));
    s->elements = calloc(maxSize,sizeof(void*));
    s->top = 0;
    s->maxSize = maxSize;
    return s;
}

void dispose(Stack* s){
	free(s->elements);
	free(s);
}

int isFull(Stack* s){
	return s->maxSize == s->top+1;
}

int isEmpty(Stack* s){
	return 0 == s->top;
}

int push(Stack* s, void* element){
	if(isFull(s)){
        s->elements = realloc(s->elements, s->maxSize * sizeof(void*));
        s->maxSize += s->maxSize; 
    }
    *(s->elements+s->top++) = element;
    return 1;
}

void* pop(Stack* s){
    void *element;
    element = peek(s);

    if(isEmpty(s)) 
    	return NULL;
    s->top--;
    return element;
};

void* peek(Stack* s){
    void* top;
    if(isEmpty(s))
    	return NULL;
    top = *(s->elements+s->top-1);
    return top;
};
