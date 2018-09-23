#include <bits/stdc++.h>
using namespace std;
const int maxn = 5 * 1e4 + 5;
typedef long long int ll;
ll arr[maxn];
ll t, n, sum, max_so_far;
int main () {
	scanf ("%lld", &t);
	while (t--) {
		sum = 0;
		max_so_far = 0;
		scanf ("%lld", &n);
		for (int i = 0; i < n; ++i) {
			scanf ("%lld", &arr[i]);
		}
		for (int  i = n - 1; i >= 0; --i) {
			if (arr[i] > max_so_far) {
				max_so_far = arr[i];
			}
			sum += max_so_far - arr[i];
		}
		printf("%lld\n", sum);
	}
	return 0;
}