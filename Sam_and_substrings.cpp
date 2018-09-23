#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int mod = 1e9 + 7;
#define maxn 2000010
int n;
ll sum, res, num;
ll sum_[maxn];
char str[maxn];
int main() {
	scanf ("%s", str);
	n = strlen (str);
	res = str[0] - '0';
	sum_[0] = res;
	for (int i = 1; i < n; ++i) {
		num = str[i] - '0';
		sum_[i] = ((i + 1) * num % mod+ 10 * sum_[i - 1] % mod + mod) % mod;
		res = (res + sum_[i]) % mod;
	}
	printf("%lld\n", res % mod);
	return 0;
}