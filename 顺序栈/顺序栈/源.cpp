#include<iostream>
#define Maxsize 100
typedef int Elemtype;
typedef struct stack
{
	Elemtype data[Maxsize];
	int top;
}Sqstack;
void init_stack(Sqstack*& S)
{
	S = (Sqstack*)malloc(sizeof(Sqstack));
	S->top = -1;
}
bool push(Sqstack* S, Elemtype e)
{
	if (S->top == Maxsize-1)
	{
		return false;
	}
	else
	{
		S->top++;
		S->data[S->top] = e;
		return true;
	}
}
void Destory_stack(Sqstack *& S)
{
	free(S);
}
bool pop(Sqstack *S, Elemtype *e)
{
	if (S->top == -1)
	{
		return false;
	}
	else
	{
		*e = S->data[S->top];
		S->top--;
		return true;
	}
}
bool gettop(Sqstack *S, Elemtype *e)
{
	if (S->top ==-1)
	{
		return false;
	}
	else
	{
		*e = S->data[S->top];
		return true;
	}
}
bool check_string(Elemtype str[])
{
	int i = 0;
	Sqstack*S;
	Elemtype *e;
	init_stack(S);
	for ( i = 0; str[i]!= '\0' ; i++)
	{
		push(S, str[i]);
	}
	for (int j = 0; str[j]!='\0'; i++)
	{
		pop(S, e);
		if (*e!=str[j])
		{
			Destory_stack(S);
			return false;
		}
	}
}


