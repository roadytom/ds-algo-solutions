package leetcode.java.tree.inordertraversal;

import leetcode.java.tree.TreeNode;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Solution1 {
  public List<Integer> inorderTraversal(TreeNode root) {
    if (root == null) {
      return Collections.emptyList();
    }
    List<Integer> answer = new ArrayList<>();
    inorderTraversal(root, answer);
    return answer;
  }

  public void inorderTraversal(TreeNode node, List<Integer> answer) {
    if (node == null) {
      return;
    }
    inorderTraversal(node.left, answer);
    answer.add(node.val);
    inorderTraversal(node.right, answer);
  }
}
