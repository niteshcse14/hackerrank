#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
int t, n, res;
int arr[maxn];
int gcd (int a, int b) {
	if (a == 0) return b;
	return gcd (b % a, a);
}
int main () {
	scanf ("%d", &t);
	while (t--) {
		scanf ("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf ("%d", arr + i);
		}
		res = 0;
		for (int i = 0; i < n; ++i) {
			res = gcd (res, arr[i]);
		}
		if (res == 1) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}