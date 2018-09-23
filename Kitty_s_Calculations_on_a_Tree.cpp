#include <bits/stdc++.h>
using namespace std;
#define ll long long int
class Kitty
{
	vector<int> *adj;
	int V;
public:
	Kitty(int V);
	void addEdges(int v, int u);
	int num_of_edges(int v, int u);
};
Kitty::Kitty(int V)
{
	this->V = V;
	adj = new vector<int>[V];
}
void Kitty::addEdges(int v, int u)
{
	adj[v].push_back(u);
	adj[u].push_back(v);
}
int Kitty::num_of_edges(int v, int u)
int main()
{
	//
	return 0;
}
//Kitty_s_Calculations_on_a_Tree.cpp