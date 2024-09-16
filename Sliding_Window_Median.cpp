#include <bits/stdc++.h>
using namespace std;

#define opt() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
#define ld long double
#define ull unsigned long long

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

// Define an ordered set to store pairs {value, index}
template<class T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){
    opt();
    int t = 1; // Assuming a single test case

    while (t--) {
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        
        oset<pair<int, int>> st;
        vector<ll> ans;
        for (int i = 0; i < k; ++i) {
            st.insert({a[i], i});
        }
        ll x = st.find_by_order((k-1)/2)->first;
        ans.push_back(x);
        int j = 0;
        for (int i = k; i < n; ++i) {
            st.erase({a[j], j});
            st.insert({a[i], i});      
            x = st.find_by_order((k-1)/2) ->first; 
            ans.push_back(x);
            j++;
        }
        for (auto d : ans) {
            cout << d << " ";
        }
        cout << endl;
    }
}
