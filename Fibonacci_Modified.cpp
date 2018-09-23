#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	ll t1, t2, N;
	cin >> t1 >> t2 >> N;
	ll arr[N + 2];
	arr[1] = t1;
	arr[2] = t2;
	for(int i = 3; i <= N; i++)
	{
		arr[i] = arr[i - 2] + arr[i - 1] * arr[i - 1];
	}
	cout << arr[N] << "\n";
	return 0;
}
//Fibonacci_Modified.cpp