#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<malloc.h>
using namespace std;
typedef int Elemtype;
typedef struct Dnode
{
	Elemtype data;
	struct Dnode *prior;
	struct Dnode *next;
}Dnode,* Dlinklist;
void head_creat(Dlinklist &L,Elemtype a[],int n)
{
	L = (Dlinklist)malloc(sizeof(Dnode));
	Dlinklist s;
	L->next = L->prior = NULL;
	for (int i = 0; i < n; i++)	
	{
		s = (Dlinklist)malloc(sizeof(Dnode));
		s->next = L->next;
		s->data = a[i];
		if (L->next != NULL)
		{
			L->next->prior = s;
		}
		L->next = s;
		s->prior = L;
	}
}
void tail_creat(Dlinklist &L, Elemtype a[], int n)
{
	L = (Dlinklist)malloc(sizeof(Dnode));
	Dlinklist s, r;
	r = L;
	L->next = L->prior = NULL;
	for (int i = 0; i < n; i++)
	{
		s = (Dlinklist)malloc(sizeof(Dnode));
		s->data = a[i];
		r->next = s;/*зЂвт*/
		s->prior = r;
		r = s;
	}
	r->next = NULL;
}
void reverse(Dlinklist L)
{
	Dlinklist p, t;
	p = L->next;
	L->next = NULL;
	while (p!=NULL)
	{
		t = p->next;
		p->next = L->next;
		if(L->next!=NULL)
		{
			L->next->prior = p;
		}
		L->next = p;
		p->prior = L;
		p = t;
	}
}
bool insert(Dlinklist L,int i,Elemtype e)
{
	Dlinklist p = L,s;
	int j = 0;
	while (j<i-1&&p->next!=NULL)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)
	{
		return false;
	}
	else
	{
		s = (Dlinklist)malloc(sizeof(Dnode));
		s->data = e;
		if (p->next!= NULL)
		{
			p->next->prior = s;
		}
		p->next = s;
		s->prior = p;
		return true;
	}
}
bool deleten(Dlinklist L, int n)
{
	int j = 0;
	Dlinklist p = L;
	while (j<n&&p!=NULL)
	{
		j++;
		p = p->next;
	}
	if (p==NULL)
	{
		return false;
	}
	else
	{
		if (p->next!=NULL)
		{
			p->next->prior = p->prior;
			p->prior->next = p->next;
			free(p);
		}
		return true;
	}
}
void check(Dlinklist L, int m)
{
	Dlinklist s = L;
	for (int i = 0; i <= m; i++)
	{
		cout << s->data << endl << s << endl
			<< s->next << endl
			<< s->prior << endl;
		s = s->next;
	}
}
