#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll maxn = 1e6 + 5;
ll t, n, sum, data;
ll cnt[maxn];
int main () {
	scanf ("%lld", &t);
	while (t--) {
		memset (cnt, 0, sizeof (cnt));
		scanf ("%lld", &n);
		for (ll i = 0; i < n; ++i) {
			scanf ("%lld", &data);
			cnt[data]++;
		}
		sum = 0;
		for (ll i = 0; i < maxn; ++i) {
			sum += cnt[i] * (cnt[i] - 1);
		}
		printf("%lld\n", sum);
	}
	return 0;
}