#include <bits/stdc++.h>
using namespace std;
#define ll long long int
bool palindrome(ll mul)
{
	string str = to_string(mul);
	for(int k = 0; k < str.size() / 2; k++)
	{
		if(str[k] != str[str.size() - 1 - k])
		{
			return false;
		}
	}
	return true;
}
int main()
{
	ll T, N, flag = 0, k = 0, arr[1000000] = { 0 };
	for(int i = 100; i < 1000; i++)
	{
		for(int j = 100; j <= i; j++)
		{
			ll mul = i * j;
			if(palindrome(mul))
			{
				arr[k] = mul;
				k++;
			}
		}
	}
	sort(arr, arr + k);
	cin >> T;
	while(T--)
	{
		int end = 0;
		flag = 0;
		cin >> N;
		for(int i = k - 1; i >= 0; i--)
		{
			if(arr[i] < N)
			{
				cout << arr[i] << "\n";
				break;
			}
		}
	}
	return 0;
}
//Largest_palindrome_product.cpp