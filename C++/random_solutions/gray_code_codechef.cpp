#include <bits/stdc++.h>
using namespace std;

// Macros
#define ll unsigned long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii std::pair<int, int>
#define vii std::vector<pii>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl "\n"
#define rep(i,a,b) for (int i=(int)(a);i<(int)(b);i++)

void solve() {
    int n;
    cin >> n;
    vector<ll> arr(n);
    for (auto &el: arr) {
        cin >> el;
    }
    sort(all(arr));
    if (n >= 130) {
        cout << "Yes" << endl;
        return;
    }
    rep(i, 0, n) {
        rep(j, i + 1, n) {
            rep(k, j + 1, n) {
                ll target = arr[i] ^ arr[j] ^ arr[k];
                auto it = lower_bound(arr.begin() + k + 1, arr.end(), target);
                if (it != arr.end() && *it == target) {
                    cout << "Yes" << endl;
                    return;
                }
            }
        }
    }
    cout << "No" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}

