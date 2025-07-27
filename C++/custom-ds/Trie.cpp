#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode *children[26];
    bool end = false;

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
    TrieNode *root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string &word) {
        TrieNode *itr = root;
        for (auto &ch: word) {
            int idx = ch - 'a';
            if (itr->children[idx] == nullptr) {
                itr->children[idx] = new TrieNode();
            }
            itr = itr->children[idx];
        }
        itr->end = true;
    }

    bool search(string &word) {
        TrieNode *itr = root;
        for (auto &ch: word) {
            int idx = ch - 'a';
            if (itr->children[idx] == nullptr) {
                return false;
            }
            itr = itr->children[idx];
        }
        return itr->end;
    }

    bool start_with(string &word) {
        TrieNode *itr = root;
        for (auto &ch: word) {
            int idx = ch - 'a';
            if (itr->children[idx] == nullptr) {
                return false;
            }
            itr = itr->children[idx];
        }
        return true;
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}
