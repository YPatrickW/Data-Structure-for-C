#define Maxsize 100
#include<iostream>
typedef struct string/*˳��*/
{
	char data[Maxsize];/*����ַ���*/
	int length;
}SqString;
typedef struct Lnode/*�ڵ��СΪ1������*/
{
	char data;
	struct Lnode *next;
}LiString;
int Strcmp(SqString s, SqString t)/*�ַ�����С�Ƚ�*/
{
	int comlen;
	if (s.length < t.length) comlen = s.length;
	else comlen = t.length;
	for (int i = 0;i < comlen;i++)/*��ͬ��������Ƚ�*/
	{
		if (s.data[i] > t.data[i])
			return 1;
		else if (s.data[i] < t.data[i])
			return -1;
	}
	if (s.length == t.length)
		return 0;
	else if (s.length > t.length)
		return 1;
	else return -1;
}
void Change(LiString *& S)/*��"ab"�滻Ϊ"xyz"*/
{
	LiString *fast = S->next, *slow = S,*temp;
	while (fast->next != NULL)
	{
		if (fast->data=='b'&&slow->data=='a')
		{
			fast->data = 'z';slow->data = 'x';
			temp = (LiString*)malloc(sizeof(LiString));
			temp->data = 'y';temp->next = slow->next;
			slow->next = temp;
			break;
		}
		else
		{
			fast = fast->next;
			slow = slow->next;
		}
	}
}
/*����ƥ��*/
/*ģʽƥ��*/
int index(SqString s, SqString t)
{
	int i = 0, j = 0;
	while (i < s.length && j < s.length)
	{
		if (s.data[i] == t.data[i])
		{
			i++;j++;
		}
		else
		{
			i = i - j + 1;
			j = 0;
		}
	}
	if (j >= t.length)
		return i - t.length;
	else
		return -1;
}
