#include<iostream>
#include<mm_malloc.h>
using namespace std;

typedef struct QNode *Queue;
struct QNode{
    int data[65536];
    int front,rear,max;
};

Queue newQueue(int max){
    Queue q=(Queue)malloc(sizeof(struct QNode));
    q->front=q->rear=0;
    q->max=max;
    return q;
}

bool isFull(Queue q){
    return q->rear-q->front==q->max;
}

bool isEmpty(Queue q){
    return q->rear-q->front==0;
}

bool add(Queue q,int value){
    if(isFull(q)) return false;
    q->data[q->rear++]=value;
    return true;
}

int del(Queue q){
    int num=q->data[q->front];
    q->data[q->front++]=0;
    return num;
}

void print(Queue q){
    cout<<'[';
    for(int i=q->front;i<q->rear;i++) cout<<q->data[i]<<',';
    cout<<']'<<endl;
}
