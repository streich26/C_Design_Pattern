#include <iostream>

int queue[100];
int front = -1;
int rear = -1;

int is_Empty()
{
	if (front == rear) return 1;
	else return 0;
}

int is_End()
{
	if (rear == (sizeof(queue) / sizeof(int))) return 1;
	else return 0;
}

void Insert_Q(int a)
{
	if (is_End()) {
		std::cout << "ť�� �� á���ϴ�!" << std::endl;
		exit(1);
	}
	rear++;
	queue[rear] = a;
}

int Delete_Q() {
	if (is_Empty()) {
		std::cout << "ť�� ������ϴ�!" << std::endl;
		exit(1);
	}
	front++;
	return	queue[front];

}
// ���� ť ����
//https://dream-and-develop.tistory.com/102