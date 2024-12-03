#include <iostream>
#define	SIZE = 64
struct Stack
{
	char StackArr[64];
	int Index;
	char name;
};
typedef Stack* st;

void init(st s1, char name)
{
	s1->Index = -1;
	s1->name = name;
	printf("Constucting stack : %s \n", s1->name);
}

void push(st s1, char ch)
{
	if (s1->Index == 63)
		printf("Stac %s is full", s1->name);
	s1->Index++;
	s1->StackArr[s1->Index] = ch;
}

char pop(st s1)
{
	if (s1->Index == -1)
		printf("Stak %s is empty", s1->name);
	char rt = s1->StackArr[s1->Index];
	s1->Index--;
	return rt;
}
int main()
{
	int f1 = 100;
	float a1, a2, a3;
	a1 = 0.5f;
	a2 = 0.6f;
	a3 = 0.4f;
	float f2 = f1 * 0.4f;
	printf("%f", f2);
	float f3 = (f2 * 0.4f) + f2;
	printf("%f", f3);
}