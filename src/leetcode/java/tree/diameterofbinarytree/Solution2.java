package leetcode.java.tree.diameterofbinarytree;

import leetcode.java.tree.TreeNode;
import leetcode.java.util.Pair;

public class Solution2 {
  private int diameter = 0;

  public int diameterOfBinaryTree(TreeNode node) {
    if (node == null) {
      return 0;
    }
    findMaxDepth(node);
    return diameter;
  }

  public int findMaxDepth(TreeNode node) {
    if (node == null) {
      return 0;
    }
    var left = findMaxDepth(node.left);
    var right = findMaxDepth(node.right);
    diameter = Math.max(diameter, left + right);
    return Math.max(left, right) + 1;
  }
}
