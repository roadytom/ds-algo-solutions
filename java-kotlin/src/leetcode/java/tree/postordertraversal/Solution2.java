package leetcode.java.tree.postordertraversal;

import leetcode.java.tree.TreeNode;

import java.util.*;

/**
 * AGAIN POST ORDER TRAVERSAL
 * USING ITERATION WITHOUT STATES
 */
public class Solution2 {
  public List<Integer> postorderTraversal(TreeNode root) {
    if (root == null) {
      return Collections.emptyList();
    }
    List<Integer> answer = new ArrayList<>();
    Deque<TreeNode> stack = new ArrayDeque<>();
    TreeNode lastVisited = null;
    TreeNode current = root;
    while (current != null || !stack.isEmpty()) {
      while (current != null) {
        stack.push(current);
        current = current.left;
      }
      TreeNode peekNode = stack.peek();
      if (peekNode.right != null && peekNode.right != lastVisited) {
        current = peekNode.right;
      } else {
        answer.add(peekNode.val);
        lastVisited = stack.pop();
      }
    }
    return answer;
  }
}
