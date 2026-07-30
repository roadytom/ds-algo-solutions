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
    void mini(int &a, int b) {
        a = min(a, b);
    }

    bool intersects(unordered_set<int> &a, unordered_set<int> &b) {
        return any_of(all(a), [&](int x) { return b.count(x); });
    }

    int minimumTeachings(int n, vector<vector<int> > &languages, vector<vector<int> > &friendships) {
        // helper[user_id][language] = knowing friends count
        int user_count = len(languages);
        // v<v<int> > helper(m + 1, v<int>(n + 1));
        v<unordered_set<int> > adj_list(user_count + 1);
        for (auto &friends: friendships) {
            int f1 = friends[0], f2 = friends[1];
            adj_list[f1].insert(f2);
            adj_list[f2].insert(f1);
        }
        v<unordered_set<int> > lang_set(user_count + 1);
        for (int i = 0; i < len(languages); i++) {
            for (int lang: languages[i]) {
                lang_set[i + 1].insert(lang);
            }
        }
        for (int i = 1; i <= user_count; i++) {
            auto &friends = adj_list[i];
            auto &my_langs = lang_set[i];
            unordered_set<int> already_match;
            for (int f: friends) {
                auto &his_langs = lang_set[f];
                if (intersects(my_langs, his_langs)) {
                    already_match.insert(f);
                }
            }
            for (int removed: already_match) {
                adj_list[i].erase(removed);
                adj_list[removed].erase(i);
            }
        }

        function<int(int, int, v<bool> &)> dfs = [&](int user, int lang, v<bool> &visited) {
            visited[user] = true;
            int res = 0;
            bool has_friend = false;
            for (auto &f: adj_list[user]) {
                has_friend = true;

                if (!visited[f]) {
                    res += dfs(f, lang, visited);
                }
            }

            res += (!lang_set[user].count(lang) && has_friend);
            return res;
        };
        // for (int user = 1; user <= n; user++) {
        //     for (auto &fr: adj_list[user]) {
        //         for (auto l: languages[fr - 1]) {
        //             helper[user][l]++;
        //         }
        //     }
        // }
        // debug(helper);
        debug(adj_list);
        int min_teach = INT_MAX;

        for (int l = 1; l <= n; l++) {
            v<bool> visited(user_count + 1);
            int current_teach = 0;
            for (int i = 1; i <= user_count; i++) {
                if (!visited[i]) {
                    int res = dfs(i, l, visited);
                    debug(l, i, res);
                    current_teach += res;
                }
            }
            mini(min_teach, current_teach);
        }
        return min_teach;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Solution s;
    // v<v<int> > l{{1}, {2}, {1, 2}};
    vector<vector<int> > v1 = {{1}, {2}, {1, 2}};
    vector<vector<int> > v2 = {{1, 2}, {1, 3}, {2, 3}};
    debug(s.minimumTeachings(3, v1, v2));

    return 0;
}
