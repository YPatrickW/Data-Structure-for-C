#define MAXSIZE 1000
#include<iostream>
typedef int Elemetype;
typedef struct SqQueue/*front����ָ���ͷԪ�ص�ǰһλ��*//*��β���룬����ɾ��*//*�ǻ��ζ���*/
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
���ζ��У�������βָ�룬���ٷ�һ��Ԫ�أ���ʼfront,rearΪ0
�ӿ�������front == rear
����������front ==��rear+1��% MAXSIZE 
���ӣ�rear = ��rear+1��%Maxsize
���ӣ�front = ��front+1��%Maxsize
*/
/*
Version2
���ζ��У���������βָ�룬���Ԫ�ظ���ΪMAXSIZE��Ԫ�ظ�������MAXSIZE
�ӿ�������count == 0
����������count == MAXSIZE
count = ��rear-front+MAXSIZE��%MAXSIZE
rear = ��front+count��%MAXSIZE
front = ��rear-count+MAXSIZE��%MAXISIZE
���ӣ�rear = ��rear+1��%Maxsize
���ӣ�front = ��front+1��%Maxsize
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
