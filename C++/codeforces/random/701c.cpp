#include <bits/stdc++.h>
#ifdef LOCAL
#include "algo/debug.hpp"
#else
#define debug(...) 42
#endif
using namespace std;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl "\n"
#define rep(i,a,b) for (int i=(int)(a);i<(int)(b);i++)
#define mp make_pair

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using uint = unsigned int;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
/**

*/
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int left = 0, right = 0;
    set<char> pokemons;
    for (char c: s) pokemons.insert(c);
    int pokemons_count = (int) pokemons.size();
    map<char, int> counter;
    int min_flat = INT_MAX;
    while (right < n) {
        counter[s[right]]++;
        while (left <= right && counter[s[left]] > 1) {
            counter[s[left]]--;
            left++;
        }
        if (counter.size() == pokemons_count) {
            min_flat = min(min_flat, right - left + 1);
        }
        right++;
    }
    cout << min_flat << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}
