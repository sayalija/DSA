typedef int (*HashCodeGenerator)(void *key);
typedef int (*Compare)(void *element1,void *element2);
typedef struct {
	void* buckets;
	int initialCapacity;
	HashCodeGenerator getHashCode;
	Compare cmp;
} HashMap;

HashMap createHashMap(HashCodeGenerator getHashCode,Compare cmp,int initial_size);
int put(HashMap *map,void *key,void *dataToPut);
void* get(HashMap* map, void* key);
int removeHashElement(HashMap *map,void *key);