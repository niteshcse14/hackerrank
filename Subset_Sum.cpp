#include <bits/stdc++.h>
using namespace std;
int main()
{
	int N, T, sum, S = 0;
	cin >> N;
	vector<int> arr;
	for(int i = 0; i < N; i++)
	{
		cin >> arr[i];
		S += arr[i];
	}
	sor(arr, arr + N);
	cin >> T;
	while(T--)
	{
		cin >> sum;
		if(sum > S)
		{
			cout << "-1\n";
		}
		else
		{
			int flag = 0;
			S = 0;
			for(int i = 0; i < N; i++)
			{
				S += arr[i];
				if(S > sum)
				{
					flag = i + 1;
					break;
				}
			}
			if(flag != 0)
			{
				cout << flag << "\n";
			}
			else
			{
				cout << "-1\n";
			}
		}
	}
	return 0;
}
//Subset_Sum.cpp