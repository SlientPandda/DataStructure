#include <iostream>
#define MAXSIZE  50

using namespace std;
typedef struct LNode{
    int data;
    LNode *next;
}LNode,*LinkList;
int main(){

}

void del(LinkList &l,int  x){//2.3.1
    LNode *p;
    if(l==NULL)
        return;
    if(l->data==x){
        p = l;
        l = l->next;
        free(p);
        del(l, x);
    }
    else
        del(l->next, x);

}



void del_2(LinkList &l,int x){//2.3.2
    LNode *p = l->next, *pre = l, *q;
    while(p!=NULL){
        if(p->data==x){
            q = p;
            p = p->next;
            pre->next = p;
            free(q);

        }
        else{
            pre = p;
            p = p->next;
        }
    }
}


