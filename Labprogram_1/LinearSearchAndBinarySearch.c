#include <stdio.h>
#include <stdlib.h>

// RECURSVE LINEAR SEARCH 
int recSearch(int arr[], int l, int r, int x)
{
     if (r < l)
        return -1;
     if (arr[l] == x)
        return l;
     if (arr[r] == x)
        return r;
     return recSearch(arr, l+1, r-1, x);
}

// RECURSIVE BINARY SEARCH (Mid method Rule)
int recursiveBinarySearch(int array[], int start_index, int end_index, int element){
   if (end_index >= start_index){
      int middle = start_index + (end_index - start_index )/2;
      if (array[middle] == element)
         return middle;
      if (array[middle] > element)
         return recursiveBinarySearch(array, start_index, middle-1, element);
      return recursiveBinarySearch(array, middle+1, end_index, element);
   }
   return -1;
}

// MAIN FUNCTION
void main(){
    int choice,x,y;
    int arr[] = {10, 20, 30, 40, 50},i;
    int array[] = {60, 70, 80, 90, 100, 110, 120};// Took directly in ascending order
    int m = 7;
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("ENTER\n 1. Linear Search \n 2. Binary Search \n -------------------\n");
    scanf("%d",&choice);
    switch(choice){
       case 1: printf("ELEMENT TO SEARCH : ");
               scanf("%d",&x);
               int index = recSearch(arr, 0, n-1, x);
               if (index != -1)
               printf("Element %d is present at index %d", x, index);
               else
               printf("Element %d is not present", x);
               break;
        case 2: printf("ELEMENT TO SEARCH : ");
                scanf("%d",&y);
                int found_index = recursiveBinarySearch(array, 0, m-1, y);
                if(found_index == -1 ) {
                 printf("Element not found in the array ");
                 }
                else {
                 printf("Element found at index : %d",found_index);
                }
                break;
     }
}