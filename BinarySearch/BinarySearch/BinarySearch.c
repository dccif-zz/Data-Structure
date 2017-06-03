#include<stdio.h>

int BinarySearch(int a[], int n, int key) {
	int low = 0;
	int high = n - 1;
	while (low<=high)
	{
		int mid = (low + high) / 2;
		int midval = a[mid];
		if (midval < key) {
			low = mid + 1;
		}
		else if(midval>key)
		{
			high = mid - 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}


int main() {
	int i, val, ans;
	int a[8] = { -32,12,42,54,65,78,45,87 };
	for (int i = 0; i < 8; i++) {
		printf("%d\t", a[i]);
	}
	printf("\n������Ҫ���ҵ�Ԫ�أ�");
	scanf("%d", &val);

	ans = BinarySearch(a, 8, val);

	if (ans == -1) {
		printf("��Ԫ��\n");
	}
	else
	{
		printf("���ҳɹ�\n%d�ǵ�%d��Ԫ��",val,ans+1);
	}
	system("pause");
}
