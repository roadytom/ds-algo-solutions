#include <iostream>
#include <vector>
#include <set>
#include <iterator>
#include <algorithm>
#include <numeric>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int &x : arr) cin >> x;

    multiset<int> low, up; // low = max heap (but we use multiset), up = min heap
    ll sum_low = 0, sum_up = 0;

    auto insert = [&](int val) {
        if (low.empty() || *low.rbegin() >= val) {
            low.insert(val);
            sum_low += val;
        } else {
            up.insert(val);
            sum_up += val;
        }

        // Balance the sets
        while (low.size() > up.size() + 1) {
            int moved = *low.rbegin();
            low.erase(prev(low.end()));
            sum_low -= moved;
            up.insert(moved);
            sum_up += moved;
        }
        while (up.size() > low.size()) {
            int moved = *up.begin();
            up.erase(up.begin());
            sum_up -= moved;
            low.insert(moved);
            sum_low += moved;
        }
    };

    auto erase = [&](int val) {
        if (low.find(val) != low.end()) {
            low.erase(low.find(val));
            sum_low -= val;
        } else {
            up.erase(up.find(val));
            sum_up -= val;
        }

        // Balance again
        while (low.size() > up.size() + 1) {
            int moved = *low.rbegin();
            low.erase(prev(low.end()));
            sum_low -= moved;
            up.insert(moved);
            sum_up += moved;
        }
        while (up.size() > low.size()) {
            int moved = *up.begin();
            up.erase(up.begin());
            sum_up -= moved;
            low.insert(moved);
            sum_low += moved;
        }
    };

    vector<ll> ans;
    int left = 0, right = 0;
    while (right < n) {
        insert(arr[right]);
        if (right - left + 1 == k) {
            int med = *low.rbegin();
            ll cost = sum_up - 1LL * med * up.size() + 1LL * med * low.size() - sum_low;
            ans.push_back(cost);
            erase(arr[left]);
            left++;
        }
        right++;
    }

    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << (i + 1 == ans.size() ? '\n' : ' ');
    }

    return 0;
}