#include<stdio.h>
#include<iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#define gc getchar_unlocked
#define pc putchar_unlocked
#define ll long long int
using namespace std;
#define MOD 1000000007
static ll ans=1;
inline long long int sscan()
{
   long long int n=0;
   int ch=gc();
   while( ch < '0' || ch > '9' )
        ch=gc();
   while(  ch >= '0' && ch <= '9' )
   {
       n = (n<<3)+(n<<1) + ch-'0';
       ch=gc();
   }
   return n;
}
 
inline void print(long int a)
{
	int i=0;
	char S[20];
	while(a>0)
	{
    	S[i++]=a%10+'0';
		a=a/10;
	}
	--i;
	while(i>=0)
		pc(S[i--]);
	pc('\n');
}
ll recur(ll n,ll d)
{
	if(n==0)
	{
		return 2;
	}
	ans=((n+1)*recur(n-1,d))/(n*recur(n-1,d)+1);
	printf("%lld\n",ans);
	return ans%MOD;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //int q=sscan();
    printf("%lld \n",recur(4,2));
    return 0;
}