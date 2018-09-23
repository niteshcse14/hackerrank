#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, data;
	cin>>N;
	int arr[N] = { 0 };
	for(int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	int MN = 1234567890;
	sort(arr, arr + N);
	for(int i = 0; i < N - 1; i++)
	{
		if(MN > abs(arr[i + 1] - arr[i]))
		{
			MN = abs(arr[i + 1] - arr[i]);
		}
	}
	cout << (MN) << "\n";
    return 0;
}
//Minimum_Absolute_Difference_in_an_Array.cpp