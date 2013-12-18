#include "sheduling.h"
#include <stdlib.h>
#include <string.h>
scheduler* create(){
        scheduler *q = calloc(sizeof(scheduler),1);
        return q;
}
int insertAtStart(scheduler *q, Process *process){
        if(q->head == NULL)
                        process->next = NULL;
        else process->next = q->head;
        q->head = process;
        q->maxSize++;
        return q->maxSize;        
}
int insertProcessHere(scheduler *q,Process *previous,Process *process ,Process *next){
        previous->next = process;
        process->next = next;
        return ++q->maxSize;
}
int insertProcess(scheduler *q, Process *process){
        Process *previous,*next,*temp;int i = 0;
        temp = q->head;
        if(q->maxSize == 0)                
                return insertAtStart(q, process);
        if(process->pPriority < temp->pPriority)
                return insertAtStart(q, process);
        for(;temp->next != NULL;temp = temp->next){
                previous = temp;
                next = temp->next;
                if(process->pPriority < next->pPriority)
                        return insertProcessHere(q ,previous, process ,next);
        };
        temp->next = process;
        process->next = NULL;
        return ++q->maxSize;
}
int removeProcessHere(scheduler *q,Process *previous ,Process *next){
        previous->next = next->next;
        return --q->maxSize;
}

int removeProcess(scheduler *q){
        Process *temp,*previous,*next;int i = 0;
        temp = q->head;

        if(q->maxSize == 1){
                if(temp->pTime == 0)
                        q->head = NULL;
                return --q->maxSize;
        }
        if(temp->pTime == 0)
                q->head = temp->next;
        for(;temp->next != NULL;temp = temp->next){
                previous = temp;
                next = temp->next;
                if(next->pTime == 0)
                        return removeProcessHere(q ,previous ,next);
        }
        if(NULL == temp->next){
                previous->next = NULL;
                return --q->maxSize;
        };
        return 0;
}
void dispose(scheduler *q){
        free(q);
}