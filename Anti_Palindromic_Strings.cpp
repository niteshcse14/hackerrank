#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MOD = 1e9 + 7;
const ll maxn = 1e6 + 5;
ll pre[maxn];
ll t, n, a, b;
ll power (ll a, ll b) {
	ll res = 1;
	while (b > 0) {
		if (b & 1) {
			res = (res * a) % MOD;
		}
		b >>= 1;
		a = (a * a) % MOD;
	}
	return (res + MOD) % MOD;
}
void solve () {
	pre[0] = pre[1] = 1;
	for (ll i = 2; i < maxn; ++i) {
		pre[i] = (i * pre[i - 1]) % MOD;
	}
}
int main () {
	solve ();
	scanf ("%lld", &t);
	while (t--) {
		scanf ("%lld%lld", &a, &b);
		ll t1 = pre[a - 1];
		ll t2 = pre[b];
		ll ans = (t2 * power (t1, MOD - 2)) % MOD;
		printf("%lld\n", ans);
	}
	return 0;
}