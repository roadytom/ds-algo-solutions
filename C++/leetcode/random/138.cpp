/**
 * 138
 * https://leetcode.com/problems/
 */
#include <bits/stdc++.h>
#ifdef LOCAL
#include "algo/debug.hpp"
#else
#define debug(...) 42
#endif
using namespace std;

#define len(x) static_cast<int>((x).size())

// Constants
constexpr long long MOD = 1e9 + 7;
constexpr long long INF = 1e18;
constexpr long long MAXN = 2e6 + 5; // for factorial precomputation etc.

class Node {
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

/**
before:   A  →  B  →  C  →  D
after:    A → A' → B → B' → C → C' → D → D'
 */
class Solution {
public:
    Node *copyRandomList(Node *head) {
        if (!head) return nullptr;
        Node *p = head;
        while (p) {
            Node *new_node = new Node(p->val);
            new_node->next = p->next;
            p->next = new_node;
            p = new_node->next;
        }
        p = head;
        while (p) {
            p->next->random = p->random ? p->random->next : nullptr;
            p = p->next->next;
        }
        Node *new_head = head->next;
        p = head;
        while (p) {
            Node *c = p->next;
            p->next = c->next;
            c->next = p->next ? p->next->next : nullptr;
        }
        return new_head;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Node *a = new Node(3);
    Node *b = new Node(3);
    Node *c = new Node(3);
    Solution sol;
    sol.copyRandomList(head);
    // vector<int> temp{1, 2};
    // debug(sol.method(temp));

    return 0;
}
