#include <bits/stdc++.h>
using namespace std;

#define opt() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
#define ld long double
#define ull unsigned long long

bool ok (ll mid, vector<ll> &a, ll n, ll t) {
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        ll x = mid / a[i];
        sum += x;
        if (sum >= t) {
            return true;
        }
    }
    return sum >= t;
}

int main(){
    opt();
    int t;
    //cin >> t;
    t = 1;

    while (t--){
        ll n, t;
        cin >> n >> t;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        //sort (a.begin(), a.end());
        ll ans = 0;
        ll l = 0, r = 1e18;
        while (l <= r) {
            ll mid = (l + r) / 2;
            if (ok(mid, a, n, t)) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        cout << ans << endl;
    }
}