#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *link;
} Node;


Node* getNode(int x){
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->data = x;
    newnode->link=NULL;
    return newnode;
}

void insertBeg(Node **start,int x){
   Node *newnode = getNode(x);
   if(*start=NULL){
       *start = newnode;
       newnode->link = newnode;
   }else{
       Node *temp = *start;
       newnode->link = temp->link;
       temp->link = newnode;
       *start = temp;
   }
}
void traverse(Node **start){
    Node *ptr = *start;
    Node *temp = ptr->link;
    printf("\t");
    while(temp!=*start){
        printf("%d->",temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}


int main(){
    Node *START=NULL;
    Node *START2=NULL;
    insertBeg(&START2,1);
    insertBeg(&START2,2);
    insertBeg(&START2,3);
    insertBeg(&START2,4);
    traverse(&START2);
    return 0;

}
