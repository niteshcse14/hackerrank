#include <bits/stdc++.h>
using namespace std;
bool isPrime[10000001];
void init()
{
	for(int i = 2; i <= 10000000; i++)
	{
		isPrime[i] = true;
	}
	for(int factor = 2; factor * factor <= 10000000; factor++)
	{
		if(isPrime[factor])
		{
			for(int j = factor; j * factor <= 10000000; j++)
			{
				isPrime[j * factor] = false;
			}
		}
	}
}
int main()
{
	init();
	int T, N;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &N);
		int arr[N], ans = 0, count;
		for(int i = 0; i < N; i++)
		{
			count = 0;
			scanf("%d", &arr[i]);
			if(isPrime[arr[i]])
			{
				count = 1;
			}
			else
			{
				for(int j = 2; j <= arr[i]; j++)
				{
					if(isPrime[j])
					{
						if(arr[i] % j == 0)
						{
							arr[i] /= j;
							j -= 1;
							count++;
						}
					}
				}
			}
			ans ^= count;
		}
		if(ans != 0)
		{
			printf("1\n");
		}
		else
		{
			printf("2\n");
		}
	}
	return 0;
} 