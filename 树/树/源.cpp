#include<iostream>
#include<cstdio>
using namespace std;
typedef char ElemeType;
typedef struct Node
{
	ElemeType data;
	struct Node *lchild, *rchild;/*���Һ��ӽ��*/
}Node, *BiTree;
void Preorder(BiTree T)/*ǰ�����*//*������*/
{
	if (T == NULL) return;
	cout <<T->data << endl;
	Preorder(T->lchild);
	Preorder(T->rchild);
}
void Inorder(BiTree T)/*�������*//*�����*/
{
	if (T == NULL) return;
	Inorder(T->lchild);
	cout << T->data << endl;
	Inorder(T->rchild);
}
void Postorder(BiTree T)/*�������*//*���Ҹ�*/
{
	if (T == NULL) return;
	Postorder(T->lchild);
	Postorder(T->rchild);
	cout << T->data << endl;
}
void CreatTree(BiTree &T)/*ǰ����*/
{
	ElemeType data;
	cout << "����" << endl;
	cin >>data;
	if (data == '#')/*��#��ʾ������*/
	{
		T = NULL;
	}
	else
	{
		T = (BiTree)malloc(sizeof(Node));
		T->data = data;
		CreatTree(T->lchild);
		CreatTree(T->rchild);
	}
}
