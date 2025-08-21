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

struct TrieNode {
    map<string, TrieNode *> children;
    int value = -1;
    bool end = false;

    TrieNode() = default;

    TrieNode(int value, bool end)
        : value(value),
          end(end) {
    }
};

class Trie {
    TrieNode *root;

public:
    Trie() {
        root = new TrieNode();
    }

    static const char delimiter = '/';
    static char buf[450 << 20];

    void *operator new(size_t s) {
        static size_t i = sizeof buf;
        assert(s < i);
        return &buf[i -= s];
    }

    void operator delete(void *) {
    }

    void insert(const string &word, int value) const {
        TrieNode *itr = root;
        string token;
        for (int i = 1; i < len(word); i++) {
            auto ch = word[i];
            if (ch == delimiter) {
                if (!itr->children.contains(token)) {
                    itr->children[token] = new TrieNode();
                }
                itr = itr->children[token];
                token = "";
            } else {
                token += ch;
            }
        }
        if (!token.empty()) {
            if (!itr->children.contains(token)) {
                itr->children[token] = new TrieNode();
            }
            itr = itr->children[token];
        }


        itr->value = value;
        itr->end = true;
    }

    TrieNode *search(const string &word) const {
        TrieNode *itr = root;
        string token;
        for (int i = 1; i < len(word); i++) {
            auto ch = word[i];
            if (ch == delimiter) {
                if (!itr->children.contains(token)) {
                    return nullptr;
                }
                itr = itr->children[token];
                token = "";
            } else {
                token += ch;
            }
        }
        if (!token.empty()) {
            if (!itr->children.contains(token)) {
                return nullptr;
            }
            itr = itr->children[token];
        }
        return itr;
    }

    bool start_with(const string &word) const {
        TrieNode *itr = root;
        string token;
        for (int i = 1; i < len(word); i++) {
            auto ch = word[i];
            if (ch == delimiter) {
                if (!itr->children.contains(token)) {
                    return false;
                }
                itr = itr->children[token] = new TrieNode();
                token = "";
            } else {
                token += ch;
            }
        }
        return true;
    }
};

class FileSystem {
public:
    Trie node{};

    FileSystem() {
    }

    bool createPath(string path, int value) {
        auto pos = path.rfind("/");
        if (pos == string::npos) return false;
        string parent = path.substr(0, pos);
        string child = path.substr(pos + 1);
        auto p = node.search(parent);
        if (p == nullptr) return false;
        if (p->children.contains(child)) return false;
        p->children[child] = new TrieNode(value, true);
        return true;
    }

    int get(string path) {
        TrieNode *res = node.search(path);
        if (res == nullptr) return -1;
        return res->value;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    FileSystem *obj = new FileSystem();
    debug(obj->createPath("/leet", 1));
    debug(obj->createPath("/leet/code", 2));
    debug(obj->get("/leet/code"));
    debug(obj->createPath("/leet/code", 3));
    debug(obj->get("/leet/code"));

    return 0;
}
