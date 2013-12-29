#include "hashMap.h"
#include <stdlib.h>
#include "../linked-list/linkedList.h"
#include "../array-list/arrayList.h"

typedef struct {
	void* value;
	int key;
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

int put(HashMap *map,void *key,void *dataToPut){
	return 1;
}

void* get(HashMap* map, void* key){
	int bucket;
	Iterator it;
	HashElement* element;
	List* list;
	bucket = map->getHashCode(key);
	list = ((ArrayList*)map->buckets)->base[bucket];
	it = getIterator(list);
	while(it.hasNext(&it)){
		element = it.next(&it);
		if(map->cmp(element,key))
			return element->value;
	}
	return NULL;
}