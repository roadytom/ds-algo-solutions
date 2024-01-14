package leetcode.java.tree.invertbinarytree;

import leetcode.java.tree.TreeNode;

import java.util.ArrayDeque;

public class Solution2 {
  public TreeNode invertTree(TreeNode root) {
    if (root == null) {
      return null;
    }
    var queue = new ArrayDeque<TreeNode>();
    queue.offer(root);
    while (!queue.isEmpty()) {
      var curr = queue.pop();
      var temp = curr.left;
      curr.left = curr.right;
      curr.right = temp;
      if (curr.left != null) {
        queue.offer(curr.left);
      }
      if (curr.right != null) {
        queue.offer(curr.right);
      }
    }
    return root;
  }

  public static void main(String[] args) {
    var tree = TreeNode.exampleTree();
    System.out.println(tree);
    new Solution2().invertTree(tree);
    System.out.println(tree);
  }
}
