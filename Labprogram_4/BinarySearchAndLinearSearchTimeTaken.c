#include <stdio.h>
#include <stdlib.h>
#include <time.h>


clock_t start1, start2, end1, end2;
double cpu_time_used1, cpu_time_used2;
int c, d;

int numsArray[12] = {1000, 2000, 5000, 8000, 10000, 15000, 20000, 25000, 30000, 40000, 45000, 50000};

// 1) LINEAR SEARCH
int recLinearSearch(int arr[], int l, int r, int x){
    if (r < l)
        return -1;
    if (arr[l] == x)
        return l;
    if (arr[r] == x)
        return r;
    for (d = 1; d <= 10000; d++){}
    return recLinearSearch(arr, l + 1, r - 1, x);
}

// 2) BINARY SEARCH
int recBinarySearch(int arr[], int l, int r, int x){
    if (r >= l){
        for (d = 1; d <= 50000; d++){}
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return recBinarySearch(arr, l, mid - 1, x);
        return recBinarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

int main(){
    int result, k, choice, n, x, j, a, i, l;
    while (1){
        printf("\n\n\n\nSELECT YOUR CHOICE\n----------------\n1) LINEAR SEARCH\n2) BINARY SEARCH\n3) STOP\n----------------\n");
        scanf("%d", &choice);

        // 1) LINEAR SEARCH CALCULATION
        if (choice == 1){
            for(l = 0; l < 12; l++){
                printf("number of elements - %d\n", numsArray[l]);
                n = numsArray[l];
                int arr[n];
                printf("Generating array \n");
                for (int k = 1; k <= n; k++){
                    arr[k] = rand() % 100;
                    }
                printf("array generated \n");

                // x = rand() % 100;
                x = 2;
                printf("\nsearching for %d\n", x);
                start1 = clock();
                result = recLinearSearch(arr, 0, n - 1, x);
                
                end1 = clock();
                printf("search finish\n");
                cpu_time_used1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
                (result == -1) ? printf("Element is not present in array\n") : printf("Element is present at index %d\n", result);
                printf("time used: %f\n", cpu_time_used1);
            }           
        }

        // 2) BINARY SEARCH TIME CALCULATION
        else if (choice == 2){
            for (l = 0; l < 12; l++){
                printf("number of elements - %d\n", numsArray[l]);
                n = numsArray[l];
                int arr[n];
                printf("Generating array......\n");
                for (int k = 1; k <= n; k++){
                    arr[k] = rand() % 100;
                    }
                for (i = 1; i <= n; i++){
                    for (j = i + 1; j <= n; ++j){
                        if (arr[i] > arr[j]){
                            a = arr[i];
                            arr[i] = arr[j];
                            arr[j] = a;
                        }
                    }
                }
                printf("array generated!\n");

                // x = rand() % 100;
                x = 2;
                printf("\nsearching for %d\n", x);
                start2 = clock();
                result = recBinarySearch(arr, 0, n - 1, x);
                
                    
                end2 = clock();
                printf("search finish\n");
                cpu_time_used2 = (double)(end2 - start2) / CLOCKS_PER_SEC;
                (result == -1) ? printf("Element is not present in array\n") : printf("Element is present at index %d\n", result);
                printf("time used: %f\n", cpu_time_used2);
            }
        }
        else
            break;
    }
    return 0;
}
