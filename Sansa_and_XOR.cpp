#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T, N;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &N);
		int arr[N], sum = 0;
		for(int i = 1; i <= N; i++)
		{
			scanf("%d", &arr[i]);
			if(((N - 1) * (i + 1)) % 2 != 0)
			{
				sum ^= arr[i];
			}
		}
		printf("%d\n",sum );
	}
	return 0;
}