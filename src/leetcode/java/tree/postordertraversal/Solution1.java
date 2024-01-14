package leetcode.java.tree.postordertraversal;

import leetcode.java.tree.TreeNode;
import leetcode.java.util.Pair;

import java.util.*;

public class Solution1 {
  public List<Integer> postorderTraversal(TreeNode root) {
    if (root == null) {
      return Collections.emptyList();
    }
    List<Integer> list = new ArrayList<>();
    final int BOTH_PENDING = 0;
    final int LEFT_DONE = 1;
    final int BOTH_DONE = 2;
    Deque<Pair<TreeNode, Integer>> stack = new ArrayDeque<>();
    stack.push(new Pair<>(root, BOTH_PENDING));
    while (!stack.isEmpty()) {
      var curr = stack.peek();
      if (curr.getKey() == null) {
        stack.pop();
        continue;
      }
      if (curr.getValue() == BOTH_DONE) {
        stack.pop();
        list.add(curr.getKey().val);
      } else if (curr.getValue() == LEFT_DONE) {
        stack.pop();
        stack.push(new Pair<>(curr.getKey(), BOTH_DONE));
        stack.push(new Pair<>(curr.getKey().right, BOTH_PENDING));
      } else {
        stack.pop();
        stack.push(new Pair<>(curr.getKey(), LEFT_DONE));
        stack.push(new Pair<>(curr.getKey().left, BOTH_PENDING));
      }
    }
    return list;
  }
}
