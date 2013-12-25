#include "../iterator.h"
typedef struct {
	void** base;
	int capacity;
	int length;
} ArrayList;
typedef void ForEach(void* data);
typedef int (*compare)(void* element1,void* element2);

ArrayList create(int capacity);
int insert(ArrayList *list, int index, void* data);
int add(ArrayList *list,void *data);

void* get(ArrayList *list, int index);

int search(ArrayList *list, void* data, compare cmp);

int remove(ArrayList * list, int index);
Iterator getIterator(ArrayList* list);
void dispose(ArrayList *list);
void iterate(ArrayList list, ForEach* forEach);