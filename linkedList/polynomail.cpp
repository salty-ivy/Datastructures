#include<iostream>
using namespace std;
struct node{
    int coff;
    int expo;
    struct node *link;
};

node* getNode(int coff,int expo){
    node *newnode = new node;
    newnode->coff = coff;
    newnode->expo = expo;
    newnode->link = NULL;
    return newnode;
}

void insertBeg(node* &start,int coff,int expo){
    node *newnode = getNode(coff,expo);
    if(start==NULL){
        start = newnode;
    }
    else{
        newnode->link = start;
        start = newnode;
    }
}

int min(int a,int b){
    return a?a>=b:b;
}

void insertEnd(node* &start,int coff,int expo){
    node *newnode = getNode(coff,expo);
    node *temp = start;
    if (start==NULL){
        start = newnode;
    }else{

        while(temp->link!=NULL){
            temp = temp->link;
        }
        temp->link = newnode;
    }
}

struct node* addPoly(node* &poly1,node* &poly2){
    node *temp1 =  poly1;
    node *temp2 = poly2;
    node *start3=NULL;
    while(temp1!=NULL && temp2!=NULL){
        if(temp1->expo==temp2->expo){
            insertEnd(start3,temp1->coff+temp2->coff,temp1->expo);
            temp1 = temp1->link;
            temp2 = temp2->link;
        }else if(temp1->expo>temp2->expo){
            insertEnd(start3,temp1->coff,temp1->expo);
        }else{
            insertEnd(start3,temp2->coff,temp2->expo);
        }
    }
    return start3;
}

void traverse(node* &start){
    cout<<endl;
    node *temp = start;
    while(temp!=NULL){
        if(temp->link==NULL){
            printf("%d",temp->coff);
        }else{
            printf("%dX^%d + ",temp->coff,temp->expo);
        }
        temp = temp->link;

    }
}

int main(){
    node *poly1=NULL;
    node *poly2=NULL;

    insertBeg(poly1,2,0);
    insertBeg(poly1,3,1);
    insertBeg(poly1,6,2);
    insertBeg(poly1,7,3);
    traverse(poly1);
    insertBeg(poly2,1,0);
    insertBeg(poly2,4,1);
    insertBeg(poly2,8,2);
    insertBeg(poly2,10,3);
    traverse(poly2);
    node *poly3 = addPoly(poly1,poly2);
    traverse(poly3);

    return 0;
}