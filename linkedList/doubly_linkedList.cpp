#include<iostream>
using namespace std;
struct node{
    int data;
    struct node *next;
    struct node *prev;
};

node* getNode(int x){
    node *newnode = new node;
    newnode->data = x;
    newnode->next = newnode->prev = NULL;
    return newnode;
}

void InsertBeg(node* &start , int x){
    node *newnode = getNode(x);
    if(start==NULL){
        start = newnode;
    }else{
        newnode->next = start;
        newnode->prev = NULL;
        start->prev = newnode;
        start = newnode;
    }
}

void InsertEnd(node* &start , int x){
    node *newnode = getNode(x);
    node *ptr = start;
    while(ptr->next!=NULL){
        ptr = ptr->next;
    }
    ptr->next = newnode;
    newnode->prev = ptr;
}

void traverse(node* &start){
    cout<<endl;;
    node *temp = start;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp = temp->next;
    }
    printf("NULL");
    cout<<endl;
}

int main(){
    node *start1=NULL;
    InsertBeg(start1,10);
    InsertBeg(start1,50);
    InsertBeg(start1,13);
    InsertBeg(start1,30);
    InsertEnd(start1,202); 
    traverse(start1);
}