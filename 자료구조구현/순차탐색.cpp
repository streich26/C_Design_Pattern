#include <stdio.h>

int seq_search(int list[], int key, int low, int high)
{
	int i;
	int hi = high - 1;
	
	for (i = low; i <= hi; i++)
		if (list[i] == key)
			return i;
	return -1;
}

int seq_search2(int list[], int key, int low, int high)
{
	int i;
	list[high + 1] = key;
	for (i = low; list[i] != key; i++) //Ű �� ã���� ����
		;
	if (i == (high + 1)) return -1;	// Ž�� ����
	else return i;	// Ž�� ����
}


int main()
{
	int list[] = { 5,0,7,8,10,9 };
	int n = sizeof(list) / sizeof(int);
	int re = seq_search(list, 9, 0, n);
	printf("%d\n", re);
	int re2 = seq_search2(list, 9, 0, n);
	printf("%d", re2);
}