#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int u, v, n, q, ans;
vector < int > adj[maxn];
int sub[maxn], c[maxn], sz[maxn];
void dfs (int u, int prev, int color) {
	c[u] = color;
	sub[u] = 1;
	sz[color]++;
	for (int i = 0; i < adj[u].size(); ++i) {
		if (adj[u][i] != prev) {
			dfs (adj[u][i], u, color);
			sub[u] += sub[adj[u][i]];
		}
	}
}
int query (int u) {
	//
}
int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n - 1; ++i) {
		scanf ("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs (1, 0, 1);
	/*
	for (int i = 1; i <= n; ++i) {
		printf("%d ", sub[i]);
	}
	printf("\n");
	*/
	ans = 0;
	scanf ("%d", &q);
	while (q--) {
		scanf ("%d", &v);
		v ^= ans;
		ans = query (v);
		printf("%d\n", ans);
	}
	return 0;
}