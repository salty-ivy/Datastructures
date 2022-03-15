#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *link;
};

void push(node* &top,int x){

    node *newnode = new node;
    newnode->data=x;
    if(newnode==NULL){
        printf("\n heap memory overflow\n");
        return;
    }
    newnode->link = top;
    top = newnode;
}

int pop(node* &top){
    if(top==NULL){
        printf("\nunderflow!\n");
    }
    node *temp = top;
    top = top->link;
    int x= temp->data;
    delete temp;
    return x;
}

int peek(node* top){
    return top->data;
}

void traverse(node *top){
    node *temp = top;
    while(temp!=NULL){
        printf("\n%d",temp->data);
        temp = temp->link;
    }
}

int main(){
    node *top=NULL;
    push(top,10);
    push(top,460);
    push(top,657);
    push(top,145);
    push(top,1340);
    push(top,123);
    push(top,1323);
    push(top,3120);
    push(top,133);
    traverse(top);
    pop(top);
    pop(top);
    pop(top);
    pop(top);
    pop(top);
    cout<<endl;
    traverse(top);
    return 0;
}