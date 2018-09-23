#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int arr[maxn], dp[maxn][105];
int t, n;
int solve (int i, int val) {
	if (i == n) {
		return 0;
	}
	if (dp[i][val] != -1) {
		return dp[i][val];
	}
	int res = 0;
	if (i == 0) {
		res = max (solve (i + 1, 1), solve (i + 1, arr[i]));
	}
	else {
		res = max (solve (i + 1, 1) + abs (1 - val), 
			solve (i + 1, arr[i]) + abs (val - arr[i]));
	}
	dp[i][val] = res;
	return res;
}
int main () {
	scanf ("%d", &t);
	while (t--) {
		scanf ("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf ("%d", &arr[i]);
		}
		memset (dp, -1, sizeof (dp));
		printf("%d\n", solve (0, 0));
	}
	return 0;
}