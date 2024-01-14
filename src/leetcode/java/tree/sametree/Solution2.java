package leetcode.java.tree.sametree;

import leetcode.java.tree.TreeNode;

import java.util.Deque;
import java.util.LinkedList;

public class Solution2 {
  public boolean isSameTree(TreeNode p, TreeNode q) {
    Deque<TreeNode> pStack = new LinkedList<>();
    Deque<TreeNode> qStack = new LinkedList<>();
    pStack.push(p);
    qStack.push(q);
    while (!pStack.isEmpty() || !qStack.isEmpty()) {
      p = pStack.poll();
      q = qStack.poll();
      if (!check(p, q)) {
        return false;
      }
      if (p != null) {
        pStack.push(p.left);
        pStack.push(p.right);
        qStack.push(q.left);
        qStack.push(q.right);
      }
    }
    return true;
  }

  private boolean check(TreeNode p, TreeNode q) {
    if (p == null && q == null) {
      return true;
    } else if (p == null || q == null) {
      return false;
    }
    return p.val == q.val;
  }
}
