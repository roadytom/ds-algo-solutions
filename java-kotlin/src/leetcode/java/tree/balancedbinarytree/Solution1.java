package leetcode.java.tree.balancedbinarytree;

import leetcode.java.tree.TreeNode;

public class Solution1 {
  private boolean isBalanced = true;

  public boolean isBalanced(TreeNode root) {
    if (root == null) {
      return true;
    }
    checkIfDepth(root);
    return isBalanced;
  }

  private int checkIfDepth(TreeNode node) {
    if (node == null) {
      return 0;
    }
    var left = checkIfDepth(node.left);
    var right = checkIfDepth(node.right);
    if (Math.abs(left - right) >= 2) {
      isBalanced = false;
    }
    return Math.max(left, right) + 1;
  }
}
