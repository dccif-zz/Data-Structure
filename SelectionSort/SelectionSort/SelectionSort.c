#include<stdio.h>
#define LENGTH(array) ( (sizeof(array)) / (sizeof(array[0])) )
void selectsort(int arr[], int len) {
	int i, j, min, temp;
	for (i = 0; i < len - 1; i++) {
		min = i;
		for (j = i + 1; j < len; j++) {
			if (arr[min] > arr[j]) {
				min = j;
			}
		}
		temp = arr[min];
		arr[min] = arr[i];
		arr[i] = temp;
	}
}

void main()
{
	int i;
	int arr[] = { 30,40,20,10,60,50 };
	int ilen = LENGTH(arr);

	printf("before sort:");
	for (i = 0; i<ilen; i++)
		printf("%d ", arr[i]);
	printf("\n");

	selectsort (arr, ilen);

	printf("after  sort:");
	for (i = 0; i<ilen; i++)
		printf("%d ", arr[i]);
	printf("\n");
	system("pause");
}