package leetcode.java.tree.sametree;

import leetcode.java.tree.TreeNode;

public class Solution1 {
  public boolean isSameTree(TreeNode p, TreeNode q) {
    if (p == null && q == null) {
      return true;
    } else if (p == null || q == null) {
      return false;
    }
    return p.val == q.val && isSameTree(p.left, q.left) && isSameTree(q.right, p.right);
  }
}
