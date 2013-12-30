#include "hashMap.h"
#include <stdlib.h>
#include "../linked-list/linkedList.h"
#include "../array-list/arrayList.h"

typedef struct {
	void *value;
	void *key;
} HashElement;

HashMap createHashMap(HashCodeGenerator getHashCode,Compare cmp,int initial_size){
	HashMap map;
	int i;
	ArrayList arrayList = createList(initial_size);
	map.getHashCode = getHashCode;
	map.cmp = cmp;
	map.initialCapacity = initial_size;
	map.buckets = calloc(1, sizeof(ArrayList));
	*(ArrayList*)map.buckets = arrayList;
	for (i = 0; i < initial_size; i++)
		insertElement(map.buckets, i, create());
	return map;
}

HashElement* getNewHashElement(void *key,void *dataToInsert){
	HashElement* element = calloc(1, sizeof(HashElement));
	element->key = key;
	element->value = dataToInsert;
	return element;
}

int hashing(HashMap* map, void* key){
	int bucket = map->getHashCode(key);
	return bucket % map->initialCapacity;
}

int put(HashMap *map,void *key,void *dataToInsert){
	int bucket;
	HashElement *element;
	List* list;
	if(NULL == map || NULL == key || NULL == dataToInsert)
		return 0;
	bucket = hashing(map,key);
	element = getNewHashElement(key, dataToInsert);
	list = ((ArrayList*)map->buckets)->base[bucket];
	insert(list, 0, element);
	return 1;
}

void* get(HashMap* map, void* key){
	int bucket;
	Iterator it;
	HashElement* element;
	List* list;
	if(NULL == map || NULL == key)
		return NULL;
	bucket = hashing(map, key);
	list = ((ArrayList*)map->buckets)->base[bucket];
	it = getIterator(list);
	while(it.hasNext(&it)){
		element = it.next(&it);
		if(0 == map->cmp(element,key))
			return element->value;
	}
	return NULL;
}

int removeHashElement(HashMap *map,void *key){
	List *list;
    HashElement *element;
    Iterator it;
    int index = 1;
    int hash;
    if(NULL == map || NULL == key)
    	return 0;
    hash = hashing(map,key);
    list = ((ArrayList*)map->buckets)->base[hash];
    it = getIterator(list);
    while(it.hasNext(&it)){
        element = it.next(&it);
        if(map->cmp(element->key,key)){
            remove(list,index);
            return 1;
        }
    }
    return 0;
}

Iterator keys(HashMap *map){
	Iterator arrayList;
	Iterator linkedList;
	Iterator result;
	HashElement *element;
	List *list = create();
	arrayList = getListIterator(map->buckets);
	while(arrayList.hasNext(&arrayList)){
		linkedList = getIterator(arrayList.next(&arrayList));
    	element = linkedList.next(&linkedList);
    	insert(list, 0, element->key);
	}
	result = getIterator(list);
	return result;
}

void disposeMap(HashMap* map){
	int i;
	for (i = 0; i < map->initialCapacity; i++)
		dispose(((ArrayList*)map->buckets)->base[i]);
	disposeList(map->buckets);
}