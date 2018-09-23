#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
string str;
int t, n;
void solve (int i, string ans) {
	cout << ans << "\n";
	for (int j = i; j < n; ++j) {
		solve (j + 1, ans + str[j]);
	}
}
int main () {
	scanf ("%d", &t);
	while (t--) {
		scanf ("%d", &n);
		cin >> str;
		string s = "";
		for (int i = 0; i < n; ++i) {
			solve (i + 1, s + str[i]);
		}
	}
	return 0;
}