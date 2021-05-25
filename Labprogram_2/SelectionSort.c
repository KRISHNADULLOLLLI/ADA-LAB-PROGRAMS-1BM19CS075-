#include<stdio.h>
#include<stdlib.h>
/* Q) Sort a given set of N integer elements using Selection Sort technique 
and compute its time taken. Run the program for different values of N and record the time taken to sort.*/

//MAIN FUNCTION
int main(){
int a[100], n, i, j, pos, swap;
printf("Enter number of elements : ");
scanf("%d", &n);
printf("Enter %d Numbers :\n", n);
for (i = 0; i < n; i++)
scanf("%d ", &a[i]);
for(i = 0; i < n - 1; i++){
pos=i;
for(j = i + 1; j < n; j++){
if(a[pos] > a[j])
pos=j;
}
if(pos!=i){
swap=a[i];
a[i]=a[pos];
a[pos]=swap;
}
}
printf("Sorted Array : \n");
for(i= 0;i<n;i++)
printf("%d ",a[i]);
return 0;
}