#include <iostream>

struct Node
{
	int data;
	Node* next;		//���� ��ġ�� ����Ű�� ������
};
class LinkedList
{
	Node* head;
	Node* tail;
	LinkedList();
	~LinkedList();
	void insertNode(int data);  // ��� ����
	void deleteNode(int data);  // ��� ����
	void printNode();
};

LinkedList::LinkedList()
{
	head = new Node();
	head->data = -1;
	tail = new Node();
	tail->data = -1;

	head->next = tail;
	tail->next = NULL;

}
LinkedList::~LinkedList()
{
	Node* now, *temp;
	for (now = head->next; now != tail;)
	{
		temp = now->next;
		delete(now);
		now = temp;
	}
	delete(head);
	delete(tail);

}

int main()
{

}