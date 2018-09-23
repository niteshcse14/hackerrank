#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define pc putchar_unlocked
#define ll long long int
#define V_ll vector<ll>
#define V_int vector<int>
#define	mp make_pair
#define	pb push_back
#define M_ll multiset<ll>
#define M_int multiset<int>
#define IT iterator
#define pii pair<int,int>
#define pll pair<ll,ll>
#define FOR_Z(i,a) for(int i=0;i<a;++i)
#define FOR_A(i,a,b) for(int i=a;i<b;++i)
#define mod 1000000007
inline int max(int a,int b){return a<b?b:a;}
inline int min(int a,int b){return a>b?b:a;}
inline ll max(ll a,ll b){return a<b?b:a;}
inline ll min(ll a,ll b){return a>b?b:a;}
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
const int MOD = 1e9+7;
const int N = 1e6+10;
const ll inf = 1e18;
#define fast ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)

ll q_sort (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
//qsort(values, 5, sizeof(int), q_sort);

ll modpow(ll a, ll b)
{
	ll r = 1;

	while (b) {
		if (b & 1) {
			r = (r * a) % mod;
		}

		a = (a * a) % mod;

		b >>= 1;
	}

	return r;
}

ll modpowinverse(ll a) 
{
	return modpow(a, mod - 2);
}

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
void solve()
{
	ll a,b;
	a = sscan();
	b = sscan();
	ll a_arr[a], b_arr[b],sum = 0, flag = 1,a_max=1,b_min=100;
	FOR_Z(i,a)
	{
		a_arr[i] = sscan();
		if(a_arr[i] > a_max)
		{
			a_max = a_arr[i];
		}
	}
	FOR_Z(i,b)
	{
		b_arr[i] = sscan();
		if(b_arr[i] < b_min)
		{
			b_min = b_arr[i];
		}
	}
	//printf("%lld  %lld \n",a_max,b_min );
	for(int i = a_max; i <= b_min; i+=a_max)
	{
		flag = 1;
		FOR_Z(j,a)
		{
			if(i % a_arr[j] != 0)
			{
				flag = 0;
				break;
			}
		}
		if(flag == 1)
		{
			FOR_Z(k,b)
			{
				if(b_arr[k] % i != 0)
				{
					flag = 0;
					break;
				}
			}
		}
		if(flag == 1)
		{
			sum++;
		}
	}
	printf("%lld\n",sum);
}
int main()
{
    fast;
    ll T = 1;
    while(T--)
    {
    	solve();
    }
    return 0;
}