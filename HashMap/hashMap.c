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
		if(map->cmp(element->key,key)){
			return element->value;
		}
	}
	return NULL;
}

void rehash(HashMap *map){
    int i;
    HashElement *element;
    Iterator it = keys(map);
    ArrayList listOfBuckets,list;
    Iterator itList = getIterator(it.list);
    disposeMap(map);
    map->initialCapacity = map->initialCapacity * 2;
    list = createList(map->initialCapacity);
    map->buckets = calloc(1,sizeof(ArrayList));
    *(ArrayList*)map->buckets = list;
    for(i=0;i<map->initialCapacity;i++)
        insertElement(map->buckets, i,create());
    while(itList.hasNext(&itList)){
        element = itList.next(&itList);
        put(map,element->key,element->value);
    }
};

void rehashingIfNeeded(HashMap* hash){
    Iterator arrayList = getListIterator(hash->buckets);
    List* list;
    while(arrayList.hasNext(&arrayList)){
        list = (List*)arrayList.next(&arrayList);
        if(list->numberOfElements == 2){
            rehash(hash);
            return;            
        }
    }
}

HashElement* isHaveSameElement(HashMap *map,void *key){
    int bucket;
    List *list;
    HashElement *element;
    Iterator it;
    bucket = hashing(map,key);
    list = ((ArrayList*)map->buckets)->base[bucket];
    it = getIterator(list);
    while(it.hasNext(&it)){
        element = it.next(&it);
        if(map->cmp(element->key,key))
            return element;
    }
    return NULL;
};

int put(HashMap *map,void *key,void *dataToInsert){
	List *list;
    HashElement *existingElement,*element;
    int bucket;
    if(NULL == map || NULL == key || NULL == dataToInsert) 
    	return 0;
    existingElement = isHaveSameElement(map, key);
    if(existingElement){
        existingElement->value = dataToInsert;
        return 1;
    }
    element = getNewHashElement(key, dataToInsert);
    bucket = hashing(map,key);
    list = ((ArrayList*)map->buckets)->base[bucket];
    insert(list, 0, element);
    rehashingIfNeeded(map);
    return 1;
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

void disposeMap(HashMap* map){
	int i;
	for (i = 0; i < map->initialCapacity; i++)
		dispose(((ArrayList*)map->buckets)->base[i]);
	disposeList(map->buckets);
}