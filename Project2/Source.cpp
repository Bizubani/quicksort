#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#define LIMIT 10000

unsigned long recusionCount, comparisonCount;
void quickSort(int sortThis[], int size);

int main(void) {
	int sort[LIMIT],count;
	FILE* ftp;
	if ((ftp = fopen("QuickSort.txt", "r")) == NULL) {
		puts("Unable to open QuickSort.txt");
	}
	else {
		for (count = 0; count < LIMIT; count++) {
			fscanf(ftp, "%d", &sort[count]);
		}
	}
	
	quickSort(sort, LIMIT);
	for (count = 0; count < LIMIT; count++) {
		printf("%d\n", sort[count]);
	}
	printf_s("%u", comparisonCount);
	getchar();
	return 0;

}


void quickSort(int sortThis[], int size) {
	int partition(int compare[], int left, int right);
	int findPivot(int a[], int size);
	int pivot, leftSize, rightSize;

	if (size <= 1) {
		return;
	}
	else {
		pivot = findPivot(sortThis, size-1); // select first element to be pivot
		leftSize = partition(sortThis, pivot, size);
		rightSize = size - leftSize - 1;

		quickSort(sortThis, leftSize);

		quickSort(&sortThis[leftSize + 1], rightSize);
	}

}

int partition(int compare[], int left, int right) {
	int pivot = compare[left];
	int leftSize = 1;
	int count, temp;

	temp = compare[0];
	compare[0] =pivot;
	compare[left] = temp;

	comparisonCount += right - 1;

	for (count = leftSize; count < right; count++) {
		if (pivot > compare[count]) {
			temp = compare[count];
			compare[count] = compare[leftSize];
			compare[leftSize++] = temp;
			printf("%d ", leftSize);
		}

	}
	puts("");
	temp = compare[--leftSize];
	compare[leftSize] = pivot;
	compare[0] = temp;

	printf("Recusion Count: %d, Pivot: %d, size of left array: %d\n", ++recusionCount, pivot, leftSize);
	for (count = 0; count < right; count++) {
		printf("%d ", compare[count]);
	}
	puts("");


	return leftSize;
}

int findPivot(int a[], int size) {
	int first, second, third;

	first = a[0];
	third = a[size];
	second = a[(size / 2)];
	

	printf("\nFirst: %d Second: %d Third: %d\n", first, second, third);

	if (first < second && first < third) {
		if (second < third) {
			return (size / 2);
		}
		else {
			return size;
		}
	}
	else if(first > second && first > third) {
		if (second > third) {
			return (size / 2);
		}
		else {
			return size;
		}
	}
	else return 0;

}