package leetcode.java.tree.lowestcommonancestorofabinarytree;

import leetcode.java.tree.TreeNode;
import leetcode.java.util.Pair;

import java.util.ArrayDeque;
import java.util.Deque;

/**
 * ITERATIVE SOLUTION WITHOUT BACKTRACKING
 * JUST STORE POSSIBLE LCA INDEX FOR LEFT AND RIGHT
 * AND WHILE DOING POST-ORDER AND
 * VISITING NODE, WE CHECK IF LEFTLCA AND RIGHTLCA
 * INTERSECT IF YES, WE FOUND OTHERWISE WE CONTINUE.
 * IF WE POPPING LEFT OR RIGHT LCA, WE HAVE TO UPDATE IT
 * TO THE PEEK OF THE STACK WHICH IS PARENT OF THIS NODE
 */
public class Solution3 {
  public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
    if (root == null) {
      return null;
    }
    final int BOTH_PENDING = 0;
    final int LEFT_DONE = 1;
    final int BOTH_DONE = 2;
    int found = 0;
    TreeNode leftLCA = null;
    TreeNode rightLCA = null;
    Deque<Pair<TreeNode, Integer>> stack = new ArrayDeque<>();
    stack.push(new Pair<>(root, BOTH_PENDING));
    while (!stack.isEmpty()) {
      var currentNode = stack.peek().getKey();
      var currentState = stack.peek().getValue();
      if (currentState == BOTH_DONE) {
        if (currentNode.val == p.val || currentNode.val == q.val) {
          found++;
          if (found == 1) {
            leftLCA = stack.peek().getKey();
          } else {
            rightLCA = stack.peek().getKey();
          }
        }
        if (found == 2 && leftLCA == rightLCA) {
          return currentNode;
        }
        var popped = stack.pop();
        if (popped.getKey() == leftLCA) {
          leftLCA = stack.peek().getKey();
        } else if (popped.getKey() == rightLCA) {
          rightLCA = stack.peek().getKey();
        }
      } else if (currentState == BOTH_PENDING) {
        stack.pop();
        stack.push(new Pair<>(currentNode, LEFT_DONE));
        if (currentNode.left != null) {
          stack.push(new Pair<>(currentNode.left, BOTH_PENDING));
        }
      } else {
        stack.pop();
        stack.push(new Pair<>(currentNode, BOTH_DONE));
        if (currentNode.right != null) {
          stack.push(new Pair<>(currentNode.right, BOTH_PENDING));
        }
      }
    }
    return null;
  }

  public static void main(String[] args) {
    var tree = TreeNode.exampleTree();
    System.out.println(tree);
    var ans = new Solution3().lowestCommonAncestor(tree, new TreeNode(1), new TreeNode(4));
    System.out.println(ans.val);
  }
}
