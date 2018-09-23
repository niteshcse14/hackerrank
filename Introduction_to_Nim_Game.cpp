#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T, N, ans, sum;
	scanf("%d", &T);
	while(T--)
	{
		sum = 0;
		scanf("%d", &N);
		for(int i = 0; i < N; i++)
		{
			scanf("%d", &ans);
			sum ^= ans;
		}
		if(sum == 0)
		{
			printf("Second\n");
		}
		else
		{
			printf("First\n");
		}
	}
	return 0;
}