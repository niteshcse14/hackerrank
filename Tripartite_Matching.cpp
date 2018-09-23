#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define pb push_back
#define fi first
#define se second
//#define LOCAL
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long i64;
typedef unsigned long long u64;
const int maxn = 100500;
int n;
vi e[3][maxn];
set<pii> e3;
const int BUBEN = 230;
int solve_small(const vi& a, const vi& b) {
    int res = 0;
    for (int v: a) { 
        for (int to: b) {
            //printf("%d %d\n", v, to);
            res += e3.count({v, to});
        }
    }
    return res;
}
int solve_large(vi a, vi b) {
    vector<int> ina(n), inb(n);
    for (int v: a) ina[v] = 1;
    for (int v: b) inb[v] = 1;
    int res = 0;
    forn(v, n) {
        for (int to: e[2][v]) {
            res += ina[v] && inb[to];
        }
    }
    return res;
}

void solve() {
    i64 res = 0;
    int cs = 0, cl = 0;
    forn(i, n) {
        vi a = e[0][i];
        vi b = e[1][i];
        if ((a.size() + b.size()) < BUBEN) {
            res += solve_small(a, b);
            ++cs;
        } else {
            res += solve_large(a, b);
            ++cl;
        }
    }
    cerr << cs << " " << cl << endl;
    cout << res << endl;
}
void scan() {
    scanf("%d", &n);
    for (int k: {0,2,1}) {
        int m;
        scanf("%d", &m);
        forn(i, m) {
            int u, v;
            scanf("%d%d", &u, &v);
            e[k][--u].push_back(--v);
            e[k][v].push_back(u);
            if (k == 2) {
                e3.insert({u, v});
                e3.insert({v, u});
            }
        }
    }
}
int main() {
    #ifdef LOCAL
        freopen("in.txt", "r", stdin);
    #endif
        scan();
        solve();
    #ifdef LOCAL
        cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
    #endif
    return 0;
}