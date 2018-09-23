#include<iostream>
#include<stdlib.h>
using namespace std;
struct AVL
{
	struct AVL *left=NULL,*right=NULL,*parent=NULL,*root=NULL;
	int data;
};
void insert(struct AVL *node,int data)
{
	node=(struct AVL*)malloc(sizeof(struct AVL));
	node->data=data;
	node->left=NULL;
	node->right=NULL;
	if(root==NULL)
	{
		root=node;
		return;
	}
	if(root->data<data)
	{
		node->right=insert(node->right,data);
	}
	else
	{
		node->left=insert(node->left,data);
	}
}
int main()
{
	return 0;
}