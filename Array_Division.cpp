#include <bits/stdc++.h>
using namespace std;

#define opt() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
#define ld long double
#define ull unsigned long long

bool ok (ll mid, ll k, vector<ll> &a) {
    for (int i = 0; i < a.size(); ++i){
        if (a[i] > mid) {
            return false;
        }
    }
    ll cur = a[0],cnt = 1;
    for (int i = 1; i < a.size(); ++i) {
        if (cur + a[i] <= mid) {
            cur += a[i];
        }
        else {
            cnt++;
            cur = a[i];
        }
    }
    return cnt <= k;
}

int main(){
    opt();
    int t;
    //cin >> t;
    t = 1;

    while (t--){
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        ll l = 0, r = 1e18;
        ll ans = 0;
        while (l <= r) {
            ll mid = (l + r) / 2;
            if (ok(mid, k, a)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        cout << ans << endl;
    }
}