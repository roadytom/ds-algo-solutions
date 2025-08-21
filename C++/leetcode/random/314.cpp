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
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {
    }

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {
    }
};

class Solution {
public:
    pair<int, int> get_col_length(TreeNode *root) {
        auto itr = root;
        int left = 0;
        while (itr != nullptr) {
            left++;
            itr = itr->left;
        }
        int right = 0;
        itr = root->right;
        while (itr != nullptr) {
            right++;
            itr = itr->right;
        }
        return {left, right};
    }

    int get_depth(TreeNode *node) {
        if (node == nullptr) return 0;
        return max(get_depth(node->left), get_depth(node->right)) + 1;
    }

    int id = 0;
    map<pair<int, int>, vector<pair<int, int> > > ans;

    void dfs(TreeNode *node, int col, int row) {
        pair<int, int> key{col, row};
        ans[key].emplace_back(id, node->val);
        if (node->left != nullptr) {
            id++;
            dfs(node->left, col - 1, row + 1);
        }
        if (node->right != nullptr) {
            id++;
            dfs(node->right, col + 1, row + 1);
        }
    }

    vector<vector<int> > verticalOrder(TreeNode *root) {
        if (root == nullptr) return {};
        auto res = get_col_length(root);
        int row = get_depth(root);

        debug(res);
        dfs(root, res.first - 1, 0);
        vector<vector<int> > ret;
        for (int i = 0; i < res.first + res.second; i++) {
            vector<int> ret_row;
            for (int j = 0; j < row; j++) {
                pair<int, int> key{i, j};
                auto &vals = ans[key];
                sort(all(vals));
                for (auto &[_, val]: vals) {
                    ret_row.push_back(val);
                }
            }
            ret.emplace_back(ret_row);
        }
        return ret;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Solution s;
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20, new TreeNode(15), new TreeNode(7));
    debug(s.verticalOrder(root));
    return 0;
}
