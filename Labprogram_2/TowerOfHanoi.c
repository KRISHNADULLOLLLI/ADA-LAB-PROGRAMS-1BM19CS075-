#include <stdio.h>
#include <stdlib.h>
//Recursive Tower of Hanoi
void TowerOfHanoi(int n,char x,char y,char z){
   if(n>0){
      TowerOfHanoi(n-1,x,z,y);
      printf("\n%c to %c",x,y);
      TowerOfHanoi(n-1,z,y,x);
   }
}
//Main Function
int main(){
   int n;
   printf("Enter no of rings: ");
   scanf("%d",&n);
   TowerOfHanoi(n,'A','B','C');
}