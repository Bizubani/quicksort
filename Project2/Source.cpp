#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LIMIT 10000

unsigned long recusionCount, comparisonCount;
void quickSort(int sortThis[], int size);

int main(void) {
	errno_t errorStatus;
	int* sort = (int*) calloc(LIMIT, sizeof(int));
	int count;
	FILE* ftp;
	errorStatus = fopen_s(&ftp, "QuickSort.txt", "r");
	if (errorStatus != 0) {
		puts("Unable to open QuickSort.txt");
	}
	else {
		for (count = 0; count < LIMIT; count++) {
			if (ftp != NULL && sort != NULL)
			{
				fscanf_s(ftp, "%d", &sort[count]);
			}
			
		}
	}	
	quickSort(sort, LIMIT);

	printf_s("\nNumber of comparisons %u", comparisonCount);	
	free(sort);
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
		srand(time(NULL));
		//pivot = findPivot(sortThis, size-1); //choose specific pivots
		pivot = rand() % size;
		leftSize = partition(sortThis, pivot, size);
		rightSize = size - leftSize - 1;

		quickSort(sortThis, leftSize);

		quickSort(&sortThis[leftSize + 1], rightSize);
	}

}

int partition(int subArray[], int pivotPosition, int totalSize) {
	int pivot = subArray[pivotPosition];
	int leftSize = 1;
	int count, temp;

	temp = subArray[0];
	subArray[0] =pivot;
	subArray[pivotPosition] = temp;

	comparisonCount += totalSize - 1;

	for (count = leftSize; count < totalSize; count++) {
		if (pivot > subArray[count]) {
			temp = subArray[count];
			subArray[count] = subArray[leftSize];
			subArray[leftSize++] = temp;
		}

	}
	temp = subArray[--leftSize];
	subArray[leftSize] = pivot;
	subArray[0] = temp;

	printf("\nRecusion Count: %d, Pivot: %d, size of left array: %d, size of right array: %d\n", ++recusionCount, pivot, leftSize, totalSize - leftSize);

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