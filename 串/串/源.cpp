#define Maxsize 100
#include<iostream>
typedef struct string/*顺序串*/
{
	char data[Maxsize];/*存放字符串*/
	int length;
}SqString;
typedef struct Lnode/*节点大小为1的链串*/
{
	char data;
	struct Lnode *next;
}LiString;
int Strcmp(SqString s, SqString t)/*字符串大小比较*/
{
	int comlen;
	if (s.length < t.length) comlen = s.length;
	else comlen = t.length;
	for (int i = 0;i < comlen;i++)/*共同长度里面比较*/
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
void Change(LiString *& S)/*将"ab"替换为"xyz"*/
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
/*串的匹配*/
/*模式匹配*/
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
