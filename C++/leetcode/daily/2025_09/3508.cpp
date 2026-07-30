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
class Router {
public:
    int memory_limit;
    int id = 0;
    // timestamp, source, destination
    map<pair<int, pii>, int> packet_to_id;
    map<pair<pii, pii>>
    Router(int memory_limit) {
        this->memory_limit = memory_limit;
    }

    bool addPacket(int source, int destination, int timestamp) {
    }

    vector<int> forwardPacket() {
    }

    int getCount(int destination, int start_time, int end_time) {
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Solution s;
    debug(s.solve());
    return 0;
}
