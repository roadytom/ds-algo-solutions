package leetcode.java.tree.lowestcommonancestorofabinarysearchtree;

import leetcode.java.tree.TreeNode;

/**
 * THE SAME LOGIC
 * with iterative approach
 */
public class Solution2 {
  public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
    while (root != null) {
      if (root.val > p.val && root.val > q.val) {
        root = root.left;
      } else if (root.val < p.val && root.val < q.val) {
        root = root.right;
      } else {
        return root;
      }
    }
    return null;
  }
}
