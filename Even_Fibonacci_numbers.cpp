#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll f[1000000] = { 0 };
ll fib(ll n)
{
	if(n == 0)
	{
		return 0;
	}
	if(n == 1 || n == 2)
	{
		return (f[n] = 1);
	}
	if(f[n])
	{
		return f[n];
	}
	int k = (n & 1) ? (n + 1) / 2 : n / 2;
	f[n] = (n & 1) ? (fib(k) * fib(k) + fib(k - 1) * fib(k - 1)):
			(2 * fib(k - 1) + fib(k)) * fib(k);
	return f[n];
}
int main()
{
	ll T, N;
	cin >> T;
	while(T--)
	{
		cin >> N;
		ll sum = 0;
		ll i = 0;
		while(fib(i) < N)
		{
			//cout << i << "  " << fib(i) << endl;
			if(fib(i) % 2 == 0)
			{
				sum += fib(i);
			}
			i++;
		}
		cout << sum << endl;
	}
	return 0;
}