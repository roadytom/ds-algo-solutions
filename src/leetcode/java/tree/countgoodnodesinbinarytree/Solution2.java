package leetcode.java.tree.countgoodnodesinbinarytree;

import leetcode.java.tree.TreeNode;
import leetcode.java.util.Pair;

import java.util.ArrayDeque;

public class Solution2 {
  public int goodNodes(TreeNode root) {
    if (root == null) {
      return 0;
    }
    var goodNodes = 0;
    var stack = new ArrayDeque<Pair<TreeNode, Integer>>();
    stack.push(new Pair<>(root, Integer.MIN_VALUE));
    while (!stack.isEmpty()) {
      var curr = stack.pop();
      var largestNode = curr.getValue();
      if (curr.getKey().val >= curr.getValue()) {
        goodNodes++;
        largestNode = curr.getKey().val;
      }
      if (curr.getKey().left != null) {
        stack.push(new Pair<>(curr.getKey().left, largestNode));
      }
      if (curr.getKey().right != null) {
        stack.push(new Pair<>(curr.getKey().right, largestNode));
      }
    }
    return goodNodes;
  }
}
