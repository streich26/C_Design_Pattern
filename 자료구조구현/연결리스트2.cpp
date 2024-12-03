#include <iostream>

struct Node
{
	int data;
	Node* next;		//다음 위치를 가리키는 포인터
};
class LinkedList
{
	Node* head;
	Node* tail;
	LinkedList();
	~LinkedList();
	void insertNode(int data);  // 노드 삽입
	void deleteNode(int data);  // 노드 제거
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