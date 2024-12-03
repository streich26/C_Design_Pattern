#include <stdio.h>

struct Queue
{
	int queue[5];
	int front;
	int rear;
};

void init_queue(Queue* q)
{
	q->front = 0;
	q->rear = 0;
}

int is_empty(Queue* q)
{
	return (q->front == q->rear);
}

int is_full(Queue* q)
{
	return (q->rear + 1) % 5 == q->front;
}

void enqueue(Queue* q, int item)
{
	if (is_full)
	{
		printf("Queue is full");
	}
	q->rear = (q->rear + 1) % 5;
	q->queue[q->rear] = item;
}

int dequeue(Queue* q)
{
	if (is_empty)
	{
		printf("Queue is empty");
	}
	q->front = (q->front + 1) % 5;
	return q->queue[q->front];
}

void queue_print(Queue* q)
{
	for (int i = 0; i < 5; i++)
	{
		printf("%d\t front : %d, rear : %d \n", q->queue[i], q->front, q->rear);
		printf("\n");
	}
}
int main()
{
	Queue q;
	init_queue(&q);

	printf("enqueue \n\n");
	for (int i = 0; i < 5; i++)
	{
		enqueue(&q, i);
		queue_print(&q);
	}

	printf("\ndequeue\n\n");
	for (int i = 0; i < 5; i++)
	{
		printf("dequeue %d \n", dequeue(&q));
		queue_print(&q);
	}
}