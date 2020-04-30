#include<malloc.h>
#include<iostream>
typedef char Elemetype;
typedef struct Linknode
{
	Elemetype data;
	Linknode * next;
}Lnode;
void init_stack(Lnode *& L)/*带头结点的链栈*/
{
	L = (Lnode*)malloc(sizeof(Lnode));
	L->next = NULL;
}
void push(Lnode *L, Elemetype e)
{
	Lnode *s = (Lnode*)malloc(sizeof(Lnode));
	s->next = L->next;
	L->next = s;
	s->data = e;
}
bool pop(Lnode *&L, Elemetype *e)
{
	Lnode *p;
	if (L->next == NULL)
	{
		return false;
	}
	p = L->next;
	*e = p->data;
	L->next = p->next;
	free(p);
	return true;
}
void destory(Lnode *&L)/*销毁所有的存储空间*/
{
	Lnode *p, *q;
	p = L;
	q = p->next;
	while (q != NULL)
	{
		free(p);
		p = q;
		q = p->next;
	}
	free(p);
}
bool check_empty(Lnode *L)
{
	return L->next == NULL;
}
bool gettop(Lnode *L, Elemetype &e)
{
	if (L->next == NULL)
	{
		return false;
	}
	e = L->next->data;
	return true;
}
bool Match(char example[])/*判断括号是否对称*/
{
	Lnode *L;
	init_stack(L);
	bool match = true;
	int i = 0;
	char e,*p;
	while (i<strlen(example)&&match)
	{
		if (example[i] == '(')
		{
			push(L, example[i]);
		}
		else if (example[i]==')')
		{
			if (gettop(L,e) == true)
			{
				if (e != '(')
				{
					match = false;
				}
				else
				{
					pop(L, p);
				}
			}
			else
			{
				match = false;
			}
		}
		i++;
	}
	if (check_empty(L) != true )
	{
		match = false;
	}
	destory(L);
	return match;
}
