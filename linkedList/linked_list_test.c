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
   newnode->link = *start;
   *start = newnode;
}
void traverse(Node **start){
    Node *ptr = *start;
    printf("\t");
    while(ptr!=NULL){
        printf("%d->",ptr->data);
        ptr = ptr->link;
    }
    printf("NULL\n");
}

Node* join_list(Node **list1,Node **list2){
    Node *ptr1 = *list1;
    Node *ptr2 = *list2;
    if(ptr1==NULL){
        return *list2;
    }else if(ptr2==NULL) return *list1;

    while(ptr1->link!=NULL){
        ptr1 = ptr1->link;
    }
    ptr1->link = ptr2;
    return *list1;
}

int main(){
    Node *START=NULL;
    Node *START2=NULL;
    insertBeg(&START2,1);
    insertBeg(&START2,2);
    insertBeg(&START2,3);
    insertBeg(&START2,4);
    traverse(&START2);
    insertBeg(&START,1220);
    insertBeg(&START,140);
    insertBeg(&START,1045);
    insertBeg(&START,14);
    insertBeg(&START,154);
    insertBeg(&START,14);
    traverse(&START);
    Node *list3 = join_list(&START,&START2);
    traverse(&list3);
    return 0;

}
