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
    bool get_bit(int n, int pos) {
        return n & (1 << pos);
    }

    vector<string> spellchecker(vector<string> &wordlist, vector<string> &queries) {
        set<char> vowels{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        map<string, int> words;
        for (int i = 0; i < len(wordlist); i++) {
            auto word = wordlist[i];
            for (char &c: word) {
                c = (char) tolower(c);
            }
            if (words.count(word)) continue;
            words[word] = i;
        }
        v<string> ans(len(queries), "");

        function<bool(int, string &, int, string &)> check_vowel_errors = [&
                ](int idx, string &query, int q, string &curr) {
            if (idx >= (int) query.size()) {
                if (words.count(query)) {
                    ans[q] = wordlist[words[query]];
                    return true;
                }
                return false;
            }
            bool res;
            if (!vowels.count(query[idx])) {
                curr.push_back((char) tolower(query[idx]));
                res = check_vowel_errors(idx + 1, query, q, curr);
                if (res) return true;
                curr.pop_back();
                curr.push_back((char) toupper(query[idx]));
                res = check_vowel_errors(idx + 1, query, q, curr);
                if (res) return true;
                curr.pop_back();
            }
            for (char vowel: vowels) {
                curr.push_back(vowel);
                res = check_vowel_errors(idx + 1, query, q, curr);
                if (res) return true;
                curr.pop_back();
            }
            return false;
        };


        for (int q = 0; q < len(queries); q++) {
            bool found = false;
            auto &query = queries[q];
            // exact match:
            if (words.count(query)) {
                ans[q] = wordlist[words[query]];
                found = true;
            }
            if (found) continue;
            // case match:
            auto s = query;
            int n = len(s);
            for (int i = 0; i < (1 << n); i++) {
                for (int j = 0; j < n; j++) {
                    if (get_bit(i, j)) {
                        s[j] = (char) toupper(s[j]);
                    } else {
                        s[j] = (char) tolower(s[j]);
                    }
                }
                if (words.count(s)) {
                    ans[q] = wordlist[words[s]];
                    found = true;
                    break;
                }
            }
            if (found) continue;
            string temp;
            check_vowel_errors(0, query, q, temp);
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Solution s;
    v<string> arg1{"zeo", "Zuo"};
    v<string> arg2{"zuo"};
    debug(s.spellchecker(arg1, arg2));
    return 0;
}
