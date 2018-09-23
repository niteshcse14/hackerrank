#include <bits/stdc++.h>
using namespace std;
int const MAX = 5005;
vector<int> adj[MAX];
int N, u, v, node1, node2, center1, center2, max_count = 0;
pair<int, int> dfs(int v, int count, bool visited[])
{
	visited[v] = true;
	vector<int>::iterator itr;
	for(itr = adj[v].begin(); itr != adj[v].end(); itr++)
	{
		if(!visited[*itr])
		{
			dfs(*itr, count + 1, visited);
		}
	}
	if(max_count < count)
	{
		node1 = v;
		max_count = count;
	}
	return make_pair(node1, max_count);
}
pair<int, int> dfs_length(int v, int count, bool visited[])
{
	visited[v] = true;
	vector<int>::iterator itr;
	for(itr = adj[v].begin(); itr != adj[v].end(); itr++)
	{
		if(!visited[*itr])
		{
			dfs_length(*itr, count + 1, visited);
		}
	}
	if(max_count < count)
	{
		node2 = v;
		max_count = count;
	}
	return make_pair(node2, max_count);
}
int main()
{
	scanf("%d", &N);
	bool visited[N];
	visited[0] = false;
	for(int i = 1; i < N; i++)
	{
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
		visited[i] = false;
	}
	pair<int, int> first_vertex = dfs(0, 0, visited);
	for(int i = 0; i < N; i++)
	{
		visited[i] = false;
	}
	max_count = 0;
	pair<int, int> second_vertex = dfs_length(first_vertex.first, 0, visited);
	printf("%d  %d\n", first_vertex.first, first_vertex.second);
	printf("%d  %d\n", second_vertex.first, second_vertex.second);
	return 0;
}