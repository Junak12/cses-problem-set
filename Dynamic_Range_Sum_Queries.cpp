#include <bits/stdc++.h>
using namespace std;

#define opt() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
#define ld long double
#define ull unsigned long long

const ll mx = 2e5 + 123;
vector<int> a(mx);
vector<ll> tree(4 * mx);
int n, q;

void build(int node, int start, int end) {
    if (start == end) {
        tree[node] = a[start];
        return ;
    }
    int mid = (start + end) / 2;
    int left = 2 * node;
    int right = left + 1;
    build(left, start, mid);
    build(right, mid + 1, end);
    tree[node] = tree[left] + tree[right];
}

void update(int node, int start, int end, int idx, int val) {
    if (start == end) {
        a[idx] = val;
        tree[node] = val;
        return;
    }
    int mid = (start + end) / 2;
    int left = 2 * node;
    int right = left + 1;
    if (idx <= mid) {
        update(left, start, mid, idx, val);
    }
    else {
        update(right, mid + 1, end, idx, val);
    }
    tree[node] = tree[left] + tree[right];
}
ll query(int node, int start, int end, int qs, int qe) {
    if (start > qe || end < qs) {
        return 0;
    }
    if (start >= qs && end <= qe) {
        return tree[node];
    }
    else {
        int mid = (start + end) / 2;
        int left = 2 * node;
        int right = left + 1;
        ll p1 = query(left, start, mid, qs, qe);
        ll p2 = query(right, mid + 1, end, qs, qe);
        return p1 + p2;
    }
}

int main(){
    opt();
    int t;
    //cin >> t;
    t = 1;

    while (t--){
        cin >> n >> q;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        build(1, 1, n);
        while(q--) {
            int type, l, r;
            cin >> type >> l >> r;
            if (type == 1) {
                update(1, 1, n, l, r);
            }
            else {
                cout << query(1, 1, n, l, r) << endl;
            }
        }
    }
    return 0;
}