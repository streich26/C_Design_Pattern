#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// ����ڰ� ���� ���ؼ�, ���ϴ� ��ġ�� �����ϰ�, �����ϴ� ���� ����� �ʹ�.
// ��ȯ ���Ḯ��Ʈ�� ���·� ����� �ʹ�.
// 


struct Node
{
	int data;
	struct Node* link;
};


void in_Node(Node* n, Node* pre, int num)
{
	n->data = num;
	n->link = pre->link;
	pre->link = n;
}

void de_Node(Node* n,Node* pre, Node* next)
{
	n->link = pre->link;
	n->data = NULL;
	free(n);
}

int main()
{
	Node *n1, *n2, *n3, *n4;
	n1 = (Node*)malloc(sizeof(Node));
	n2 = (Node*)malloc(sizeof(Node));
	n3 = (Node*)malloc(sizeof(Node));
	n4 = (Node*)malloc(sizeof(Node));

	n1->data = 10;
	n1->link = n2;
	n2->data = 9;
	n2->link = n3;
	n3->data = 8;
	n3->link = n4;
	n4->data = 7;
	n4->link = NULL;




}

//https://jeongorithm.tistory.com/11 �̰��� �Լ��� ��ȯ�ؼ� �� �����̴�. 
