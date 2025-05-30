package leetcode.java.tree.countgoodnodesinbinarytree;

import leetcode.java.tree.TreeNode;

public class Solution1 {
  // because root is always good node

  /**
   * 3
   * 1   4
   */
  public int goodNodes(TreeNode root) {
    if (root == null) {
      return 0;
    }
    return countGoodNodes(root, Integer.MIN_VALUE);
  }

  private int countGoodNodes(TreeNode node, int lastNodeVal) {
    if (node == null) {
      return 0;
    }
    if (node.val >= lastNodeVal) {
      return 1 + countGoodNodes(node.left, node.val) + countGoodNodes(node.right, node.val);
    }
    return countGoodNodes(node.left, lastNodeVal) + countGoodNodes(node.right, lastNodeVal);
  }

  public static void main(String[] args) {
    var tree = new TreeNode(9);
    tree.right = new TreeNode(3);
    tree.right.left = new TreeNode(6);
    System.out.println(tree);
    System.out.println(new Solution1().goodNodes(tree));
  }
}
