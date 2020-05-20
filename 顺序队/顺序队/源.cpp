#define MAXSIZE 1000
#include<iostream>
typedef int Elemetype;
typedef struct SqQueue/*front总是指向队头元素的前一位置*//*队尾插入，队首删除*//*非环形队列*/
{
	Elemetype data[MAXSIZE];
	int front, rear;
}SqQueue;
void init_queue(SqQueue *&Q)
{
	Q = (SqQueue*)malloc(sizeof(SqQueue));
	Q->front = Q->rear = -1;
}
void Destory_queue(SqQueue *&Q)
{
	free(Q);
}
bool push(SqQueue*&Q, Elemetype e)
{
	if (Q->rear == MAXSIZE-1)
	{
		return false;
	}
	Q->rear++;
	Q->data[Q->rear] = e;
	return true;
}
bool pop(SqQueue *&Q, Elemetype &e)
{
	if (Q->front == Q->rear)
	{
		return false;
	}
	Q->front++;
	e = Q->data[Q->front];
	return true;
}
/*
Version1
环形队列：包括队尾指针，会少放一个元素，初始front,rear为0
队空条件：front == rear
队满条件：front ==（rear+1）% MAXSIZE 
进队：rear = （rear+1）%Maxsize
出队：front = （front+1）%Maxsize
*/
/*
Version2
环形队列：不包括队尾指针，存放元素个数为MAXSIZE，元素个数等于MAXSIZE
队空条件：count == 0
队满条件：count == MAXSIZE
count = （rear-front+MAXSIZE）%MAXSIZE
rear = （front+count）%MAXSIZE
front = （rear-count+MAXSIZE）%MAXISIZE
进队：rear = （rear+1）%Maxsize
出队：front = （front+1）%Maxsize
*/
typedef struct Rqueue
{
	Elemetype data[MAXSIZE];
	int front;
	int count;
}Rqueue;
void init_Rqueue(Rqueue *&Q)
{
	Q = (Rqueue*)malloc(sizeof(Rqueue));
	Q->count = Q->front = 0;
}
bool empty_Rqueue(Rqueue *Q)
{
	return Q->count == 0;
}
bool push(Rqueue *&Q, Elemetype e)
{
	if (Q->count == MAXSIZE)
	{
		return false;
	}
	else
	{
		int rear = (Q->front + Q->count) % MAXSIZE;
		rear == (rear + 1) % MAXSIZE;
		Q->data[rear] = e;
		Q->count++;
		return true;
	}	
}
bool pop(Rqueue *&Q, Elemetype &e)
{
	if (Q->count == 0)
	{
		return false;
	}
	else
	{
		Q->front = (Q->front + 1) % MAXSIZE;
		e = Q->data[Q->front];
		Q->count--;
		return true;
	}
}
