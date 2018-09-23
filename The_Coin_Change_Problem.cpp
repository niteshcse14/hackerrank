#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	ll t = 1, N, K;
	//cin >> t;
	while(t--)
	{
		cin >> K >> N;
		ll arr[N], T[N + 1][K + 1];
		for(ll i = 0; i < N; i++)
		{
			cin >> arr[i];
		}
		for(ll i = 0; i <= N; i++)
		{
			T[i][0] = 1;
		}
		for(ll i = 1; i <= K; i++)
		{
			T[0][i] = 0;
		}
		
		for(ll i = 1; i <= N; i++)
		{
			for(ll j = 1; j <= K; j++)
			{
				if(j >= arr[i - 1])
				{
					T[i][j] = T[i - 1][j] + T[i][j - arr[i - 1]];
				}
				else
				{
					T[i][j] = T[i - 1][j];
				}
			}
		}
		cout << T[N][K] << "\n";
	}
	return 0;
}
//The_Coin_Change_Problem.cpp