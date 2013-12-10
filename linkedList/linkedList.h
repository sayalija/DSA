typedef struct Node{
	void* data;
	struct Node* previous;
	struct Node* next;
} Node;
typedef struct {
	Node* head;
	Node* tail;
	int numberOfElements;
} List;

List* create();
int insert(List* list, int index, void* data);
int remove(List* list, int index);
int findIndex(List* list, void* data);
int getLength(List* list);