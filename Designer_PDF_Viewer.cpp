#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll arr[26]={0},ans[26]={0};
	for(int i = 0; i < 26; i++)
	{
		cin>>arr[i];
	}
	string str;
	cin>>str;
	for(int i = 0;i < str.size(); i++)
	{
		ans[i] = arr[str[i]-97];
	}
	sort(ans,ans+26);
	printf("%lld\n",(str.size())*ans[25]);
}
int main()
{
    solve();
    return 0;
}