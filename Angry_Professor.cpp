#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
	ll N, K, sum = 0;
	cin>>N>>K;
	int arr[N]={0};
	sum=0;
	for(int i = 0; i<N;i++)
	{
		cin>>arr[i];
		if(arr[i]<0 || arr[i]==0)
		{
			sum++;
		}
	}
	if(sum<K)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
}
int main()
{
    ll T;
    cin>>T;
    while(T--)
    {
    	solve();
    }
    return 0;
}