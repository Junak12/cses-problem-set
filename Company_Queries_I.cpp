#include <bits/stdc++.h>
using namespace std;

#define opt() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
#define ld long double
#define ull unsigned long long

const int mx = 2e5 + 123;
vector<int> adj[mx];
vector<vector<int>> dp(mx, vector<int>(18, 0));

void dfs(int u, int par) {
    dp[u][0] = par;
    for (int i = 1; i < 18; ++i) {
        if (dp[u][i - 1] == -1) {
            dp[u][i] = -1;
        }
        else dp[u][i] = dp[dp[u][i - 1]][i - 1];
    }
    for (auto d : adj[u]) {
        if (d == par) {
            continue;
        }
        dfs(d, u);
    }
}

int main(){
    opt();
    int t;
    //cin >> t;
    t = 1;

    while (t--){
        int n, q;
        cin >> n >> q;
        for (int i = 2; i <= n; ++i) {
            int x;
            cin >> x;
            adj[x].push_back(i);
            adj[i].push_back(x);
        }
        dfs(1, -1);
        while (q--) {
            int node, k;
            cin >> node >> k;
            for (int i = 18; i >= 0; --i) {
                if ((k >> i) & 1) {
                    node = dp[node][i];
                    if(node == -1)break;
                }
            }
            if (node == -1) {
                cout << "-1" << endl;
            }
            else {
                cout << node << endl;
            }
        }
    }
    return 0;
}