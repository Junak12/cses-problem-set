#include <bits/stdc++.h>
using namespace std;

#define opt() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
#define ld long double
#define ull unsigned long long

int main(){
    opt();
    int t;
    //cin >> t;
    t = 1;

    while (t--){
        ll n;
        cin >> n;
        vector<ll> a(n);
        vector<ll> pre(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        pre[0] = a[0] % n;
        pre[0] = (pre[0] + n) % n;
        for (int i = 1; i < n; ++i) {
            pre[i] = pre[i - 1] + a[i];
            pre[i] = pre[i] % n;
            pre[i] = (pre[i] + n) % n;
        }
        ll cnt = 0;
        map<ll,ll> mp;
        mp[0] = 1;
        for (int i = 0; i < n; ++i) {
            cnt += mp[pre[i]];
            mp[pre[i]]++;
        }
        cout << cnt << endl;
    }
}