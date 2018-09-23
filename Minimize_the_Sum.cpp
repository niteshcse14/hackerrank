#include <bits/stdc++.h>
using namespace std;
#define f(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) f(i,0,n)
#define fd(i,a,b) for(i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define vi vector< int >
#define vl vector< ll >
#define ss second
#define ff first
#define ll long long
#define pii pair< int,int >
#define pll pair< ll,ll >
#define sz(a) a.size()
#define inf (1000*1000*1000+5)
ll ans=0;
ll l[123456],r[123456];
int main(){
    int n,i;
    cin>>n;
    rep(i,n)
        cin>>l[i];
    rep(i,n)
        cin>>r[i];
    i=0;
    ll low,high;
    low=l[i];
    high=r[i];
    f(i,1,n){
        if(low>r[i]){
            ans+=low-r[i];
            low=r[i];
            high=r[i];
        }
        else if(high<l[i]){
            ans+=l[i]-high;
            low=l[i];
            high=l[i];
        }
        else{
            high=min(high,r[i]);
            low=max(low,l[i]);
        }
    }
    cout<<ans<<endl;        
}