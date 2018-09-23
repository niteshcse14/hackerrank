#include <bits/stdc++.h>
using namespace std;
const int MAXN = 101;
int arr[MAXN];
int cnt, sum;
int main()
{
	//freopen("input.txt", "r", stdin);
	int T, N, data;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &N);
		for(int i = 0; i < N; i++)
		{
			scanf("%d", &arr[i]);
		}
		sum = 0;
		cnt = N;
		while(1)
		{
			//printf("Hello\n");
			cnt = 0;
			long long s = 0;
			for(int i = 0; i < N; i++)
			{
				if(arr[i])
				{
					cnt++;
					s += arr[i];
				}
			}
			if(cnt == 2)
			{
				if(s % 2 == 0)
				{
					sum += 0;
				}
				else
				{
					sum += 1;
				}
				break;
			}
			for(int i = 0; i < N; i++)
			{
				if(arr[i] > 0)
				{
					if(cnt > 2)
					{
						arr[i] = 0;
					}
					else
					{
						if(cnt == 1)
						{
							arr[i] = 0;
						}
						else
						{
							arr[i] -= 1;
						}
					}
					sum++;
				}
				if(arr[i] == 0)
				{
					cnt++;
				}
			}
			if(cnt == N)
			{
				break;
			}
		}
		if(sum % 2 == 0)
		{
			printf("First\n");
		}
		else
		{
			printf("Second\n");
		}
	}
}