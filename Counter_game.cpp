#include <bits/stdc++.h>
using namespace std;
int count_bit(unsigned long long int N)
{
	int count = 0;
	while(N)
	{
		N &= (N - 1);
		count++;
	}
	return count;
}
int main()
{
	int T;
	scanf("%d\n", &T);
	while(T--)
	{
		unsigned long long int N;
		scanf("%llu\n", &N);
		if(count_bit(N - 1) & 1)
		{
			printf("Louise\n");
		}
		else
		{
			printf("Richard\n");
		}
	}
	return 0;
}