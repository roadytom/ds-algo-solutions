package leetcode.java.tree.kthsmallestelementinbst;

import leetcode.java.tree.TreeNode;

public class Solution1 {
  public int index = 1;

  public int kthSmallest(TreeNode root, int k) {
    if (root == null) {
      return Integer.MAX_VALUE;
    }

    var left = kthSmallest(root.left, k);
    if (index++ == k) {
      return root.val;
    }
    var right = kthSmallest(root.right, k);
    return Math.min(left, right);
  }

  public static void main(String[] args) {
    System.out.println(TreeNode.exampleTree());
    System.out.println(new Solution1().kthSmallest(TreeNode.exampleTree(), 3));
  }
}
