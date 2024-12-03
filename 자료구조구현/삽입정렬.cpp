#include <stdio.h>

void insert_sort_up(int arr[], int n)
{
	int i,j,key;

	for (i = 1; i < n; i++)
	{
		key = arr[i];

		for (j = i-1; j >= 0 && arr[j] > key; j--)
		{
			arr[j + 1] = arr[j];
		}

		arr[j + 1] = key;
	}

}
void insert_sort_down(int arr[], int n)
{
	int i, j, key;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		for (j = i - 1; j >= 0 && arr[j] < key; j--)
		{
			arr[j+1] = arr[j];
		}
		arr[j+1] = key;
	}
}

int main()
{
	int i;
	int list[5] = { 8,5,6,3,4 };
	int size = sizeof(list) / sizeof(int);

	insert_sort_up(list, size);
	for (int i = 0; i < size; i++)
	{
		printf("%d", list[i]);
	}
	printf("\n");
	int list2[5] = { 7,5,4,9,1 };
	int size2 = sizeof(list2) / sizeof(int);
	insert_sort_down(list2, size2);
	for (int i = 0; i < size2; i++)
	{
		printf("%d", list2[i]);
	}
	
}