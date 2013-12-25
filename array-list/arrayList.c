#include "arrayList.h"
#include <string.h>
#include <stdlib.h>
ArrayList create(int capacity) {
	ArrayList list;
	list.base = (void*)malloc(sizeof(void*) * capacity);
	list.capacity = capacity;
	list.length = 0;
	return list;
}

void shiftElementsIfNeeded(ArrayList *list, int index) {
	int i;
	if (index < list->length) {
		for (i = list->length - 1; i >= index; i--) {
			list->base[i+1] = list->base[i];
		}
	}	
}

int isFull(ArrayList *list) {
	return list->length == list->capacity;
}

void increaseCapacity(ArrayList *list) {
	int targetCapacity;
	if (isFull(list)) {
		targetCapacity = list->capacity * 2;
		list->base = realloc(list->base, targetCapacity * sizeof(void*));
		list->capacity = targetCapacity;
	}	
}

int insert(ArrayList *list, int index, void* data) {
	if (list == NULL) return 0;
	if (index < 0 || index > list->length) return 0;
	increaseCapacity(list);
	shiftElementsIfNeeded(list, index);

	list->base[index] = data;
	list->length++;

	return 1;
}

int add(ArrayList *list,void *data){
		insert(list, list->length, data);
	return 1;
}

void* get(ArrayList *list, int index) {
	if (index < 0 || index >= list->length) return NULL;

	return list->base[index];
}

int search(ArrayList *list, void* data, compare cmp){
	int i;
	for(i = 0 ; i < list->length; i++){
		if(1 == cmp(list->base[i],data))
			return 1;
	}
	return 0;
}

int remove(ArrayList * list, int index){
  	int i;
  	void* element;
    if(index < 0 || index >= list->length) 
    	return 0;
    if (index < list->length-1) {
	    for (i = index; i < list->length; i++) {
	        list->base[i] = list->base[i+1];
	    }
	}
    list->length--;
	return 1; 
}

int hasNext(Iterator* it){
    ArrayList *list = it->list;
    if(list->length <= it->position) return 0;
    return 1;
};

void* getNextData(Iterator* it){
    ArrayList* list = it->list;
    if(!hasNext(it)) return NULL;
    return list->base[it->position++];
}

Iterator getIterator(ArrayList* list){
    Iterator it;
    it.list = list;
    it.position = 0;
    it.hasNext = &hasNext;
    it.next = &getNextData;
    return it;
}

void iterate(ArrayList list, ForEach* forEach){
    int result,index;
    for(index = 0;index < list.length ;index++){
            forEach(list.base[index]);
    }
}

void dispose(ArrayList *list) {
	free(list->base);
}