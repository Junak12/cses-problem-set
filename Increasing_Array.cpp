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
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        ll ans = 0;
        for (int i = 1; i < n; ++i) {
            if (a[i] < a[i - 1]) {
                ans += abs(a[i -1] - a[i]);
                a[i] = a[i - 1];
                //cout << a[i -1] <<  " " << a[i] << endl;
            }
        }
        cout << ans << endl;
    }
}