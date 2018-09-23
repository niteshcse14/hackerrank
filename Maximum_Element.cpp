#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define pc putchar_unlocked
#define ll long long int
#define V_ll vector<ll>
#define V_int vector<int>
#define M_ll multiset<ll>
#define M_int multiset<int>
#define	mp make_pair
#define	pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
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

int main()
{
    fast;
    int T = sscan(),N;
    N=T;
    int m=0,m1=0,n,si=0,type,current_max=0;
    stack<int> s;
    stack<int> maxx;
    while(T--)
    {
		type=sscan();
		if(type == 1)
		{
			n=sscan();
			s.push(n);

			if(n > current_max)
			{
				maxx.push(n);
				current_max=n;
			}
			else
			{
				maxx.push(maxx.top());
			}
		}
		else if(type == 2)
		{
			s.pop();
			int m_top=maxx.top();
			if(m_top == current_max)
			{
				maxx.pop();
				if(maxx.empty())
				{
					current_max=0;
				}
				else
				{
					current_max=maxx.top();
				}
			}
		}
		else if(type == 3)
		{
			printf("%d\n",maxx.top());
		}
    }
    return 0;
}