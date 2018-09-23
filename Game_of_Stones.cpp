#include <bits/stdc++.h>
using namespace std;
#define MAX 100000
int dp[MAX];
void init()
{
	dp[0] = dp[1] = 0;
	dp[2] = dp[3] = dp[4] = dp[5] = 1;
	for(int i = 6; i < MAX; i++)
	{
		if(!dp[i - 2] || !dp[i - 3] || !dp[i - 5])
		{
			dp[i] = 1;
		}
	}
}
int main()
{
	init();
	int T, N, count, div;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d",&N);
		if(dp[i])
		{
			printf("First\n");
		}
		else
		{
			printf("Second\n");
		}
	}
	return 0;
}