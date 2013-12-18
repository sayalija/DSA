#include "stack.h"
#include <stdlib.h>
#include <string.h>
Stack* createStack(){
    Stack* stack = calloc(1,sizeof(Stack));
    stack->list = create();
    return stack;
};

int push(Stack* stack,void* element){
    return insert(stack->list, 0, element);
};

void* peek(Stack* stack){
	void* data = calloc(1, sizeof(void*));
    if(stack->list->head == NULL) 
    	return NULL;
    memcpy(data,stack->list->head->data,sizeof(Node));
    return data;
};

void* pop(Stack *stack){
	Node* node = calloc(1, sizeof(Node));
	if(stack->list->head == NULL) 
		return NULL;
	node = remove(stack->list,0);
	return node->data;
}

void disposeStack(Stack* stack){
	free(stack->list);
	free(stack);
}