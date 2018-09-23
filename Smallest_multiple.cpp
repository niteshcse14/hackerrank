#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	int T, N, count = 0;
	int arr[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37 };
	cin >> T;
	while(T--)
	{
		count = 0;
		cin >> N;
		for(int i = 0; i < 12; i++)
		{
			if(arr[i] <= N)
			{
				count++;
			}
		}
		ll ans = 1;
		int j = 0;
		cout << "count " << count << "\n";
		for(int i = count - 1; i > 0; i--)
		{
			ans *= pow(arr[j], i);
			j++;
		}
		ans *= arr[j];
		if(ans % N != 0)
		{
			ans *= N;
		}
		cout << ans << "\n";
	}
	return 0;
}
//Smallest_multiple.cpp