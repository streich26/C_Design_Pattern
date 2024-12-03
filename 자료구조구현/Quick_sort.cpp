#include <stdio.h>

void swap(int x, int y, int temp)
{
	temp = x;
	x = y;
	y = temp;
}

// 정렬 후 반으로 쪼개서 다시 정렬 하는 것
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
	if (start >= end) return; // 원소가 1개인 경우 그대로 리턴

	int pivot = start; 
	int i = start + 1, j = end, temp;

	while (i <= j) { // 엇갈릴 때까지 반복 
		while (i <= end && list[i] <= list[pivot]) i++; // 피봇 값보다 큰 값을 만날 때까지

		while (j > start && list[j] >= list[pivot]) j--; // 피봇 값보다 작은 값을 만날 떄까지

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