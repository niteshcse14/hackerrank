#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
int a[5025];
vector<int> v;
bool prime[9025];
long long dp[2][8192];
void sieve() {
    memset(prime, true, sizeof(prime));
    prime[1] = false, prime[0] = false; 
    for(int i = 4; i <= 9000; i += 2)
    prime[i] = false;
    for (int p = 3; p * p <= 9000;p += 2){
        if (prime[p] == true) {
            for (int i = p * p; i <= 9000; i += 2 * p)
                prime[i] = false;
        }
    }
}
int main() {
int t;
sieve();
cin >> t;
    while(t--) {
        int n, x;
        cin >> n;
        v.clear();
        memset(a,0,sizeof(a));
        for(int i=0;i<n;i++) {
            scanf("%d",&x);
            a[x]+=1;
        }
        for(int i=3500;i<4525;i++)
            if(a[i]>=1)
                v.push_back(i);
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        int flag=1;
        int k = v.size();
        for(int i=1;i<=k;i++) {
            for(int j=0;j<8192;j++) {
                dp[flag][j] = (dp[flag^1][j]*(1+(a[v[i-1]])/2))%mod + 
                    (dp[flag^1][j^v[i-1]]*((a[v[i-1]]+1)/2))%mod;
                if(dp[flag][j]>=mod)
                    dp[flag][j]%=mod;
            }
            flag = flag^1;
        }
        long long ans=0;
        long long res=0;
        for(int i=1;i<8192;i++) {
            if(prime[i]){

                res+= dp[flag^1][i];
                res%=mod;
            }
        }
        cout << res << endl;
    }
    return 0;
}