#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

struct node *START;
struct node *START2;

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

struct node* join(struct node *start1 , struct node *start2){
    struct node *list3=NULL;
    if(start1==NULL){
        list3 = start2;
        return list3;
    }
    else if(start2==NULL){
        list3 = start1;
        return list3;
    }
    struct node *ptr = start1;
    while(ptr->link!=NULL){
        ptr->link;
    }
    ptr->link = start2;
    list3 = start1;
    return list3;
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
    START2 = NULL;
    insertBeg(66);
    insertBeg(120);
    insertBeg(80);
    insertBeg(580);
    insertBeg(780);
    insertBeg(600);
    insertBeg(802);
    printf("\n");
    traverse();
    printf("\n");
    if(START==NULL)
        printf("\n %p \n",START);
    return 0;
}