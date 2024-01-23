package leetcode.java.tree.inordertraversal;

import leetcode.java.tree.TreeNode;

import java.util.*;

public class Solution2 {
  public List<Integer> inorderTraversal(TreeNode root) {
    if (root == null) {
      return Collections.emptyList();
    }
    List<Integer> answer = new ArrayList<>();
    Deque<TreeNode> stack = new ArrayDeque<>();
    TreeNode curr = root;
    while (curr != null || !stack.isEmpty()) {
      while (curr != null) {
        stack.push(curr);
        curr = curr.left;
      }
      curr = stack.pop();
      answer.add(curr.val);
      curr = curr.right;
    }
    return answer;
  }

  public static void main(String[] args) {
    var tree = TreeNode.exampleTree();
    System.out.println(tree);
    System.out.println(new Solution2().inorderTraversal(tree));
  }
}
