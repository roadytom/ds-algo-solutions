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
class TaskManager {
public:
    map<int, int> task_to_priority;
    map<int, int> task_to_user;
    set<pair<int, int>> task_and_priority;

    explicit TaskManager(vector<vector<int>>& tasks) {
        for (auto &row: tasks) {
            int user_id = row[0], task_id = row[1], priority = row[2];
            task_to_priority[task_id] = priority;
            task_to_user[task_id] = user_id;
            task_and_priority.emplace(priority, task_id);
        }
    }

    void add(int user_id, int task_id, int priority) {
        task_to_priority[task_id] = priority;
        task_and_priority.emplace(priority, task_id);
        task_to_user[task_id] = user_id;
    }

    void edit(int task_id, int new_priority) {
        auto &old_priority = task_to_priority[task_id];
        task_and_priority.erase({old_priority, task_id});
        task_and_priority.emplace(new_priority, task_id);
        task_to_priority[task_id] = new_priority;
    }

    void rmv(int task_id) {
        auto &old_priority = task_to_priority[task_id];
        task_and_priority.erase({old_priority, task_id});
        task_to_priority.erase(task_id);
        task_to_user.erase(task_id);
    }

    int execTop() {
        if (task_and_priority.empty()) return -1;
        auto &[priority, task_id] = *task_and_priority.rbegin();
        int user_id = task_to_user[task_id];
        rmv(task_id);
        return user_id;
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
