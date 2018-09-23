#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll N, a, b;
	scanf("%lld", &N);
	for(int i = 0; i < N; i++)
	{
		scanf("%lld %lld", &a, &b);
		ll bit_diff = (ll)log2(a ^ b) + 1;
		b = b >> bit_diff;
		printf("%lld\n", (b << bit_diff));
		//printf("%lld     %lld\n", a ^ b, (ll)log2(a ^ b));
		/*
		printf("%lld\n", (a & ~((1 << (ll)log2(a ^ b)) - 1)));
		*/
	}
	return 0;
}