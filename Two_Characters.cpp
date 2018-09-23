#include <bits/stdc++.h>
using namespace std;
int main()
{
	int N;
	string str;
	cin >> N >> str;
	int arr[26];
	for(int i = 0; i < 26; i++)
	{
		arr[i] = 0;
	}
	if(N == str.size())
	{
		for(int i = 0; i < N; i++)
		{
			arr[str[i] - 97]++;
		}
	}
	for(int i = 1; i < str.size(); i++)
	{
		if(str[i - 1] == str[i])
		{
			char ch = str[i];
			arr[str[i] - 97] = 0;
			string A = "";
			for(int j = 0; j < str.size(); j++)
			{
				if(ch == str[j])
				{
					str[j] = '\0';
				}
				else
				{
					A += str[j];
				}
			}
			str = A;
			i = 0;
		}
	}
	if(str.size() == 0)
	{
		printf("0\n");
	}
	else
	{
		sort(arr, arr + 26);
		cout << arr[24] + arr[25] << "\n";
	}
	return 0;
}
//Two_Characters.cpp