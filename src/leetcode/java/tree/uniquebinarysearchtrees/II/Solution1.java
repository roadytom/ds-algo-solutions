package leetcode.java.tree.uniquebinarysearchtrees.II;

import leetcode.java.tree.TreeNode;

import java.util.ArrayList;
import java.util.List;


public class Solution1 {
  public List<TreeNode> generateTrees(int n) {
    List<List<List<TreeNode>>> memo = new ArrayList<>();
    for (int i = 0; i <= n; i++) {
      List<List<TreeNode>> row = new ArrayList<>();
      for (int j = 0; j <= n; j++) {
        row.add(null);
      }
      memo.add(row);
    }
    return generateTrees(1, n, memo);
  }

  public List<TreeNode> generateTrees(int left, int right, List<List<List<TreeNode>>> memo) {
    if (left > right) {
      List<TreeNode> list = new ArrayList<>();
      list.add(null);
      return list;
    } else if (left == right) {
      return List.of(new TreeNode(left));
    }
    if (memo.get(left).get(right) != null) {
      return memo.get(left).get(right);
    }
    List<TreeNode> list = new ArrayList<>();
    for (int root = left; root <= right; root++) {
      createNewTree(root, generateTrees(left, root - 1, memo), generateTrees(root + 1, right, memo), list);
    }
    memo.get(left).set(right, list);
    return memo.get(left).get(right);
  }

  private void createNewTree(int root, List<TreeNode> leftNodes, List<TreeNode> rightNodes, List<TreeNode> list) {
    for (TreeNode left : leftNodes) {
      for (TreeNode right : rightNodes) {
        TreeNode rootNode = new TreeNode(root);
        rootNode.left = left;
        rootNode.right = right;
        list.add(rootNode);
      }
    }
  }

  public static void main(String[] args) {
    new Solution1().generateTrees(3).forEach(System.out::println);
  }
}
