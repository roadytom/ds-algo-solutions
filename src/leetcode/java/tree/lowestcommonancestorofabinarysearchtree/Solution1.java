package leetcode.java.tree.lowestcommonancestorofabinarysearchtree;

import leetcode.java.tree.TreeNode;

/**
 * if it is binary search tree
 * we can use binary search like
 * logic
 */
public class Solution1 {
  public TreeNode lowestCommonAncestor(TreeNode node, TreeNode p, TreeNode q) {
    if (node == null) {
      return null;
    }
    var currVal = node.val;
    var leftVal = p.val;
    var rightVal = q.val;
    if (currVal < leftVal && currVal < rightVal) {
      return lowestCommonAncestor(node.right, p, q);
    } else if (currVal > leftVal && currVal > rightVal) {
      return lowestCommonAncestor(node.left, p, q);
    }
    return node;
  }
}
