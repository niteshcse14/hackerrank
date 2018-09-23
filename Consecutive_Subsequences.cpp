#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll t, n, k, sum, data;
ll prefix[105], ans;
int main () {
	scanf ("%lld", &t);
	while (t--) {
		memset (prefix, 0, sizeof (prefix));
		sum = 0;
		ans = 0;
		scanf ("%lld%lld", &n, &k);
		prefix[0] = 1;
		for (ll i = 1; i <= n; ++i) {
			scanf ("%lld", &data);
			sum = (sum + data) % k;
			prefix[sum]++;
		}
		for (ll i = 0; i < k; ++i) {
			if (prefix[i] > 1) {
                prefix[i] = prefix[i] * (prefix[i] - 1);
			    ans += prefix[i] / 2;
            }
		}
		printf("%lld\n", ans);
	}
	return 0;
}