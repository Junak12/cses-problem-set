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
        ll n, x;
        cin >> n >> x;
        vector<ll> a(n);
        map<ll,ll> mp;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            if (mp.find(x - a[i]) != mp.end()) {
                cout << mp[x - a[i]] + 1 << " " << i + 1 << endl;     
                return 0;      
            }
            mp[a[i]] = i;
        }
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}