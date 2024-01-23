package leetcode.java.tree.serializeanddeserializebinarytree;

import leetcode.java.tree.TreeNode;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

public class Solution1 {

  // Encodes a tree to a single string.
  public String serialize(TreeNode root) {
    List<Integer> nodes = new ArrayList<>();
    inorderTraversalWithNull(root, nodes);
    return nodes.stream().map(String::valueOf).collect(Collectors.joining(","));
  }

  private void inorderTraversalWithNull(TreeNode node, List<Integer> nodes) {
    nodes.add(node == null ? null : node.val);
    if (node == null) {
      return;
    }
    inorderTraversalWithNull(node.left, nodes);
    inorderTraversalWithNull(node.right, nodes);
  }

  // Decodes your encoded data to tree.
  public TreeNode deserialize(String data) {
    String[] tokens = data.split(",");
    return deserialize(tokens);
  }

  int index = 0;

  public TreeNode deserialize(String[] nodes) {
    if ("null".equals(nodes[index])) {
      index++;
      return null;
    }
    var curr = new TreeNode(Integer.parseInt(nodes[index]));
    index++;
    curr.left = deserialize(nodes);
    curr.right = deserialize(nodes);
    return curr;
  }

  public static void main(String[] args) {
    var tree = TreeNode.exampleTree();
    System.out.println(tree);
    var str = new Solution1().serialize(tree);
    System.out.println(str);
    System.out.println(new Solution1().deserialize(str));
  }
}
