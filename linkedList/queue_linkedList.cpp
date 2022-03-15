#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *link;
};

//QUEUE FIFO

void Enqueue(node* &front,node* &rear,int x){
    node *newnode = new node;
    if(newnode==NULL){
        printf("\n memory overflow");
        return;
    }else{
        newnode->data = x;
        newnode->link = NULL;
        if(front==rear==NULL){
            front = newnode;
            rear = newnode;
        }else{
            rear->link = newnode;
            rear = newnode;
        }
    }
}

void Dequeue(node* &front,node* &rear,int x){
    if(front==NULL){
        printf("\n underflow");
        return;
    }else{
        if((front==rear) && (front->link==NULL)){
            node *temp = front;
            delete temp;
            front=NULL;
            rear=NULL;
        }else{
            node *temp = front;
            front = front->link;
            delete temp;
        }
    }
}

int main(){
    node *front=NULL;
    node *rear=NULL;
    return 0;
}