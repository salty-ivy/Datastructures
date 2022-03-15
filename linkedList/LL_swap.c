#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

struct node *START;

struct node* getNode(int x){

    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = x;
    if (ptr == NULL){
        exit(1);
    }
    ptr->link = NULL;
    return ptr;
}

void insertBeg(int x){
    struct node* newnode = getNode(x);
    newnode->link = START;
    START = newnode;
}

void insertEnd(int x){

    struct node *newnode = getNode(x);
    if (START==NULL){
        START = newnode;
    }
    else{
        struct node *ptr = START;
        while (ptr->link != NULL){
            ptr = ptr->link;
        }
        ptr->link = newnode;
    }
}

void insertAft(int data, int x){
    struct node *newnode = getNode(x);
    if (START == NULL){
        START = newnode;
    }else{
        struct node *ptr = START;
        while (ptr->data != data){
            ptr = ptr->link;
        }
        newnode->link = ptr->link;
        ptr->link = newnode;
    }
}


void deleteBeg(){
    if (START==NULL){
        printf("\n UNDERFLOW!");
    }
    else{

        struct node *ptr = START;
        START = START->link;
        free(ptr);
    }

}

void deleteEnd(){
    struct node*ptr = START;
    if (START==NULL){
        printf("\n UNDERFLOW!!");
    }
    else{
        struct node *q;
        while(ptr->link != NULL){
            q = ptr;
            ptr = ptr->link;
        }
        q->link = NULL;
        free(ptr);
    }
}

void deleteMid(int data){
    if (START==NULL){
        printf("\n UNDERFLOW!");
    }else{
        struct node *ptr = START;
        while(ptr->link->data != data){
            ptr = ptr->link;
        }

        struct node *q = ptr->link;
        ptr->link = q->link;
        free(q);
    }
}

void swap(){
    struct node *ptr = START;
    int temp;
    while(ptr!=NULL && ptr->link!=NULL){
        temp = ptr->data;
        ptr->data = ptr->link->data;
        ptr->link->data = temp;
        ptr = ptr->link;
    }
}

void traverse(){
    if (START==NULL){
        printf("\n LINK IS EMPTY! ");
    }else{
        struct node *ptr = START;
        while(ptr != NULL){
            printf("\t %d ",ptr->data);
            ptr = ptr->link;
        }

        printf("\n");
    }
}


int main(){
    START = NULL;
    insertBeg(66);
    insertBeg(120);
    insertBeg(80);
    insertBeg(580);
    insertBeg(780);
    insertEnd(600);
    insertAft(80,110);
    traverse();
    swap();
    traverse();
    if(START==NULL)
        printf("\n %p \n",START);
    return 0;
}