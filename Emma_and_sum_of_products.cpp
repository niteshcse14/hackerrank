#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const double PI = 4 * atan(1);
#define base complex <double>
#define pb push_back
#define mod 100003
vector<base> omega;
ll FFT_N;
void init_fft(ll n) {
    FFT_N = n;
    omega.resize(n);
    double alpha = 2 * PI / n;
    for (ll i = 0; i < n; ++i) {
        omega[i] = base(cos(i * alpha), sin(i * alpha));
    }
}
void fft(vector<base> &a) {
    ll n = a.size();
    if (n == 1) return;
    ll half = n >> 1;
    vector<base> even(half), odd(half);
    for (ll i = 0, j = 0; i < n; i += 2, ++j) {
        even[j] = a[i];
        odd[j] = a[i + 1];
    }
    fft(even);
    fft(odd);
    for (ll i = 0, fact = FFT_N / n; i < half; ++i) {
        base tw = omega[i * fact] * odd[i];
        a[i] = even[i] + tw;
        a[i + half] = even[i] - tw;
    }
}
void multiply(vector<ll> &a, vector<ll> &b, vector<ll> &res) {
    vector<base> fa (a.begin(), a.end());
    vector<base> fb (b.begin(), b.end());
    ll len_a = a.size();
    ll len_b = b.size();
    ll n = 1;
    while (n < 2 * max (len_a, len_b)) n <<= 1;
    fa.resize(n);
    fb.resize(n);
    init_fft(n);
    fft(fa);
    fft(fb);
    for (ll i = 0; i < n; ++i) {
        fa[i] = conj(fa[i] * fb[i]);
    }
    fft(fa);
    res.resize(n);
    for (ll i = 0; i < n; ++i) {
        res[i] = (ll)(fa[i].real() / n + 0.5);
        res[i] %= mod;
    }
}
ll n, val, idx, l, ptr, q;
vector<ll> temp,tt;
vector<vector<ll>>inp[20];
int main() {
    scanf("%lld", &n);
    for (ll i = 0; i < n; ++i) {
        temp.clear();
        scanf("%lld", &val);
        temp.pb(1);
        temp.pb(val);
        inp[0].pb(temp);
    }
    l = n;
    while (l > 1) {
        ptr++;
        for (ll i = 0; i < l / 2; ++i) {
            inp[ptr].pb(tt);
            multiply(inp[ptr - 1][2 * i], inp[ptr - 1][2 * i + 1], inp[ptr][i]);
        }
        if (l % 2)
            inp[ptr].pb(inp[ptr - 1][l - 1]);
        l = inp[ptr].size();
    }
    scanf("%lld", &q);
    while (q--) {
        scanf("%lld", &idx);
        printf("%lld\n", inp[ptr][0][idx]);
    }
    return 0;
}