#include <bits/stdc++.h>
using namespace std;

#define opt() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
#define ld long double
#define ull unsigned long long

const int mx = 2e5 + 123;
vector<int> adj[mx];
vector<bool> vis(mx, false);
vector<int> dist(mx, 0);

void dfs(int u, int cur) {
	vis[u] = true;
	dist[u] = cur;
	for (auto d : adj[u]) {
		if (!vis[d]) {
			dfs(d, cur + 1);
		}
	}
}

int main() {
	opt();
	int t;
	//cin >> t;
	t = 1;

	while(t--) {
		int n;
		cin >> n;
		for (int i = 0; i < n - 1; ++i) {
			int u, v;
			cin >> u >> v;
            u--; v--; 
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		dfs(0, 0);
		/*for (int i = 0; i < n; ++i) {
			cout << dist[i] << " ";
		}
		cout << endl;*/
        int mx = 0;
        int idx = -1;
        for (int i = 0; i < n; ++i) {
            if (dist[i] >= mx) {
                mx = dist[i];
                idx = i;
            }
        }
        fill (dist.begin(), dist.begin() + n, 0);
        fill (vis.begin(), vis.begin() + n, false);
        dfs(idx, 0);
        int diameter = 0;
        int idx1 = -1;
        for (int i = 0; i < n; ++i) {
            if (dist[i] >= diameter) {
                diameter = dist[i];
                idx1 = i;
            }
        }
        cout << diameter << endl;
	}
}