typedef struct Process{
	int priority;
	int eTime;
} Process;
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
int remove(List* list, int index);
int findIndex(List* list, void* data);
int getLength(List* list);
int schedule(void *data);

int getTime(Process* p);