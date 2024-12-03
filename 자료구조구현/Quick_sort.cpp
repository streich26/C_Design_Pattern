#include <stdio.h>

void swap(int x, int y, int temp)
{
	temp = x;
	x = y;
	y = temp;
}

// ���� �� ������ �ɰ��� �ٽ� ���� �ϴ� ��
int partition(int list[], int left, int right)
{
	int temp = 0;
	int pivot;
	int low, high;

	low = left;
	high = right + 1;
	pivot = list[left];

	do {
		do {
			low++;
		} while (low <= right && list[low] < pivot);

		do {
			high--;
		} while (high >= left && list[high] > pivot);

		if (low < high) {
			swap(list[low], list[high], temp);
		}
	} while (low < high);
	
	swap(list[left], list[high], temp);

	return high;
}
int partition2(int list[], int left, int right)
{
	int temp = 0;
	int pivot;
	int low, high;

	low = left + 1;
	high = right;
	pivot = left;

	while (low <= high) 
	{
		while (low <= right && list[low] <= list[pivot])
		{
			low++;
		}
		while (high >= left && list[high] >= list[pivot])
		{
			high--;
		}
		if (low < high)
		{
			swap(list[low], list[high], temp);
		}
	}
	swap(list[low], list[high], temp);
	
	return high;
}


void Quick_sort(int list[], int start, int end)
{
	printf("start = %d\n", start);
	if (start >= end) return; // ���Ұ� 1���� ��� �״�� ����

	int pivot = start; 
	int i = start + 1, j = end, temp;

	while (i <= j) { // ������ ������ �ݺ� 
		while (i <= end && list[i] <= list[pivot]) i++; // �Ǻ� ������ ū ���� ���� ������

		while (j > start && list[j] >= list[pivot]) j--; // �Ǻ� ������ ���� ���� ���� ������

		if (i > j) {
			temp = list[j];
			list[j] = list[pivot];
			list[pivot] = temp;
		}
		else {
			temp = list[i];
			list[i] = list[j];
			list[j] = temp;
		}
	}

	Quick_sort(list, start, j - 1);
	Quick_sort(list, j + 1, end);
	
}



int main()
{
	int list[9] = { 5,3,8,4,9,1,6,2,7 };
	int size = sizeof(list) / sizeof(int);

	Quick_sort(list, 0, size - 1);
	for (int i = 0; i < size; i++)
	{
		printf("%d ", list[i]);
	}
}