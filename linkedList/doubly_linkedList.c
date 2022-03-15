#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
} Node;

Node* getNode(int x){
    Node * newnode = (Node*)malloc(sizeof(Node));
    newnode->data = x;
    return newnode;
}

void InsertBeg(Node **start,int x){
    Node* newnode = getNode(x);
    *start
}

int main(){
    return 0;
}