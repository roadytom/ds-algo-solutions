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
struct Info {
    int rating;
    string food;

    bool operator<(const Info &other) const {
        if (rating != other.rating) return rating < other.rating;
        return food > other.food;
    }
};

class FoodRatings {
public:
    map<string, string> food_to_cuisine;
    map<string, set<Info> > cuisine_to_foods;
    map<string, int> food_to_rating;

    FoodRatings(vector<string> &foods, vector<string> &cuisines, vector<int> &ratings) {
        for (int i = 0; i < len(foods); i++) {
            auto &food = foods[i];
            auto &cuisine = cuisines[i];
            auto &rating = ratings[i];
            food_to_cuisine[food] = cuisine;
            food_to_rating[food] = rating;
            cuisine_to_foods[cuisine].insert({rating, food});
        }
    }

    void changeRating(string food, int new_rating) {
        auto &cuisine = food_to_cuisine[food];
        auto &cuisine_set = cuisine_to_foods[cuisine];
        int old_rating = food_to_rating[food];
        cuisine_set.erase({old_rating, food});
        cuisine_set.insert({new_rating, food});
        food_to_rating[food] = new_rating;
    }

    string highestRated(string cuisine) {
        const auto &[rating, food] = *cuisine_to_foods[cuisine].rbegin();
        return food;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // Solution s;
    // debug(s.solve());
    return 0;
}
