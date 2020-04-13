#ifndef dlist_h
#define dlist_h

#include <stdio.h>
#include <stdbool.h>


//-------------------------------------------------
typedef struct dnode dnode;
struct dnode {
  int data;
  dnode* prev;
  dnode* next;
};

typedef struct dlist dlist;
struct dlist {
  dnode* head;
  dnode* tail;
  size_t size;
};

//-------------------------------------------------
dnode* dnode_create(int data, dnode* prev, dnode* next){
    dnode* p = (dnode*)malloc(sizeof(dnode));
    p->data = data;
    p->prev = prev;
    p->next = next;
    
    return p;
}
dlist* dlist_create(void){
    dlist* p = (dlist*)malloc(sizeof(dlist));
    p->head = NULL;
    p->tail = NULL;
    p->size = 0;
    
    return p;
}

bool dlist_empty(dlist* list){
    return list->size == 0;
}

size_t dlist_size(dlist* list){
    return list->size;
}

void dlist_popfront(dlist* list){
    dnode* p = list->head;
    list->head = list->head->next;
    free(p);
    --list->size;
}

void dlist_popback(dlist* list){
    dnode* p = list->head;
    dnode* prev = p;
    while(p->next != NULL){
        prev = p;
        p = p->next;
    }
    prev->next = NULL;
    free(p);
    list->tail = prev;
    --list->size;
}

void dlist_pushfront(dlist* list, int data){
    dnode* p = dnode_create(data, NULL, list->head);
    list->head = p;
    if(list->size == 0) {list->tail= p;}
    ++list->size;
}

void dlist_pushback(dlist* list, int data){
        if(list->size == 0){dlist_pushfront(list, data); return;}
        dnode* p = dnode_create(data,list->tail,NULL);
        list->tail->next = p;
        list->tail = p;
        ++list->size;
    }

void dlist_clear(dlist* list){
    while(!dlist_empty(list)){
        dlist_popback(list);
    }
}

void dlist_print(dlist* list, const char* msg){
    printf("%s\n", msg);
    if(!dlist_empty(list)){printf("empty list\n");}
    
    dnode* p = list->head;
    while(p!=NULL){
        printf("%d --> %p\n",p->data,p->next);
        p = p->next;
    }
}

int dlist_front(dlist* list){
    return list->head->data;
}

int dlist_back(dlist* list){
    return list->tail->data;
}


void dlist_test(void);


#endif /* dlist_h */
