#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*LABPROGRAM 3 (04/05/2020) BASAVARAJ JAKALLI SIR.
Q) Sort a given set of N integer elements using Selection Sort technique and compute its time taken.
Run the program for different values of N and record the time taken to sort.*/

// 1) MAIN FUNCTION
int main(){
	long int n = 10000;
	int it = 0;

	// Arrays to store time duration of sorting algorithms
	double tim1[10], tim2[10], tim3[10];

	printf("\n\n\n\n\n\nARRAY SIZE | Selection Sort (time taken by SS algo)\n");
	printf("---------------------------\n");

	while (it++ < 10) {
		long int a[n], b[n], c[n];
		// generating n random numbers storing them in arrays a, b, c
		for (int i = 0; i < n; i++) {
			long int no = rand() % n + 1;
			a[i] = no;
			b[i] = no;
			c[i] = no;
		}

		// using clock_t to store time
		clock_t start, end;
		tim2[it] = ((double)(end - start));

		// Selection sort
		start = clock();
		selectionSort(c, n);
		end = clock();

		tim3[it] = ((double)(end - start));

		// type conversion to long int for plotting graph with integer values
		printf("  %li    | %li ms\n",n, (long int)tim3[it]);

		// increases the size of array by 10000
		n += 1000;
	}
	return 0;
}

// 2) SELECTION SORT FUNCTION
void selectionSort(long int arr[], long int n){
	long int i, j, midx;
	for (i = 0; i < n - 1; i++) {

		// Find the minimum element in unsorted array
		midx = i;
		for (j = i + 1; j < n; j++)
			if (arr[j] < arr[midx])
				midx = j;

		// Swap the found minimum element with the first element
		swap(&arr[midx], &arr[i]);
	}
}

// 3) SWAP FUNCTION USED IN SELECTION SORT TECHNIQUE
void swap(long int* a, long int* b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}