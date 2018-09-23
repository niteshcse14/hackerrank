#include<bits/stdc++.h>
using namespace std;
#define assn(n,a,b) assert(n<=b && n>=a)
#define pb push_back
#define mp make_pair
#define clr(x) x.clear()
#define sz(x) ((int)(x).size())
#define F first
#define S second
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,b) for(i=0;i<b;i++)
#define rep1(i,b) for(i=1;i<=b;i++)
#define pdn(n) printf("%d\n",n)
#define sl(n) scanf("%lld",&n)
#define sd(n) scanf("%d",&n)
#define pn printf("\n")
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;
#define MOD 1000000007
LL mpow(LL a, LL n) {
    LL ret=1;LL b=a;
    while(n) {
        if(n&1) 
            ret=(ret*b)%MOD;
        b=(b*b)%MOD;
        n>>=1;
}
return (LL)ret;}
LL cx,cy,r,x[3],y[3],i,j;
void checkp(){
    if((x[0]*(y[1]-y[2])+x[1]*(y[2]-y[0])+x[2]*(y[0]-y[1]))==0ll)
        assert(1>2);
}
bool check(LL p, LL q){
    LL x0=x[p],x1=x[q],y0=y[p],y1=y[q];
    LL a=x1-x0;
    LL b=y1-y0;
    LL c=cx-x0;
    LL d=cy-y0;
    if((a*d-c*b)*(a*d-c*b)>r*r*(a*a+b*b))
        return false;
    LL flag1=0,flag2=0;
    if((c*c + d*d)==r*r||((a-c)*(a-c)+(b-d)*(b-d))==(r*r))
        return true;
    if(c*c+d*d<r*r)
        flag1=1;
    if((a-c)*(a-c)+(b-d)*(b-d)<r*r)
        flag2=1;
    if(flag1*flag2==1ll)
        return false;
    if(flag1+flag2==1ll)
        return true;
    if(c*a+d*b>=0&&c*a+d*b<=(a*a+b*b))
        return true;
    return false;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> cx >> cy >> r;
        assn(cx,-2000,2000);
        assn(cy,-2000,2000);
        assn(r,1,2000);
        for(i=0; i<3; i++){
            cin >> x[i] >> y[i];
            assn(x[i],-5000,5000);
            assn(y[i],-5000,5000);
        }
        checkp();
        if(check(0,1) || check(0,2) || check(1,2))
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}