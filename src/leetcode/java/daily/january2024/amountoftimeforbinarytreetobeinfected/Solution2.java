package leetcode.java.daily.january2024.amountoftimeforbinarytreetobeinfected;

import leetcode.java.tree.TreeNode;

public class Solution2 {
  private int maxDistance = 0;

  public int amountOfTime(TreeNode root, int start) {
    findAmountOfTime(root, start);
    return maxDistance;
  }

  private int findAmountOfTime(TreeNode root, int start) {
    if (root == null) {
      return 0;
    }
    int depth = 0;
    int leftDepth = findAmountOfTime(root.left, start);
    int rightDepth = findAmountOfTime(root.right, start);
    if (root.val == start) {
      // we found infected node
      maxDistance = Math.max(leftDepth, rightDepth);
      depth = -1;
    } else if (leftDepth >= 0 && rightDepth >= 0) {
      // in subtree there is no infected element
      depth = Math.max(leftDepth, rightDepth) + 1;
    } else {
      int distance = Math.abs(leftDepth) + Math.abs(rightDepth);
      maxDistance = Math.max(maxDistance, distance);
      // negative value if always min, and it is the distance between
      // curr node to infected node
      depth = Math.min(leftDepth, rightDepth) - 1;
    }
    return depth;
  }

  public static void main(String[] args) {
    var five = new TreeNode(5);
    var three = new TreeNode(3);
    var six = new TreeNode(6);
    var two = new TreeNode(2);
    var four = new TreeNode(4);
    var one = new TreeNode(1);
    var tree = five;
    five.left = three;
    five.right = six;
    three.left = two;
    three.right = four;
    two.left = one;
    System.out.println(tree);
  }
}
