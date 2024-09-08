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

    while(t--){
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        ll to_meet = a[n / 2];
        ll ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += abs(a[i] - to_meet);
        }
        cout << ans << endl;
    }
    return 0;
}
