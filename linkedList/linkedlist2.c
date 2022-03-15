#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *next;

};
struct node *start;
struct node *GetNode(){
    struct node *p;
    p=(struct node*)malloc(sizeof(struct node));
    return p;
}

void InsertBeg(int x){
    struct node *p;
    p=GetNode();
    p->info = x;
    p->next = start;
    start=p;
}

void traverse(){
    struct node *t = start;
    while(t!=NULL){
        printf("\t %d",t->info);
        t=t->next;
    }
}

void swap(struct node *start){
    struct node *p = start;
    int temp;
    while(p!=NULL&&p->next!=NULL){
        temp = p->info;
        p->info = p->next->info;
        p->next->info = temp;
        p = p->next->next;
    }
}

int main(){
    start=NULL;
    InsertBeg(100);
    InsertBeg(200);
    InsertBeg(300);
    InsertBeg(400);
    InsertBeg(500);
    InsertBeg(600);
    InsertBeg(700);
    InsertBeg(800);
    traverse();
    printf("\n");
    swap(start);
    traverse();
    return 0;
}
