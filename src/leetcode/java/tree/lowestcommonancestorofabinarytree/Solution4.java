package leetcode.java.tree.lowestcommonancestorofabinarytree;

import leetcode.java.tree.TreeNode;

import java.util.ArrayDeque;
import java.util.Deque;

/**
 * THE SAME AS SOLUTION3
 * BUT USING EASIER WAYS FOR DOING
 * POST-ORDER
 */
public class Solution4 {
  public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
    if (root == null) {
      return null;
    }
    TreeNode leftLCA = null;
    TreeNode rightLCA = null;
    Deque<TreeNode> stack = new ArrayDeque<>();
    TreeNode curr = root;
    TreeNode lastVisited = null;
    while (curr != null || !stack.isEmpty()) {
      while (curr != null) {
        stack.push(curr);
        curr = curr.left;
      }
      TreeNode peek = stack.peek();
      if (peek.right != null && peek.right != lastVisited) {
        curr = peek.right;
      } else {
        var popped = stack.pop();
        if (popped.val == p.val || popped.val == q.val) {
          if (leftLCA == null) {
            leftLCA = popped;
          } else {
            rightLCA = popped;
          }
        }
        if (leftLCA != null && leftLCA == rightLCA) {
          return popped;
        }
        if (popped == leftLCA) {
          leftLCA = stack.peek();
        } else if (popped == rightLCA) {
          rightLCA = stack.peek();
        }
        lastVisited = popped;
      }
    }
    return null;
  }
}
