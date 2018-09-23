#include <bits/stdc++.h>
using namespace std;
#define maxn 1000
#define ll long long int
ll n, a, b, c;
ll inp[maxn];
int main() {
	scanf ("%lld", &n);
	for (ll i = 0; i <= n; ++i)
		scanf ("%lld", &inp[i]);
	assert (inp[0] != 0);
	if (n == 1) {
		a = -1 * (inp[0] / inp[1]);
		printf("%lld %lld\n", a, a);
	}
	else {
		c = inp[0];
		a = inp[n];
		b = inp[n - 1];
		printf("%lld %lld\n", (-1 * (b / a)), (ll)pow(-1, n) * (c / a));
	}
	return 0;
}