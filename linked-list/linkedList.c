#include "linkedList.h"
#include <string.h>
#include <stdlib.h>

List* create(){
    List* list = calloc(1, sizeof(List));
    list->head = NULL;
    list->numberOfElements = 0;
    return list;
}

int insertInBetween(List *list,Node *nodeToInsert,Node *node,void *data){
    nodeToInsert->next = node->next;
    node->next = nodeToInsert;
    nodeToInsert->previous = node;
    list->numberOfElements++;
    return 1;
}
int insertAtFirst(List *list, Node *nodeToInsert,void *data){
    nodeToInsert->next = list->head;
    list->head = nodeToInsert;
    list->numberOfElements++;
    return 1;
};

int insert(List *list, int index, void *data){
    Node *node = list->head,*nodeToInsert;
    int i;
    nodeToInsert = calloc(1, sizeof(node));
    if(index < 0 || index > list->numberOfElements)
        return 0;
    nodeToInsert->data = data; 
    if(index == 0)
        return insertAtFirst(list, nodeToInsert,data);
    for(i = 0; i<index-1; i++)
        node = node->next;
    return insertInBetween(list, nodeToInsert, node, data);
    return 1;
};

int removeFromFirst(List *list){
    list->head = list->head->next;
    list->numberOfElements--;
    return 1;
}

void* remove(List* list, int index){
    int i;
    Node* nodeToDelete;
    Node* node;
    nodeToDelete = list->head;
    if(index < 0 || (!nodeToDelete)) return NULL;
    for(i=1; i < index; i++)
        nodeToDelete = nodeToDelete->next;
    if(NULL == nodeToDelete->previous){
        list->head = nodeToDelete->next;
        list->numberOfElements--;
        return nodeToDelete;
    }
    node = nodeToDelete->previous;
    node->next = nodeToDelete->next;
    list->numberOfElements--;
    if(node->next!=NULL)
        node->next->previous = node;
    return nodeToDelete;
}


void* getNodeData(List list, int index){
    int i = 0;
    Node* head = list.head;
    if(index<0 || index >= list.numberOfElements)
        return NULL;
    while(i < index){
        head = head->next;
        i++;
    }
    return head->data;
}

int hasNext(Iterator *it){
    List list;
    if(NULL == it->list) return 0;
    list = *(List*)it->list;
    if(it->position == list.numberOfElements) return 0;
    return 1;
}

void* next(Iterator* it){
    int i;
    Node* head;
    if(!hasNext(it)) return NULL;
    head = ((List*)(it->list))->head;
    for(i = 0; i<it->position; i++){
        head = head->next;
    };
    it->position++;
    return head->data;
}

Iterator getIterator(List *list){
    Iterator listIterator;
    listIterator.position = 0;
    listIterator.list = list;
    listIterator.hasNext = &hasNext;
    listIterator.next = &next;
    return listIterator;
}

int getLength(List* list){
    return list->numberOfElements;  
}

void dispose(List* list){
    free(list->head);
    free(list);
}

