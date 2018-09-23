#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll t, a, b, x;
int main () {
	scanf ("%lld", &t);
	while (t--) {
		scanf ("%lld%lld%lld", &a, &b, &x);
		ll res = 0;
		res = 1LL * pow(a, b);
		ll temp = (res - res % x);
		ll temp1 = temp + x;
		if (b < 0) {
			if (x == 1) {
				printf("1\n");
			}
			else {
				printf("0\n");
			}
		}
		else if (abs (res - temp) < abs (res - temp1)) {
			printf("%lld\n", temp);
		}
		else {
			printf("%lld\n", temp1);
		}
	}
	return 0;
}