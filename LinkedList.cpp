#include<mm_malloc.h>

typedef struct LNode *Ptr;
typedef Ptr Node;
typedef Ptr List;

struct LNode{
    int data;
    Ptr next;
};

Node get(List l,int at){
    Node n=l;
    for(int i=0;i<at;i++) n=n->next;
    return n;
}

bool insert(List l,int at,int value){
    Node tmp,pre,next;
    pre=get(l,at-1);
    next=get(l,at);
    if(pre==NULL) return false;
    tmp=(Node)malloc(sizeof(struct LNode));
    tmp->data=value;
    tmp->next=next;
    pre->next=tmp;
    return true;
}

bool erase(List l,int at){
    Node pre,next;
    pre=get(l,at-1);
    next=get(l,at);
    if(pre==NULL) return false;
    pre->next=next->next;
    free(next);
    return true;
}

Node find(List l,int value){
    Node at;
    for(at=l;at&&at->data!=value;at=at->next);
    return at;
}

bool set(List l,int at,int value){
    Node tmp=get(l,at);
    if(tmp==NULL) return false;
    tmp->data=value;
    return true;
}

int length(List l){
    List at;int len=0;
    for(at=l;at;at=at->next) len++;
    return len;
}
