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
void solve() {
    int n, d, k;
    cin >> n >> d >> k;
    vector<pair<int, int> > jobs(k);
    rep(i, 0, k) {
        cin >> jobs[i].first >> jobs[i].second;
    }

    int max_start_day = n - d + 1;
    // Difference array to store changes in overlap counts.
    // Size is max_start_day + 2 to handle the diff[end_s + 1] index.
    vector<int> diff(max_start_day + 2, 0);

    for (int i = 0; i < k; ++i) {
        int job_l = jobs[i].first;
        int job_r = jobs[i].second;

        // Determine the range of visit start days [s_min, s_max]
        // that would overlap with this job.
        int s_min = job_l - d + 1;
        int s_max = job_r;

        // Clip the range to valid start days [1, max_start_day].
        s_min = max(1, s_min);
        s_max = min(max_start_day, s_max);

        // If the resulting range is valid, mark the changes.
        if (s_min <= s_max) {
            diff[s_min]++;
            diff[s_max + 1]--;
        }
    }

    int max_overlap = -1;
    int brother_start = 1;
    int min_overlap = k + 1;
    int mother_start = 1;
    int current_overlap = 0;

    // Iterate through all possible start days to find the best ones.
    for (int s = 1; s <= max_start_day; ++s) {
        // Calculate the overlap count for day 's' by adding the change.
        current_overlap += diff[s];

        // Check for new maximum (brother)
        if (current_overlap > max_overlap) {
            max_overlap = current_overlap;
            brother_start = s;
        }

        // Check for new minimum (mother)
        if (current_overlap < min_overlap) {
            min_overlap = current_overlap;
            mother_start = s;
        }
    }

    cout << brother_start << " " << mother_start << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        solve();
    }

    return 0;
}
