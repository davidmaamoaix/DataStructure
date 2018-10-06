#include<iostream>
#include<mm_malloc.h>
using namespace std;

typedef struct SNode *Ptr;
typedef Ptr Stack;

struct SNode{
    int data;
    Ptr next;
};

Stack newStack(){
    Stack s=(Stack)malloc(sizeof(struct SNode));
    s->next=NULL;
    return s;
}

bool isEmpty(Stack s){
    return s->next==NULL;
}

Stack getLast(Stack s){
    Stack tmp=s;
    while(tmp->next!=NULL){
        tmp=tmp->next;
    }
    return tmp;
}

Stack getLast(Stack s,bool second){
    Stack tmp=s;
    while(tmp->next->next!=NULL){
        tmp=tmp->next;
    }
    return tmp;
}

void push(Stack s,int data){
    Stack tmp=(Stack)malloc(sizeof(struct SNode));
    tmp->data=data;
    tmp->next=NULL;
    getLast(s)->next=tmp;
}

int pop(Stack s){
    if(isEmpty(s)) return NULL;
    Stack tmp=getLast(s,true);
    int last=tmp->next->data;
    free(tmp->next);tmp->next=NULL;
    return last;
}

void print(Stack s){
    Stack tmp=s->next;
    cout<<'[';
    do{
        cout<<tmp->data<<',';
        tmp=tmp->next;
    }while(tmp!=NULL);
    cout<<']'<<endl;
}
