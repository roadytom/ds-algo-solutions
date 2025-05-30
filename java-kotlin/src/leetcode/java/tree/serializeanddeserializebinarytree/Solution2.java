package leetcode.java.tree.serializeanddeserializebinarytree;

import leetcode.java.tree.TreeNode;

import java.util.*;
import java.util.stream.Collectors;

/**
 * USING BFS
 */
public class Solution2 {
  public String serialize(TreeNode root) {
    if (root == null) {
      return "";
    }
    List<Integer> list = new ArrayList<>();
    bfsSerialize(root, list);
    return list.stream().map(String::valueOf).collect(Collectors.joining(","));
  }

  private void bfsSerialize(TreeNode root, List<Integer> list) {
    Queue<TreeNode> q = new LinkedList<>();
    q.offer(root);
    while (!q.isEmpty()) {
      var curr = q.poll();
      if (curr == null) {
        list.add(null);
      } else {
        list.add(curr.val);
        q.offer(curr.left);
        q.offer(curr.right);
      }
    }
  }

  // Decodes your encoded data to tree.
  public TreeNode deserialize(String data) {
    if (data.isEmpty()) {
      return null;
    }
    int index = 0;
    String[] tokens = data.split(",");
    Queue<TreeNode> q = new ArrayDeque<>();
    TreeNode root = new TreeNode(Integer.parseInt(tokens[index++]));
    q.offer(root);
    while (!q.isEmpty()) {
      var parent = q.poll();
      if (!tokens[index].equals("null")) {
        parent.left = new TreeNode(Integer.parseInt(tokens[index]));
        q.offer(parent.left);
      }
      index++;
      if (!tokens[index].equals("null")) {
        parent.right = new TreeNode(Integer.parseInt(tokens[index]));
        q.offer(parent.right);
      }
      index++;
    }
    return root;
  }

  public static void main(String[] args) {
    var solution = new Solution2();
    var tree = TreeNode.exampleTree();
    System.out.println(tree);
    System.out.println(solution.serialize(tree));
    var deserializedTree = solution.deserialize(solution.serialize(tree));
    System.out.println(deserializedTree);
  }
}
