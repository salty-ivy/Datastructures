#include<stdio.h>

int And(int a,int b){
    if((a==1&&b==1))
        return 1;
    else return 0;
}

int Or(int a,int b){
    if((a==1&&b==0) || (a==0&&b==1) || (a==1&&b==1))
        return 1;
    else if ((a==0 && b==0)) return 0;
}

int Not(int a){
    if (a==1) return 0;
    else if (a==0) return 1;
}

int main(){
    int a=1;
    int b=0;
    printf("\n\tA\tB\tAND\tOR\tNOT(a and b)");
    printf("\n\t%d\t%d\t%d\t%d\t%d",a,b,And(a,b),Or(a,b),Not(a));
    printf("\n\t%d\t%d\t%d\t%d\t%d",a,a,And(a,a),Or(a,a),Not(b));
    printf("\n\t%d\t%d\t%d\t%d",a,b,And(b,b),Or(b,b));
    return 0;

}