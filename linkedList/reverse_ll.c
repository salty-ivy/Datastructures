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

void reverse(){
    struct node *current = START;
    struct node *previous = NULL;
    struct node *next = START;

    while(next!=NULL){
        next = next->link;
        current->link = previous;
        previous = current;
        current = next;
    }
    START = previous;
}

void traverse(){
    if (START==NULL){
        printf("\n LINK IS EMPTY! ");
    }else{
        struct node *ptr = START;
        while(ptr != NULL){
            printf("%d->",ptr->data);
            ptr = ptr->link;
        }
        printf("NULL");
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
    insertBeg(600);
    insertBeg(802);
    printf("\n");
    traverse();
    reverse();
    traverse();
    printf("\n");
    if(START==NULL)
        printf("\n %p \n",START);
    return 0;
}