#include <bits/stdc++.h>
using namespace std;
int const maxn = 100009;
vector < int > adj[maxn];
int n;
int wt[maxn];
int wt_sum[maxn];
int visited[maxn];
int dfs(int u){
	if(visited[u] == 1){
		return 0;
	}
	if(adj[u].size() == 1){
		wt_sum[u] = wt[u];
		visited[u] = 1;
		return wt_sum[u];
	}
	else{
		vector < int > :: iterator itr;
		int sum = wt[u];
		visited[u] = 1;
		for(itr = adj[u].begin(); itr != adj[u].end(); itr++){
			sum += dfs(*itr);
		}
		wt_sum[u] = sum;
		return wt_sum[u];
	}
} 
int main(){
	int u, v;
	scanf("%d", &n);
	int total = 0;
	for(int i = 1; i <= n; ++i){
		scanf("%d", &wt[i]);
		total += wt[i];
	}
	for(int i = 0; i < n - 1; ++i){
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int root = -1;
	for(int i = 1; i <= n; ++i){
		if(adj[i].size() > 1){
			root = i;
			break;
		}
	}
	for(int i = 1 ; i<= n; ++i){
		wt_sum[i] = visited[i] = 0;
	}
	int c = dfs(root);
	int mn = INT_MAX;
	for(int i = 1; i <= n; ++i){
		mn = min(mn, abs(total - 2 * wt_sum[i]));
	}
	printf("%d\n", mn);
	return 0;
}