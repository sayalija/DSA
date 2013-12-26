#include "iterator.h"
typedef struct Node{
	void* data;
	struct Node* previous;
	struct Node* next;
} Node;
typedef struct {
	Node* head;
	int numberOfElements;
} List;

List* create();
int insert(List* list, int index, void* data);
void* remove(List* list, int index);
int findIndex(List* list, void* data);
int getLength(List* list);
void* getNodeData(List list, int index);
Iterator getIterator(List *list);
void dispose(List* list);