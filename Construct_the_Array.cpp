#include "bits/stdc++.h"
#define MAXN 100009
#define INF 1000000007
using namespace std; 
typedef long long ll;
int dp[MAXN];
int mod(ll x){
	while(x<0)
		x+=INF;
	return (x%INF);	
}
int Fe(int x,int y){
	if(!y)
		return 1LL;
	int h=Fe(x,y/2);
	h=mod(h*1LL*h);
	if(y&1)
		h=mod(h*1LL*x);
	return h;	
}
int main(){
	int N,K,X;
	scanf("%d%d%d",&N,&K,&X);
	assert(3<=N and N<=100000);
	assert(2<=K and K<=100000);
	assert(1<=X and X<=K);
	dp[0]=1;
	for(int i=2;i<=N;i++)	
		dp[i]=mod(mod(dp[i-2]*1LL*(K-1))+mod(dp[i-1]*1LL*(K-2)));
	if(X==1)
		printf("%d\n",dp[N-1]);
	else
		printf("%d\n",mod(dp[N]*1LL*Fe(K-1,INF-2)));
	return 0;
}