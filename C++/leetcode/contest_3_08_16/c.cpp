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
const int inf = INT_MAX / 2;

class Solution {
public:
    int minCost(int n, vector<vector<int> > &edges) {
        v<v<pii> > tree(n);
        for (auto &edge: edges) {
            int a, b, w;
            a = edge[0], b = edge[1], w = edge[2];
            tree[a].emplace_back(b, w);
            tree[b].emplace_back(a, 2 * w);
        }

        v<int> distance(n, inf);
        distance[0] = 0;
        priority_queue<pii, v<pii>, greater<> > pq;
        pq.emplace(0, 0);
        while (!pq.empty()) {
            auto [node, dist] = pq.top();
            pq.pop();
            if (node == n - 1) break;
            if (dist > distance[node]) continue;

            for (auto &[child, weight]: tree[node]) {
                if (distance[child] > dist + weight) {
                    distance[child] = dist + weight;
                    pq.emplace(child, distance[child]);
                }
            }
        }
        return distance[n - 1] == inf ? -1 : distance[n - 1];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Solution s;
    v<v<int> > temp = {{0, 1, 3}, {3, 1, 1}, {2, 3, 4}, {0, 2, 2}};
    debug(s.minCost(4, temp));
    return 0;
}
