typedef struct{
	void *elements;
	int rear;
	int maxSize;  
	int elementSize;
} Queue ;
typedef char String[256];

Queue* create(int maxSize,int elementSize);
int enqueue(Queue* q, void* element);
void* dequeue(Queue* q);
int isEmpty(Queue* q);
int isFull(Queue* q);