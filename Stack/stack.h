typedef struct{
	void **elements;
	int top;
	int maxSize;
}Stack;

Stack* create(int maxSize);
void dispose(Stack* s);

int push(Stack* s, void* element);
void* pop(Stack* s);

void* peek(Stack* s);

int isEmpty(Stack* s);