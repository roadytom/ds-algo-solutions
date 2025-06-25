#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const double INF = 1e18;

// Read utility functions
vector<int> read_int_list(int n) {
    vector<int> result(n);
    for (int i = 0; i < n; ++i) {
        cin >> result[i];
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    vector<int> arr = read_int_list(N);

    set<int> sorted_set;
    for (int i = 0; i <= arr.size(); ++i) {
        sorted_set.insert(i);
    }

    int left = 0, right = 0;
    unordered_map<int, int> counter;
    int ans = INT_MAX;

    while (right < N) {
        counter[arr[right]]++;
        sorted_set.erase(arr[right]);

        if (right - left + 1 == M) {
            ans = min(ans, *sorted_set.begin());

            counter[arr[left]]--;
            if (counter[arr[left]] == 0) {
                sorted_set.insert(arr[left]);
            }
            left++;
        }
        right++;
    }

    cout << ans << '\n';
    return 0;
}