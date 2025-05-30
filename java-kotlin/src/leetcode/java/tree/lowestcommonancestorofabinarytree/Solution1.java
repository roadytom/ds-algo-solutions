package leetcode.java.tree.lowestcommonancestorofabinarytree;

import leetcode.java.tree.TreeNode;

public class Solution1 {
  private TreeNode lowestCommonAncestor = null;

  public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
    findLowestCommonAncestor(root, p, q);
    return lowestCommonAncestor;
  }

  private boolean findLowestCommonAncestor(TreeNode node, TreeNode p, TreeNode q) {
    if (node == null) {
      return false;
    }
    var left = findLowestCommonAncestor(node.left, p, q);
    var right = findLowestCommonAncestor(node.right, p, q);
    if (node.val == p.val || node.val == q.val || (left && right)) {
      if (left || right) {
        lowestCommonAncestor = node;
      }
      return true;
    }
    return left || right;
  }
}
