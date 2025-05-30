package leetcode.java.tree;

import java.util.Objects;

public class TreeNode {
  public static TreeNode exampleTree() {
    var five = new TreeNode(5);
    var three = new TreeNode(3);
    var six = new TreeNode(6);
    var two = new TreeNode(2);
    var four = new TreeNode(4);
    var one = new TreeNode(1);
    five.left = three;
    five.right = six;
    three.left = two;
    three.right = four;
    two.left = one;
    return five;
  }

  public int val;
  public TreeNode left;
  public TreeNode right;

  TreeNode() {
  }

  public TreeNode(int val) {
    this.val = val;
  }

  TreeNode(int val, TreeNode left, TreeNode right) {
    this.val = val;
    this.left = left;
    this.right = right;
  }

  @Override
  public String toString() {
    return diagram(this, "", "", "");
  }

  public String diagram(TreeNode node, String top, String root, String bottom) {
    if (node != null) {
      if (node.left == null && node.right == null) {
        return root + node.val + "\n";
      } else {
        return diagram(node.right, top + " ", top + "┌──", top + "│ ") +
            root + node.val + "\n" +
            diagram(node.left, bottom + "│ ", bottom + "└──", bottom + " ");
      }
    } else {
      return root + "null\n";
    }
  }

  @Override
  public boolean equals(Object o) {
    if (this == o) return true;
    if (o == null || getClass() != o.getClass()) return false;
    TreeNode treeNode = (TreeNode) o;
    boolean leftEqual;
    if (left == null) {
      leftEqual = treeNode.left == null;
    } else {
      leftEqual = left.equals(treeNode.left);
    }
    boolean rightEqual;
    if (right == null) {
      rightEqual = treeNode.right == null;
    } else {
      rightEqual = right.equals(treeNode.right);
    }

    return val == treeNode.val && leftEqual && rightEqual;
  }

  @Override
  public int hashCode() {
    return Objects.hash(val);
  }
}