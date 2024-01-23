package leetcode.java.tree.subtreeofanothertree;

import leetcode.java.tree.TreeNode;

public class Solution1 {
  public boolean isSubtree(TreeNode root, TreeNode subRoot) {
    if (equals(root, subRoot)) {
      return true;
    }
    return isSubtree(root.left, subRoot) || isSubtree(root.right, subRoot);
  }

  private boolean equals(TreeNode node1, TreeNode node2) {
    if (node1 == null || node2 == null) {
      return node1 == null && node2 == null;
    }

    return node1.val == node2.val && equals(node1.left, node2.left) && equals(node1.right, node2.right);
  }
}
