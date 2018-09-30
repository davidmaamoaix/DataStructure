#include<mm_malloc.h>
#define MAXSIZE 65536

typedef struct LNode *List;

struct LNode{
    int data[MAXSIZE];
    int index;
};

List EmptyList(){
    List l;
    l=(List)malloc(sizeof(struct LNode));
    l->index=-1;
    return l;
}

bool insert(List l,int at,int value){
    if(l->index==MAXSIZE-1||at<0||(at>l->index&&l->index!=-1)) return false;
    for(int i=l->index;i>=at;i--) if(i!=-1) l->data[i+1]=l->data[i];
    l->data[at]=value;
    l->index++;
    return true;
}

bool erase(List l,int at){
    if(l->index==-1||at<0||at>l->index) return false;
    for(int i=at;i<l->index;i++) l->data[i]=l->data[i+1];
    l->data[l->index]=0;
    l->index--;
    return true;
}

int find(List l,int value){
    for(int i=0;i<l->index+1;i++) if(l->data[i]==value) return i;
    return -1;
}

int length(List l){
    return l->index+1;
}

int get(List l,int at){
    return l->data[at];
}

bool set(List l,int at,int value){
    if(l->index==-1||at<0||at>l->index) return false;
    l->data[at]=value;
    return true;
}
