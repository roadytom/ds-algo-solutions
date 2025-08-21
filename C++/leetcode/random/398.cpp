#include <bits/stdc++.h>
#ifdef LOCAL
#include "algo/debug.hpp"
#else
#define debug(...) 42
#endif
using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i,a,b) for (int i=(int)(a);i<(int)(b);i++)
#define len(x) static_cast<int>((x).size())
#define mp make_pair
#define pb push_back
#define ppb pop_back
#define f first
#define s second
#define v vector

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using uint = unsigned int;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
/**

*/
class Solution {
public:
    v<double> generateAllOperations(double a, double b) {
        vector<double> operations{a + b, a - b, b - a, a * b};
        if (a) {
            operations.pb(b / a);
        }
        if (b) {
            operations.pb(a / b);
        }
        return operations;
    }

    bool backtrack(v<double> &list) {
        if (len(list) == 1) {
            return abs(list[0] - 24) <= 0.1;
        }
        for (int i = 0; i < len(list); i++) {
            for (int j = i + 1; j < len(list); j++) {
                v<double> new_list;
                for (int k = 0; k < len(list); k++) {
                    if (i != k && j != k) {
                        new_list.pb(list[k]);
                    }
                }
                for (double option: generateAllOperations(list[i], list[j])) {
                    new_list.pb(option);
                    auto res = backtrack(new_list);
                    if (res) return res;
                    new_list.pop_back();
                }
            }
        }
        return false;
    }

    bool judgePoint24(vector<int> &cards) {
        v<double> double_cards;
        rep(i, 0, len(cards)) double_cards.pb(cards[i]);
        return backtrack(double_cards);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Solution s;
    v<int> t{1, 2, 1, 2};
    debug(s.judgePoint24(t));
    return 0;
}
