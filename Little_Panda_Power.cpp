#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll power(ll a, ll b, ll MOD)
{
	ll res = 1;
	while(b)
	{
		if(b & 1)
		{
			res = res * a % MOD;
		}
		a = a * a % MOD;
		b >>= 1;
	}
	return res % MOD;
}
int modInverse(int N, int MOD)
{
	int OLD_MOD = MOD, t, quotient;
	int x0 = 0, x1 = 1;

	if (MOD == 1)
	return 0;

	while (N > 1)
	{
		quotient = N / MOD;
		t = MOD;
		MOD = N % MOD;
		N = t;
		t = x0;
		x0 = x1 - quotient * x0;
		x1 = t;
	}
	if (x1 < 0)
       x1 += OLD_MOD;
 
    return x1;
}
int main()
{
	ll T, A, B, X, ans;
	cin >> T;
	while(T--)
	{
		cin >> A >> B >> X;
		if(B < 0)
		{
			B = (-1) * B;
			ll inv = modInverse(A, X);
			cout << power(inv, B, X) << "\n";
		}
		else
		{
			//cout << "ELSE\n";
			cout << power(A, B, X) << "\n";
		}
	}
	return 0;
}
//Little_Panda_Power.cpp