#include<iostream>
#include<cstdio>
using namespace std;
typedef char ElemeType;
typedef struct Node
{
	ElemeType data;
	struct Node *lchild, *rchild;/*左右孩子结点*/
}Node, *BiTree;
void Preorder(BiTree T)/*前序遍历*//*根左右*/
{
	if (T == NULL) return;
	cout <<T->data << endl;
	Preorder(T->lchild);
	Preorder(T->rchild);
}
void Inorder(BiTree T)/*中序遍历*//*左根右*/
{
	if (T == NULL) return;
	Inorder(T->lchild);
	cout << T->data << endl;
	Inorder(T->rchild);
}
void Postorder(BiTree T)/*后序遍历*//*左右根*/
{
	if (T == NULL) return;
	Postorder(T->lchild);
	Postorder(T->rchild);
	cout << T->data << endl;
}
void CreatTree(BiTree &T)/*前序建树*/
{
	ElemeType data;
	cout << "输入" << endl;
	cin >>data;
	if (data == '#')/*用#表示无数据*/
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
