#include <bits/stdc++.h>
using namespace std;
int main () {
	scanf ("%d%d", &n, &k);
	for (int i = 0; i < n - 1; ++i) {
		scanf ("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	return 0;
}