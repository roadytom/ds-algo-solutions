package leetcode.java.tree.diameterofbinarytree;

import leetcode.java.tree.TreeNode;
import leetcode.java.util.Pair;

public class Solution1 {
  public int diameterOfBinaryTree(TreeNode node) {
    if (node == null) {
      return 0;
    }
    return findMaxDepth(node).getValue();
  }

  public Pair<Integer, Integer> findMaxDepth(TreeNode node) {
    if (node == null) {
      return new Pair<>(0, 0);
    }
    var left = findMaxDepth(node.left);
    var right = findMaxDepth(node.right);
    return new Pair<>(
        Math.max(left.getKey(), right.getKey()) + 1,
        Math.max(
            Math.max(left.getValue(), right.getValue()),
            left.getKey() + right.getKey()
        )
    );
  }
}

