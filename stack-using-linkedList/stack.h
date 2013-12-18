#include "../Linkedlist/linkedList.h"
typedef struct {
        List* list;
} Stack;

Stack* createStack();
int push(Stack* stack,void* element);
void* pop(Stack* stack);
void* peek(Stack* stack);
void disposeStack(Stack* stack);