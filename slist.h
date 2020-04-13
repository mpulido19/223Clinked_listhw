#ifndef slist_h
#define slist_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct snode snode;
struct snode {
  int data;
  snode* next;
};

typedef struct slist slist;
struct slist {
  snode* head;
  snode* tail;
  size_t size;
};

snode* snode_create(int data, snode* next){
    snode* p = (snode*)malloc(sizeof(snode));
    p->data = data;
    p->next = next;
    return p;
}

slist* slist_create(void){
    slist* p = (slist*)malloc(sizeof(slist));
    p->head = NULL;
    p->tail = NULL;
    p->size = 0;
    
    return p;
}

bool slist_empty(slist* list){
    return list->size == 0;
}
size_t slist_size(slist* list){
    return list->size;
}

void slist_popfront(slist* list){
    snode* p = list->head;
    list->head = list->head->next;
    free(p);
    --list->size;
}

void slist_popback(slist* list){
    snode* p = list->head;
    snode* prev = p;
    while(p->next != NULL){
        prev = p;
        p = p->next;
    }
    prev->next=NULL;
    free(p);
    list->tail = prev;
    --list->size;
}

void slist_pushfront(slist* list, int data){
    snode*p = snode_create(data, list->head);
    list->head = p;
    if(list->size == 0){list->tail = p;}
    ++list->size;
}

void slist_pushback(slist* list, int data){
    if(list->size == 0){slist_pushfront(list, data); return;}
    
    snode*p = snode_create(data,NULL);
    list->tail->next = p;
    list->tail = p;
    ++list->size;
}

void slist_clear(slist* list){
    while(!slist_empty(list)){
        slist_popfront(list);
    }
}

void slist_print(slist* list, const char* msg){
    printf("%s\n", msg);
    
    snode* p = list->head;
    while(p!=NULL){
        printf("%d --> %p\n", p->data, p->next);
        p = p->next;
    }
}

int slist_front(slist* list){
    return list->head->data;
}

int slist_back(slist* list){
    return list->tail->data;
}

void slist_test(void);


#endif /* slist_h */
