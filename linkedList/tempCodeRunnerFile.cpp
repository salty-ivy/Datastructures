
node* addPoly(node* &poly1,node* &poly2){
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
}