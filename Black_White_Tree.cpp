#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
vector < int > adj[maxn];
vector < int > ADJ[maxn];
vector < int > ans;
int dp[maxn][2];
int arr[maxn];
int n, l, r, a, b, m;
void dfs (int u, int p = -1) {
    if (arr[u] == 0) {
        dp[u][0] = 1;
        dp[u][1] = -1;
    }
    else {
        dp[u][0] = -1;
        dp[u][1] = 1;
    }
    for (int i = 0; i < adj[u].size(); ++i) {
        int temp = adj[u][i];
        if (temp != p) {
            ADJ[u].push_back(temp);
            dfs (temp, u);
            if (dp[temp][0] > 0) {
                dp[u][0] += dp[temp][0];
            }
            if (dp[temp][1] > 0) {
                dp[u][1] += dp[temp][1];
            }
        }
    }
}
void DFS (int u, int v) {
    ans.push_back(u);
    for (int i = 0; i < ADJ[u].size(); ++i) {
        int temp = ADJ[u][i];
        if (dp[temp][v] > 0) {
            DFS (temp, v);
        }
    }
}
int main () {
    scanf ("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf ("%d", &arr[i]);
    }
    for (int i = 1; i < n; ++i) {
        scanf ("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs (1);
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (dp[i][j] > m) {
                m = dp[i][j];
                l = i;
                r = j;
            }
        }
    }
    DFS (l, r);
    printf("%d\n", m);
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i) {
        printf("%d ", ans[i]);
    }
    printf("\n");
    return 0;
}