#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	ll N, Q, x, y;
	cin >> N;
	ll arr[N];
	for(int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	cin >> Q;
	while(Q--)
	{
		cin >> x >> y;
		x = x - 1;
		y = y - 1;
		if(x == y)
		{
			if(arr[x] % 2 == 0)
			{
				cout << "Even\n";
			}
			else
			{
				cout << "Odd\n";
			}
		}
		else
		{
			if(arr[x] % 2 == 0 && arr[x + 1] != 0)
			{
				cout << "Even\n";
			}
			else
			{
				cout << "Odd\n";
			}
		}
	}
	return 0;
}
//Even_Odd_Query.cpp