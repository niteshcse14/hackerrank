#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	ll T, N, ans;
	cin >> T;
	while(T--)
	{
		ans = 0;
		cin >> N;
		for(ll i = 1; i <= sqrt(N); i++)
		{
			if(N % i == 0)
			{
				if(i * i == N)
				{
					ans++;
				}
				else
				{
					ans += 2;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
//Count_the_Divisors.cpp