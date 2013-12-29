#include "../iterator.h"
typedef struct {
	void** base;
	int capacity;
	int length;
} ArrayList;
typedef void ForEach(void* data);
typedef int (*compare)(void* element1,void* element2);

ArrayList createList(int capacity);
int insertElement(ArrayList *list, int index, void* data);
int add(ArrayList *list,void *data);

void* getElement(ArrayList *list, int index);

int search(ArrayList *list, void* data, compare cmp);

int removeElement(ArrayList * list, int index);
Iterator getListIterator(ArrayList* list);
void disposeList(ArrayList *list);
void iterate(ArrayList list, ForEach* forEach);