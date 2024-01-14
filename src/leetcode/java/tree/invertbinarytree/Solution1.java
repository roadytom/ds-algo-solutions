package leetcode.java.tree.invertbinarytree;

import leetcode.java.tree.TreeNode;

public class Solution1 {
  public TreeNode invertTree(TreeNode root) {
    if (root == null) {
      return null;
    }
    var temp = root.left;
    root.left = root.right;
    root.right = temp;
    invertTree(root.left);
    invertTree(root.right);
    return root;
  }
}
