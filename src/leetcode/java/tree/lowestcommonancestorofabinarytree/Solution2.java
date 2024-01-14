package leetcode.java.tree.lowestcommonancestorofabinarytree;

import leetcode.java.tree.TreeNode;

import java.util.*;

/**
 * TO SOLVE THIS PROBLEM ITERATIVELY
 * WE HAVE TO STORE PARENTS FOR EACH NODE
 * TO TRAVERSE BACK UNTIL WE FIND COMMON ANCESTOR
 */
public class Solution2 {
  public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
    Map<TreeNode, TreeNode> childToParent = new HashMap<>();
    Deque<TreeNode> stack = new ArrayDeque<>();
    stack.push(root);
    childToParent.put(root, null);
    while (!childToParent.containsKey(p) || !childToParent.containsKey(q)) {
      var curr = stack.pop();
      if (curr.left != null) {
        stack.push(curr.left);
        childToParent.put(curr.left, curr);
      }
      if (curr.right != null) {
        stack.push(curr.right);
        childToParent.put(curr.right, curr);
      }
    }
    Set<TreeNode> ancestors = new HashSet<>();
    while (p != null) {
      ancestors.add(p);
      p = childToParent.get(p);
    }
    while (q != null) {
      if (ancestors.contains(q)) {
        return q;
      }
      q = childToParent.get(q);
    }
    return null;
  }
}
