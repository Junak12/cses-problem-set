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
        string s;
        cin >> s;
        map<char, int> mp;
        for (int i = 0; i < s.size(); ++i) {
            mp[s[i]]++;
        }
        bool ok = true;
        int cnt = 0;
        for (auto d : mp) {
            if (d.second % 2) {
                cnt++;
                if (cnt > 1) {
                    ok = false;
                    break;
                }
            }
        }
        if (!ok) {
            cout << "NO SOLUTION" << endl;
            continue;
        }
        string ans = "";
        for (auto d : mp) {
            ans += string(d.second / 2, d.first);
        }
        //reverse(ans.begin(), ans.end());
        string res = ans;
        reverse(res.begin(), res.end());
        for (auto d : mp) {
            if (d.second % 2) {
                ans += d.first;
                break;
            }
        }
        ans += res;
        cout << ans << endl;
    }
}