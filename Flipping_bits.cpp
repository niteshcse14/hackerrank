#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	register int T;
	unsigned int N;
	
	for(scanf("%u", &T); T; T--)
	{
		scanf("%lld", &N);
		printf("%u\n", ~N);
		//printf("%lld\n", (ll)(pow(2, 32)) - N  - 1);
	}
	return 0;
}