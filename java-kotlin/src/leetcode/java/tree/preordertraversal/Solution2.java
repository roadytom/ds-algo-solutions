package leetcode.java.tree.preordertraversal;

import leetcode.java.tree.TreeNode;

import java.util.*;

public class Solution2 {
  public List<Integer> preorderTraversal(TreeNode root) {
    if (root == null) {
      return Collections.emptyList();
    }
    List<Integer> answer = new ArrayList<>();
    Deque<TreeNode> stack = new ArrayDeque<>();
    stack.push(root);
    while (!stack.isEmpty()) {
      var curr = stack.pop();
      answer.add(curr.val);
      if (curr.left != null) {
        stack.push(curr.left);
      }
      if (curr.right != null) {
        stack.push(curr.right);
      }
    }
    return answer;
  }
}
