#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll T, N;
    ll ans = 0;
    cin >> T;
    while(T--)
    {
        ans = 0;
        ll three = 0, five = 0, fifteen = 0;
        cin >> N;
        N--;
        three = N / 3;
        five = N / 5;
        fifteen = N / 15;
        ans += three * (6 + (three - 1) * 3) / 2;
        ans += five * (10 + (five - 1) * 5) / 2;
        ans -= fifteen * (30 + (fifteen - 1) * 15) / 2;
        cout << ans << "\n" ;
    }
    return 0;
}