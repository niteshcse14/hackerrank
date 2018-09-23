#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MOD = 1e9 + 7;
const ll maxn = 1000;
ll dp[maxn][maxn];
ll t, n, m;
int main(){
	scanf("%lld", &t);
	while(t--){
		scanf("%lld%lld", &n, &m);
		memset(dp, 0, sizeof(dp));
		for(int i = 0; i <= n; ++i){
			for(int j = 0; j <= m; ++j){
				if(i == 0 || j == 0){
					dp[i][j] = 1;
				}
				else{
					dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
					dp[i][j] %= MOD;
				}
			}
		}
		printf("%lld\n", dp[n][m] % MOD);
	}
	return 0;
}