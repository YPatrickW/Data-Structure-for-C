#include<iostream>
typedef int Elemetype;
typedef struct DataNode/*���ݽڵ�*/
{
	Elemetype Data;
	DataNode *next;
}Dnode;
typedef struct/*ͷ���*/
{
	Dnode *front;
	Dnode *rear;
}Liqueue;
void Init_queue(Liqueue *&Q)/*��ʼ������ֻ����ͷ���*/
{
	Q = (Liqueue*)malloc(sizeof(Liqueue));
	Q->front = Q->rear = NULL;
}
void Destory_queue(Liqueue *&Q)/*����ָ��*/
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
bool check_empty(Liqueue *Q)/*�ж϶����Ƿ��ǿ�*/
{
	return Q->rear == NULL;
}
void push(Liqueue *&Q, Elemetype e)
{
	Dnode *d = (Dnode*)malloc(sizeof(Dnode));
	d->Data = e;
	d->next = NULL;
	if (Q->rear == NULL)/*����Ϊ��*/
	{
		Q->rear = Q->front = d;
	}
	else/*���в�Ϊ��*/
	{
		Q->rear->next = d;
		Q->rear = d;
	}
}
bool pop(Liqueue*&Q, Elemetype &e)
{
	Dnode *temp = Q->front;
	if (Q->front == NULL)/*�ն���*/
	{
		return false;
	}
	else if (Q->front == Q->rear)/*ֻ��һ�����ݽ��Ķ���*/
	{
		Q->front = Q->rear = NULL;
	}
	else/*������ݽ��*/
	{
		Q->front = Q->front->next;
	}
	e = temp->Data;
	free(temp);
	return true;
}
/*����һ��������ͷ������ֻ����β����ѭ������*/
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
	if (Q->rear == NULL)/*����Ϊ��*/
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
	if (Q->rear == NULL)/*����Ϊ��*/
	{
		return false;
	}
	else if (Q->rear->next == Q->rear )/*ֻ��һ�����ݽ��Ķ���*/
	{
		e = Q->rear->Data;
		free(Q);Q->rear = NULL;
	}
	else/*������ݽ��*/
	{
		Dnode *temp = Q->rear->next;
		e = temp->Data;
		Q->rear->next = temp->next;
		free(temp);
	}
}