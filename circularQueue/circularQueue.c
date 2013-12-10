#include "circularQueue.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

CQueue* create(int elementSize, int maxSize){
        CQueue* queue = calloc(1,sizeof(CQueue));
        queue->front=-1;
        queue->rear=-1;
        queue->elements= calloc(maxSize,elementSize);
        queue->maxSize=maxSize;
        queue->elementSize=elementSize;
        return queue;
}
bool enqueue(CQueue* queue,void* element)
{
        if(isFull(queue)) return false;
        queue->rear++;
        memcpy((queue->elements+(queue->elementSize*queue->rear)) , element,queue->elementSize);
        return true;
}
void* dequeue(CQueue* queue){
        void* element = malloc(queue->elementSize);
        if(isEmpty(queue)) return false;
        queue->front++;
        memmove(element, queue->elements+(queue->elementSize*queue->front), queue->elementSize);
        return element;
}
bool isFull(CQueue* queue){ 
        if(queue->front == -1 && queue->rear == queue->maxSize-1) return true;
        return (queue->front == queue->rear+1);
}
bool isEmpty(CQueue* queue){
        if(queue->front ==-1 && queue->rear == -1) return true;
        return (queue->front == queue->rear+1);
}