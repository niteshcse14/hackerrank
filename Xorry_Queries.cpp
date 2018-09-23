#include <bits/stdc++.h>
using namespace std;
int **tree, **lazy;
int **new_arr;
void build_tree(int node, int start, int endd,int i)
{
    if(start == endd)
        tree[i][node] = new_arr[i][start];
    else{
        int mid = (start+endd)/2;
        build_tree(2*node,start,mid,i);
        build_tree(2*node+1,mid+1,endd,i);
        tree[i][node]=tree[i][2*node]+tree[i][2*node+1];
    }
}
void update_range(int node, int start, int endd, int l, int r, int i)
{
    if (lazy[i][node] == 1){
        tree[i][node] = endd - start + 1 - tree[i][node];
        if (start != endd) {
            lazy[i][node * 2] ^= 1; 
            lazy[i][node * 2 + 1] ^= 1; 
        }
        lazy[i][node] = 0;
    }
    if (start > endd or start > r or endd < l) 
        return;
    if (start >= l and endd <= r) {
        tree[i][node] = endd-start + 1 - tree[i][node];
        if (start != endd) {
            lazy[i][node * 2] ^= 1;
            lazy[i][node * 2 + 1] ^= 1;
        }
        return;
    }
    int mid = (start + endd) / 2;
    update_range(node * 2, start, mid, l, r, i); 
    update_range(node * 2 + 1, mid + 1, endd, l, r, i); 
    tree[i][node] = tree[i][node * 2] + tree[i][node * 2 + 1];
}
int queryRange(int node, int start, int endd, int l, int r, int i)
{
    if (start > endd or start > r or endd < l)
        return 0; 
    if (lazy[i][node] == 1) {
        tree[i][node] = (endd - start + 1) - tree[i][node]; 
        if (start != endd) {
            lazy[i][node * 2] ^= 1; 
            lazy[i][node * 2 + 1] ^= 1; 
        }
        lazy[i][node] = 0; 
    }
    if (start >= l and endd <= r) 
        return tree[i][node];
    int mid = (start + endd) / 2;
    int p1 = queryRange(node * 2, start, mid, l, r, i); 
    int p2 = queryRange(node * 2 + 1, mid + 1, endd, l, r, i);
    return (p1 + p2);
}
void solve()
{
    int n, m, p;

    cin >> n >> m >> p;
    int new_arr_size = n - p + 1;
    int *arr=new int[n+1];
    tree = new int*[17];
    lazy = new int*[17];
    new_arr=new int*[17];
    int seg_size = 4 * n - 4 * p + 6;
    for (int i = 0; i < 17; i++) {
        tree[i] = new int[seg_size];
        lazy[i] = new int[seg_size];
        new_arr[i]=new int[new_arr_size+1];
        for (int j = 1; j < seg_size; j++)
            tree[i][j] = lazy[i][j] = 0;
    }
    int i;
    long long ai;
    long long xorr=0;
    for (i = 1; i <= n; i++)
            cin>>arr[i];
    arr[0]=0;
    for(i=1;i<p;i++)
        xorr^=arr[i];
    for(i=1;i<=n-p+1;i++){
        xorr=(xorr^arr[i-1])^arr[i+p-1];
        int k=0;
        for(long long j=1;k<17;k++,j*=2)
            if(xorr&j)
                new_arr[k][i]=1;
            else
                new_arr[k][i]=0;
    }
    for(int i=0;i<17;i++)
        build_tree(1,1,new_arr_size,i);
    int type;
    while (m--) {
        cin >> type;
        if (type == 1) {
            cin >> i >> ai;
            int l = max(1, i - p + 1);
            int r = min(i, new_arr_size);
            for (long long j=1,k=0;j<=ai;j*=2,k++)
                if (ai&j)
                    update_range(1, 1, new_arr_size, l, r, k);
        }
        else {
            int l, r;
            cin >> l >> r;
            if (l > new_arr_size)
                cout << 0 << "\n";
            else {
                r = min(r, new_arr_size);
                long long ans = 0;
                int k = 0;
                for (long long j = 1, k = 0; k < 17; j *= 2, k++)
                    ans += j * queryRange(1, 1, new_arr_size, l, r, k);
                cout << ans << "\n";
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}