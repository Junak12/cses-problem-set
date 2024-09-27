#include <bits/stdc++.h>
using namespace std;

#define opt() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
#define ld long double
#define ull unsigned long long

const int mx = 2e5 + 123;
vector<int> adj[mx];
vector<ll> st(mx), et(mx), euler(mx), seg(4 * mx), a(mx);
int t = 0;

void dfs(int u, int par) {
    st[u] = t;               
    euler[t] = a[u]; 
    t++;
    for (auto v : adj[u]) {
        if(v != par) {
            dfs(v, u);
        }
    }
    et[u] = t;
}

void build(int node, int start, int end) {
    if (start == end) {
        seg[node] = euler[start]; 
    } 
    else {
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        seg[node] = seg[2 * node] + seg[2 * node + 1];
    }
}

void update(int node, int start, int end, int idx, ll val) {
    if (start == end) {
        seg[node] = val; 
    } 
    else {
        int mid = (start + end) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        seg[node] = seg[2 * node] + seg[2 * node + 1];
    }
}

ll query(int node, int start, int end, int l, int r) {
    if (r < start || end < l) {
        return 0; 
    }
    if (l <= start && end <= r) {
        return seg[node];
    }
    int mid = (start + end) / 2;
    ll left_sum = query(2 * node, start, mid, l, r);
    ll right_sum = query(2 * node + 1, mid + 1, end, l, r);
    return left_sum + right_sum;
}

int main() {
    opt();
    
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--; 
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0 , -1);
    build(1, 0, n - 1);
    while(q--) {
        int type;
        cin >> type;
        if(type == 1) {
            int x, y;
            cin >> x >> y;
            --x; 
            update(1, 0, n - 1, st[x], y);
        } 
        else {
            int x;
            cin >> x;
            --x;
            cout << query(1, 0, n - 1, st[x], et[x] - 1) << endl;
        }
    }
    return 0;
}
