package leetcode.java.tree.preordertraversal;

import leetcode.java.tree.TreeNode;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Solution1 {
  public List<Integer> preorderTraversal(TreeNode root) {
    if (root == null) {
      return Collections.emptyList();
    }
    List<Integer> answer = new ArrayList<>();
    preorderTraversal(root, answer);
    return answer;
  }

  public void preorderTraversal(TreeNode node, List<Integer> result) {
    if (node == null) {
      return;
    }
    result.add(node.val);
    preorderTraversal(node.left, result);
    preorderTraversal(node.right, result);
  }
}
