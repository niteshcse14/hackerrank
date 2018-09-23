#include <bits/stdc++.h>
using namespace std;
int main()
{
	string str;
	cin >> str;
	int count = 1;
	if(str[0] < 91)
	{
		count = 0;
	}
	for(int i = 0; i < str.size(); i++)
	{
		int t = str[i];
		if(t < 91)
		{
			count++;
		}
	}
	cout << count << "\n";
	return 0;
}
//Camel_Case.cpp