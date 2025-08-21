#include <bits/stdc++.h>
#ifdef LOCAL
#include "algo/debug.hpp"
#else
#define debug(...) 42
#endif
using namespace std;

#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl "\n"
#define rep(i,a,b) for (int i=(int)(a);i<(int)(b);i++)
/**

*/
vector<int> binary_decimals;
int MAXN = 1e5 + 5;

void precompute() {
    for (int i = 2; i <= (1 << 5); i++) {
        int curr = i;
        int decimal = 0;
        int pow = 1;
        while (curr != 0) {
            int digit = curr % 2;
            decimal += digit * pow;
            pow *= 10;
            curr /= 2;
        }
        binary_decimals.push_back(decimal);
    }
    reverse(all(binary_decimals));
}

void solve() {
    // debug(binary_decimals);
    int n;
    cin >> n;
    bool found;
    do {
        found = false;
        for (auto num: binary_decimals) {
            if (n % num == 0) {
                n /= num;
                found = true;
            }
        }
    } while (n != 1 && found);
    if (n == 1) cout << "YES" << endl;
    else cout << "NO" << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    precompute();
    for (int i = 0; i < T; i++) {
        solve();
    }
    return 0;
}
