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
        ll n, m;
        cin >> n >> m;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int i = 0, j = n - 1;
        ll cnt = 0;
        while (i < j) {
            if (a[j] + a[i] <= m) {
                cnt++;
                i++;
                j--;
            }
            else {
                cnt++;
                j--;
            }
        }
        if (i == j && a[i] <= m) {
            cnt++;
        }
        cout << cnt << endl;
    }
}