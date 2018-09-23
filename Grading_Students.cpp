#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll div,N,T;
    cin>>T;
    assert(T >= 1 and T <= 60);
    while(T--)
    {
    	cin>>N;
    	assert(N >= 0 and N <= 100);
    	
    	if(N < 38)
    	{
    		printf("%lld\n",N);
    	}
    	else
    	{
    		div=N/5;
    		ll next=(div+1)*5;
    		if((next-N) < 3)
    		{
    			printf("%lld\n",next);
    		}
    		else
    		{
    			printf("%lld\n",N);
    		}
    	}
    }
    return 0;
}