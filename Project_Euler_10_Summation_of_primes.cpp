#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	vector<ll> arr;
	arr.push_back(1);
	for(int i = 1; i < 1000000; i++)
	{
		arr.push_back(1);
	}
	for(int i = 2; i < 1000000; i++)
	{
		if(arr[i] == 1)
		{
			for(int j = 2 * i; j < 1000000; j += i)
			{
				arr[j] = 0;
			}
		}
	}
	int j = 0;
	vector<ll> prime(1000000, 0);
	for(int i = 1; i < 1000000; i++)
	{
		if(arr[i] == 1)
		{
			prime[j] = i;
			j++;
		}
	}
	vector<ll> prime_sum(prime.size(), 0);
	ll sum = 0;
	for(int i = 0; i < prime.size(); i++)
	{
		prime_sum[i] = sum + prime[i];
		sum = prime_sum[i];
	}
	int T, N;
	cin >> T;
	while(T--)
	{
		cin >> N;
		ll ans = 0;
		for(int i = 0; i < j; i++)
		{
			if(prime[i] > N)
			{
				break;
			}
			else
			{
				ans = prime_sum[i];
			}
		}
		cout << (ans - 1) << "\n";
	}
	return 0;
}
//Project_Euler_10_Summation_of_primes.cpp