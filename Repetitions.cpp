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
        int i = 0, j = 1;
        int n = s.size();
        int cnt = 1, ans = 1;
        while (i < n -1 || j < n - 1) {
            if (s[i] == s[j]) {
                cnt++;
                j++;
            }
            else {
                ans = max(ans, cnt);
                cnt = 1;
                i++;
                if (i == j) {
                    j++;
                }
            }
        }
       // cout << i << " " << j << endl;
        ans = max(ans, cnt);
        cout << ans << endl;
    }
    return 0;
}