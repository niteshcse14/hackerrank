#include <bits/stdc++.h>
using namespace std;
int test, n, ctr, cur, mx, k;
string s, t;
int main() {
	scanf("%d", &test);
	while (test--) {
		mx = 0;
		scanf("%d", &k);
		cin >> s >> t;
		n = s.size();
		for (int resvered = 0; resvered < 2; ++resvered) {
			if (resvered) swap(s, t);
			for (int i = 0; i < n; ++i) {
				ctr = 0;
				cur = 0;
				for (int j = 0; i + ctr < n; ++j) {
					//printf("j  %d %d\n", j, ctr);
					while (cur <= k && i + ctr < n) {
						cur += (s[ctr] != t[i + ctr]);
						ctr++;
					}
					if (cur > k){
						ctr--;
						cur--;
					}
					mx = max(mx, ctr - j);
					cur -= (s[j] != t[j + i]);
				}
			}
		}
		printf("%d\n", mx);
	}
	return 0;
}