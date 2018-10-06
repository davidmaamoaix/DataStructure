#include<mm_malloc.h>

struct SNode{
    int data[65536];
    int top;
    int max;
};

typedef struct SNode *Stack;

Stack newStack(int max){
    Stack s=(Stack)malloc(sizeof(struct SNode));
    s->top=-1;
    s->max=max;
    return s;
}

bool isFull(Stack s){
    return s->top==s->max-1;
}

bool isEmpty(Stack s){
    return s->top==-1;
}

bool push(Stack s,int data){
    if(isFull(s)) return false;
    s->data[++s->top]=data;
    return true;
}

int pop(Stack s){
    if(isEmpty(s)) return NULL;
    int last=s->data[s->top--];
    s->data[s->top+1]=0;
    return last;
}
