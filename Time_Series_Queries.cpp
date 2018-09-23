#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int arr_price[MAXN];
int arr_time[MAXN];
int N, Q, type, v;
struct node
{
	int tt;
	int pp;
	node *left;
	node *right;
	node(){}
	node(node *l, node *r, int t, int p){
		left = l;
		right = r;
		tt = t;
		pp = p;
	}
};
/*
void build_price(node *n, int ss, int se)
{
	if(ss == se)
	{
		n->time = time[ss];
		n->price = price[ss];
		return;
	}
	int mid = (ss + se) / 2;
	n->left = new node(NULL, NULL, 0, 0);
	n->right = new node(NULL, NULL, 0, 0);
	build_price(n->left, ss, mid);
	build_price(n->right, mid + 1, se);
	if(n->left->price > n->right->price){
		n->price = n->left->price;
		n->time = n->left->time;
	}
	else{
		n->price = n->right->price;
		n->time = n->right->price;
	}
}
*/
void build(node *n, int ss, int se)
{
	if(ss == se)
	{
		n->tt = arr_time[ss];
		n->pp = arr_price[ss];
		return;
	}
	int mid = (ss + se) / 2;
	n->left = new node(NULL, NULL, 0, 0);
	n->right = new node(NULL, NULL, 0, 0);
	build(n->left, ss, mid);
	build(n->right, mid + 1, se);
	if(n->left->tt > n->right->tt){
		n->pp = n->left->pp;
		n->tt = n->left->tt;
	}
	else{
		n->pp = n->right->pp;
		n->tt = n->right->tt;
	}
}
int main()
{
	scanf("%d %d", &N, &Q);
	for(int i = 1; i <= N; ++i){
		scanf("%d", arr_time + i);
	}
	for(int i = 1; i <= N; ++i){
		scanf("%d", arr_price + i);
	}
	//node *root_time = new node(NULL, NULL, 0, 0);
	node *root = new node(NULL, NULL, 0, 0);
	build(root, 1, N);
	//build_time(root_time, 1, N);
	while(Q--){
		scanf("%d %d", &type, &v);
	}
	return 0;
}