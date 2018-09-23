#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll maxn = 1e6 + 5;
ll t, n, a, b, c, ans;
typedef pair < ll, ll > PII;
vector < PII > adj[maxn];
ll arr[maxn], cost[maxn];
int visited[maxn];
ll dfs (ll u, ll pre = -1, ll tot = 0) {
	ll res = tot;
	vector < PII > :: iterator itr;
	for (itr = adj[u].begin(); itr != adj[u].end(); ++itr) {
		if (pre != (*itr).first) {
			res += dfs ((*itr).first, u, tot + (*itr).second);
		}
	}
	return res;
}
int main () {
	memset (arr, 0, sizeof (arr));
	memset (visited, 0, sizeof (visited));
	scanf ("%lld", &n);
	for (ll i = 0; i < n - 1; ++i) {
		scanf ("%lld%lld%lld", &a, &b, &c);
		adj[a].push_back(make_pair(b, c));
		adj[b].push_back(make_pair(a, c));
	}
	ll a1 = dfs (1);
	ll a2 = dfs (n);
	printf("%lld\n", min (a1, a2));
	return 0;
}