#include<stdio.h>
#define LENGTH(array) ( (sizeof(array)) / (sizeof(array[0])) )
void insertionsort(int arr[], int len) {
	int i, j, k;
	for (i = 1; i < len; i++) {
		for (j = i - 1; j >= 0; j--) {
			if (arr[j] < arr[i])
				break;
		}
		if (j != i - 1) {
			int temp = arr[i];
			for (k = i - 1; k > j; k--) {
				arr[k + 1] = arr[k];
			}
			arr[k + 1] = temp;
		}
		}
	}

void main()
{
	int i;
	int arr[] = { 20,40,30,10,60,50 };
	int ilen = LENGTH(arr);

	printf("before sort:");
	for (i = 0; i<ilen; i++)
		printf("%d ", arr[i]);
	printf("\n");

	insertionsort(arr, ilen);

	printf("after  sort:");
	for (i = 0; i<ilen; i++)
		printf("%d ", arr[i]);
	printf("\n");
	system("pause");
}