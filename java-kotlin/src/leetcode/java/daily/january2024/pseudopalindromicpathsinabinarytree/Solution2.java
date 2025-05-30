package leetcode.java.daily.january2024.pseudopalindromicpathsinabinarytree;

import leetcode.java.tree.TreeNode;
import leetcode.java.util.Pair;

import java.util.ArrayDeque;
import java.util.Deque;

/**
 * Iterative PreOrder Traversal
 * using bitset instead of set or array
 * to store frequency
 */
public class Solution2 {
  public int pseudoPalindromicPaths(TreeNode root) {
    if (root == null) {
      return 0;
    }
    int countPaths = 0;
    Deque<Pair<TreeNode, Integer>> stack = new ArrayDeque<>();
    stack.push(new Pair<>(root, 0));
    while (!stack.isEmpty()) {
      var curr = stack.pop();
      var currNode = curr.getKey();
      var currBitSet = curr.getValue();
      currBitSet ^= (1 << currNode.val);
      if (currNode.left == null && currNode.right == null) {
        if ((currBitSet & (currBitSet - 1)) == 0) {
          countPaths++;
        }
      } else {
        if (currNode.left != null) {
          stack.push(new Pair<>(currNode.left, currBitSet));
        }
        if (currNode.right != null) {
          stack.push(new Pair<>(currNode.right, currBitSet));
        }
      }
    }
    return countPaths;
  }

  private static class BitSet {
    int bitSet = 0;

    public void toggle(int num) {
      bitSet ^= (1 << num);
    }

    public boolean isPowerOfTwo() {
      return (bitSet & (bitSet - 1)) == 0;
    }
  }
}
