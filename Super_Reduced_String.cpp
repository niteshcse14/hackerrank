#include <bits/stdc++.h>
using namespace std;
int main()
{
	stringstream ss;
	int flag = 0;
	string str, temp = "";
	cin >> str;
	for(int i = 1; i < str.size(); i++)
	{
		if(str[i - 1] == str[i])
		{
			str = str.substr(0, i - 1) + str.substr(i + 1);
			i = 0;
		}
	}
	if(str.size() == 0)
	{
		printf("Empty String\n");
	}
	else
	{
		cout << str << "\n";
	}
	return 0;
}
//Super_Reduced_String.cpp