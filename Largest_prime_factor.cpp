#include <bits/stdc++.h>
using namespace std;
#define ll long long int
bool prime(ll n)
{
	if(n % 2 == 0 || n == 2)
	{
		return false;
	}
	for(int i = 3; i * i <= n; i += 2)
	{
		if(n % i == 0)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	ll T = 1, N;
	//cin >> T;
	while(T--)
	{
		ll i;
		cin >> N;
		i = N;
		while(1)
		{
			cout << i << endl;
			if(prime(i))
			{
				cout << i << endl;
				break;
			}
			i--;
		}
	}
	return 0;
}