#include<iostream>
typedef int Elemetype;
typedef struct DataNode/*数据节点*/
{
	Elemetype Data;
	DataNode *next;
}Dnode;
typedef struct/*头结点*/
{
	Dnode *front;
	Dnode *rear;
}Liqueue;
void Init_queue(Liqueue *&Q)/*初始化队列只创造头结点*/
{
	Q = (Liqueue*)malloc(sizeof(Liqueue));
	Q->front = Q->rear = NULL;
}
void Destory_queue(Liqueue *&Q)/*快慢指针*/
{
	Dnode *p = Q->front, *q;
	if (p!= NULL)
	{
		q = p->next;
		while (q != NULL)
		{
			free(p);
			p = q;
			q = p->next;
		}
	}
	free(p);free(Q);
}
bool check_empty(Liqueue *Q)/*判断队列是否是空*/
{
	return Q->rear == NULL;
}
void push(Liqueue *&Q, Elemetype e)
{
	Dnode *d = (Dnode*)malloc(sizeof(Dnode));
	d->Data = e;
	d->next = NULL;
	if (Q->rear == NULL)/*队列为空*/
	{
		Q->rear = Q->front = d;
	}
	else/*队列不为空*/
	{
		Q->rear->next = d;
		Q->rear = d;
	}
}
bool pop(Liqueue*&Q, Elemetype &e)
{
	Dnode *temp = Q->front;
	if (Q->front == NULL)/*空队列*/
	{
		return false;
	}
	else if (Q->front == Q->rear)/*只有一个数据结点的队列*/
	{
		Q->front = Q->rear = NULL;
	}
	else/*多个数据结点*/
	{
		Q->front = Q->front->next;
	}
	e = temp->Data;
	free(temp);
	return true;
}
/*创建一个不包含头结点的且只包含尾结点的循环队列*/
typedef struct
{
	Dnode *rear;
}Rear;
void inti_Rqueue(Rear *&Q)
{
	Q->rear = NULL;
}
bool check_empty(Rear *Q)
{
	return Q->rear == NULL;
}
void push(Rear *&Q, Elemetype e)
{
	Dnode *s = (Dnode*)malloc(sizeof(Dnode));
	s->Data = e;
	if (Q->rear == NULL)/*队列为空*/
	{
		s->next = s;
		Q->rear = s;
	}
	else
	{
		s->next = Q->rear->next;
		Q->rear->next = s;
		Q->rear = s;
	}
}
bool pop(Rear*&Q, Elemetype &e)
{
	if (Q->rear == NULL)/*队列为空*/
	{
		return false;
	}
	else if (Q->rear->next == Q->rear )/*只有一个数据结点的队列*/
	{
		e = Q->rear->Data;
		free(Q);Q->rear = NULL;
	}
	else/*多个数据结点*/
	{
		Dnode *temp = Q->rear->next;
		e = temp->Data;
		Q->rear->next = temp->next;
		free(temp);
	}
}