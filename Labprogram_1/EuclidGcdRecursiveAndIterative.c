#include<stdio.h>
#include<stdlib.h>
// EUCLID'S RECURSIVE GCD
int GCD(int a,int b)
{
    if(b==0)
        return a;
    else
        return(GCD(b,a%b));
}

// EUCLID'S ITERTATIVE GCD
int iterative(int a, int b){
    while (a != b){
        if (a > b)
            a = a - b;
        else 
            b = b - a;
    }
    return a;        
}

// MAIN FUNCTION
int main(){
    int p,q,r;
    printf("ENTER FIRST NUMBER : \n");
    scanf("%d",&p);
    printf("ENTER SECOND NUMBER : \n");
    scanf("%d",&q);
    if(p<q){
        r = p;
        p = q;
        q = r;
    }
    printf("ENTER\n 1. RECURSIVE \n 2. ITERATIVE \n -------------------\n");
    scanf("%d",&r);
    switch(r){
        case 1: r = GCD(p,q);
                break;
        case 2: r = iterative(p,q);
                break;
        default: {
            printf("Wrong choice\n");
            exit(0);
        }
    }
    printf("GCD of %d and %d is = %d",p,q,r);
    return 0;
}