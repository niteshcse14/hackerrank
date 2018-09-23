#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll MOD = 1e9 + 7;
ll arr[2001];
ll inv[2001];
ll mpow(ll a, ll N)
{
    ll res = 1;
    ll b = a;
    while(N)
    {
        if(N & 1)
        {
        	res=(res * b) % MOD;
    	}
        b =(b * b) % MOD;
        N >>= 1;
    }
    return (ll)res;
}
int main()
{
	arr[0] = 1;
	inv[0] = 1;
	for(int i = 1; i < 2001; i++)
	{
		arr[i] = i * arr[i - 1] % MOD;
		inv[i] = mpow(arr[i], MOD - 2);
	}
	int T, N, M;
	cin >> T;
	while(T--)
	{
		cin >> N >> M;
		ll ans = inv[N] * inv[M - 1] % MOD;
		cout << (arr[N + M - 1] * ans) % MOD << "\n";
	}
}
//Sherlock_and_Permutations.cpp