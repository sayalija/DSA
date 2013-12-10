#include "linkedList.h"
#include <string.h>
#include <stdlib.h>

List* create(){
	List* list = calloc(1, sizeof(List));
	list->head = NULL;
	list->tail = NULL;
	list->numberOfElements = 0;
	return list;
}

int insertFirst(List* list, Node* node, void* data){
	node->data = data;
	node->next = list->head;
	list->head = node;
	list->numberOfElements++;
	return 1;
}

int insertLast(List* list, Node* node, void* data){
	node->data = data;
	node->previous = list->tail;
	list->tail = node;
	list->numberOfElements++;
	return 1;
}

int insert(List* list, int index, void* data){
	Node* node;
	int validIndex = index >= 0 && index <= list->numberOfElements;
	if(!validIndex)
		return 0;
	node = calloc(1, sizeof(Node));
	if(index == 0)
		insertFirst(list,node, data);
	if(index == list->numberOfElements)
		insertLast(list, node, data);
	return 1;
}

int getLength(List* list){
	int length;
	length = list->numberOfElements;	
	return length;
}
