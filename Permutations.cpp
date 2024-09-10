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
        int n;
        cin >> n;
        if (n == 1) {
            cout << "1" << endl;
            continue;
        }
        if (n == 4) {
            cout << "2 4 1 3" << endl;
            continue;
        }
        if(n <= 3 ) {
            cout << "NO SOLUTION" << endl;
        }
        else {
            int x = 0, y = 0;
            if (n % 2 == 0) {
                x = n / 2;
                y = n / 2;
            }
            else {
                x = n / 2 + 1;
                y = n / 2 ;
            }
            vector<int> a;
            int k = 1, j = 2;
            for (int i = 0; i < x; ++i) {
                a.push_back(k);
                k += 2;
            }
            for (int i = 0; i < y; ++i) {
                a.push_back(j);
                j += 2;
            }
            for (int i = 0; i < n; ++i) {
                cout << a[i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}