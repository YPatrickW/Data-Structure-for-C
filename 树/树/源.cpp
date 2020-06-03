#include<iostream>
#include<cstdio>
using namespace std;
typedef int ElemeType;
typedef struct Node
{
	ElemeType data;
	struct Node *lchild, *rchild;/*左右孩子结点*/
}Node, *BiTree;
void Preorder(BiTree T)/*前序遍历*//*根左右*/
{
	if (T == NULL) return;
	cout << T->data << endl;
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