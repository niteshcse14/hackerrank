#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll maxn = 1e2 + 5;
int n, t;
int arr[maxn];
int g_cnt[maxn];
int gcd(int a, int b) {
	if(a == 0) {
		return b;
	}
	return gcd(b % a, a);
}
ll prev(int n) {
	memset(arr, 0, sizeof(arr));
	memset(g_cnt, 0, sizeof(g_cnt));
	ll res = 1;
	int j = 0;
	for(int i = n; i > 1; --i) {
		if(res % i != 0) {
			res *= i;
			arr[j++] = i;
		}
	}
	for (int i = 0; i < j; ++i) {
		for (int k = 0; k < j; ++k) {
			if(i != k) {
				int g = gcd(arr[i], arr[k]);
				g_cnt[g]++;
			}
		}
	}
	for(int i = 2; i < n; ++i) {
		if(g_cnt[i] > 1) {
			res /= i * (g_cnt[i] - 1);
		}
	}
	return res;
}
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		printf("%lld\n", prev(n));
	}
	return 0;
}