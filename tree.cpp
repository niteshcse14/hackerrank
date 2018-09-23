#include<iostream>
#include<stdlib.h>
using namespace std;
struct Node
{
	int data;
	struct Node *left,*right;
};
struct Node *newNode(int data)
{
	struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
struct Node* insert(struct Node* node,int data)
{
	if(node==NULL)
	{
		return newNode(data);
	}

	if(data<node->data)
	{
		node->left=insert(node->left,data);
	}
	else
	{
		node->right=insert(node->right,data);
	}
	return node;
}
int getHeight(struct Node *node)
{
	if(node==NULL)
	{
		return 0;
	}
	else
	{
		int l=getHeight(node->left);
		int r=getHeight(node->right);
		if(l>r)
		{
			return l+1;
		}
		else
		{
			return r+1;
		}
	}
}
void inorder(struct Node *node)
{
	if(node!=NULL)
	{
		inorder(node->left);
		cout<<node->data<<" ";
		inorder(node->right);
	}
}
void topView(struct Node *node)
{
	if(node!=NULL)
	{
		inorder(node->left->left);
		cout<<node->data<<" ";
		inorder(node->right->right);
	}
}
int main()
{
	struct Node *root=NULL;
	root=insert(root,3);
	insert(root,5);
	insert(root,1);
	insert(root,9);
	insert(root,2);
	insert(root,4);
	insert(root,7);
	insert(root,8);

	inorder(root);
	cout<<endl;
	topView(root);
	cout<<endl;
	cout<<getHeight(root)<<endl;
}