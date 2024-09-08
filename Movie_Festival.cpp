#include <bits/stdc++.h>
using namespace std;

#define opt() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
#define ld long double
#define ull unsigned long long

bool cmp(pair<int,int> &a, pair<int,int> &b){
    return a.second < b.second; 
}

int main(){
    opt();
    int t;
   // cin >> t;
    t = 1;

    while(t--){
        int n;
        cin >> n;
        vector<pair<int,int>> vp;
        for (int i = 0; i < n; ++i) {
            int a, b;
            cin >> a >> b;
            vp.push_back({a, b});
        }
        sort(vp.begin(), vp.end(), cmp);
        int cnt = 0;
        int so_far = -1;
        for (int i = 0; i < vp.size(); ++i) {
            if(vp[i].first >= so_far) {
                so_far = vp[i].second; 
                cnt++;
            }
        } 
        cout << cnt << endl;
    }
}