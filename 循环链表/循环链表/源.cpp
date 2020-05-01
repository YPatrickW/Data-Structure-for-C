#include<iostream>
using namespace std;
typedef int Elementype;
typedef struct SNode
{
	Elementype data;
	struct SNode *next;
}SCnode,*Linklist;
typedef struct DNode
{
	Elementype data;
	struct DNode *prior;
	struct DNode *next;
}DCnode,*DLinklist;
void tail_creat(Linklist &L, Elementype a[], int n)/*循环单链表de*/
{
	L = (Linklist)malloc(sizeof(SCnode));
	L->next = NULL;
	Linklist r = L,s;
	for (int i = 0; i < n; i++)
	{
		s = (Linklist)malloc(sizeof(SCnode));
		s->data = a[i];
		r->next = s;
		r = s;
	}
	r->next = L;
}
void merge(Linklist L1, Linklist L2)/*带头结点的单链表合并*/
{
	Linklist P1 = L1, P2 = L2;
	Linklist temp;
	while (P1->next!=L1)
	{
		P1 = P1->next;/*找尾结点*/
	}
	while (P2->next!=L2)
	{
		P2 = P2->next;/*找尾结点*/
	}
	temp = P1->next;
	P1->next = P2->next->next;
	P2->next = temp;
	free(temp);
}
void tail_creatD(DLinklist &L, Elementype a[], int n)/*循环双链表的建立*/
{
	L = (DLinklist)malloc(sizeof(DNode));
	L->next = NULL;
	L->prior = NULL;
	DLinklist r = L;
	DLinklist s;
	for (int i = 0; i < n; i++)
	{
		s = (DLinklist)malloc(sizeof(DNode));
		s->data = a[i];
		r->next = s;
		s->prior = r;
		r = s;
	}
	r->next = L;
	L->prior = r;
}
void check_symmetry(DLinklist L)/*检查是否对称*/
{
	DLinklist r = L;/*第二种方法：DLinklist r = L->prior*/
	DLinklist s = L->next;
	int same = 1;
	while (r->next != L)/*第二种方法不用遍历*/
	{
		r = r->next;
	}
	while (same==1)
	{
		if (s->data != r->data)
		{
			same = 0;
		}
		else
		{
			if (s==r||s->next==r)
			{
				break;
			}
			s = s->next;
			r = r->prior;
		}
	}
}