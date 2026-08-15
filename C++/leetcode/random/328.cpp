/**
 * 328
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

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {
    }

    ListNode(int x) : val(x), next(nullptr) {
    }

    ListNode(int x, ListNode *next) : val(x), next(next) {
    }
};

class Solution {
public:
    ListNode *oddEvenList(ListNode *head) {
        if (!head || !head->next) {
            return head;
        }
        auto odd = head;
        auto even = head->next;
        auto ptr1 = head;
        auto ptr2 = head->next;
        while (odd && even) {
            odd->next = even->next;
            if (odd->next) {
                even->next = odd->next->next;
            }
            odd = odd->next;
            even = even->next;
        }
        while (ptr1->next) ptr1 = ptr1->next;
        ptr1->next = ptr2;
        return head;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Solution sol;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);
    head->next->next->next->next->next->next->next = new ListNode(8);

    auto res = sol.oddEvenList(head);
    // auto res = head;
    while (res) {
        cout << res->val << " ";
        res = res->next;
    }
    return 0;
}
