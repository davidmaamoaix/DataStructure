#include<iostream>
#include<mm_malloc.h>
using namespace std;

typedef struct QNode *Ptr;
typedef struct QNode *Queue;
struct QNode{
    int data;
    Ptr next;
};

Queue newQueue(){
    Queue q=(Queue)malloc(sizeof(struct QNode));
    q->next=NULL;
    return q;
}

bool isEmpty(Queue q){
    return q->next==NULL;
}

Queue getLast(Queue q){
    Queue tmp=q;
    while(tmp->next!=NULL) tmp=tmp->next;
    return tmp;
}

void add(Queue q,int value){
    Queue tmp=newQueue();
    tmp->data=value;
    getLast(q)->next=tmp;
}

int del(Queue &q){
    if(isEmpty(q)) return NULL;
    int num=q->next->data;
    Queue tmp=q->next->next;
    free(q->next);
    q->next=tmp;
    return num;
}

void print(Queue q){
    Queue tmp=q->next;
    cout<<'[';
    while(tmp!=NULL){
        cout<<tmp->data<<',';
        tmp=tmp->next;
    }
    cout<<']'<<endl;
}
