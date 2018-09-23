#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
ll sum, N;
int main()
{
	int Q;
	scanf("%d", &Q);
	while(Q--)
	{
		scanf("%llu", &N);
		sum = 0;
		for(int i = 0; i < 32; i++)
		{
			if((1LL << i) >= N)
			{
				break;
			}
			else
			{
				if((N & (1LL << i)) == 0 && ((1LL << i) < N))
				{
					sum += (unsigned long long int)pow(2, i);
				}
			}
		}
		printf("%llu\n", sum);
	}
	return 0;
}