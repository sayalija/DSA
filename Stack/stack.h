typedef struct{
	void *elements;
	int top;
	int maxSize;  
	int elementSize;
}Stack;
typedef char String[256];

Stack* create(int maxSize, int elementSize);
int push(Stack* s, void* element);
void* pop(Stack* s);
void* peek(Stack* s);
int isEmpty(Stack* s);
int isFull(Stack* s);