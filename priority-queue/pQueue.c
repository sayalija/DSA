#include "pQueue.h"
#include "../linked-list/linkedList.h"
#include "customType.h"
#include <stdlib.h>
void* createQueue(){
	List* pQueue = create();
	return pQueue;
}

QItem* createNode(int priority, void* data){
	QItem* element = calloc(1,sizeof(QItem));
	element->priority = priority;
	element->data = data;
	return element;
}
int enqueue(void* list, void* data, int priority){
	List* queue = list;
	QItem* element = createNode(priority,data);
	int index = 1;
	Node* head = queue->head;
	QItem* head_data;
	if(NULL == queue->head)
        return insert(queue, 0, element);
	head_data = head->data;
	if(head_data->priority > element->priority)
        return insert(queue, 0, element);
	while(head->next != NULL){
        head = head->next;
        head_data = head->data;
        if(head_data->priority > element->priority)
            return insert(queue, index,element);
        index++;
	}
	return insert(queue, index, element);
};

void* dequeue(void* list){
	List* queue = list;
	QItem* result = (QItem*)remove(queue, 0);
	return result->data;
};
