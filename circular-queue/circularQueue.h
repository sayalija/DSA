#include <stdbool.h>

typedef char String[256];
typedef struct{
        void* elements;
        int elementSize;
        int front;
        int rear;
        int maxSize;
}CQueue;

CQueue* create(int elementSize, int maxSize);
bool enqueue(CQueue* queue,void* element);
void* dequeue(CQueue* queue);
bool isFull(CQueue* queue);
bool isEmpty(CQueue* queue);
