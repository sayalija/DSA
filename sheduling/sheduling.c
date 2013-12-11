#include "sheduling.h"
#include <stdlib.h>
List* create(){
	List* list = calloc(1, sizeof(List));
	list->head = NULL;
	list->numberOfElements = 0;
	return list;
}

int insertFirst(Node* nodeToAdd,List* list){
	nodeToAdd->next = list->head;
    list->head = nodeToAdd;
    return 1;
}

int insertNode(Node* node, Node* nodeToAdd, List* list){
	nodeToAdd->previous = node->previous;
	nodeToAdd->next = node;
	node->next = nodeToAdd;
    return 1;
}

int insert(List* list, int index, void* data){
	int i;
	Node* node = list->head;
	Node* nodeToAdd;
	 if((index <= 0 )|| (index >(list->numberOfElements+1)))  return 0;
	list->numberOfElements++;
	nodeToAdd = calloc(1, sizeof(Node));
	nodeToAdd->data = data;
	if(list->head == NULL){
		list->head = nodeToAdd;
		return 1;
	}
	for(i = 0; i < index-1; i++)
		node = node->next;
	if(index == 1)
		return insertFirst(nodeToAdd, list);
	return insertNode(node, nodeToAdd, list);
}

int getTime(Process* p){
	return p->eTime;
}