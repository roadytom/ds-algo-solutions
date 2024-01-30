package leetcode.java.daily.january2024.pseudopalindromicpathsinabinarytree;

import leetcode.java.tree.TreeNode;


public class Solution1 {
  public int pseudoPalindromicPaths(TreeNode root) {
    int[] counts = new int[10];
    return findPseudoPalindromicPaths(root, counts);
  }

  private int findPseudoPalindromicPaths(TreeNode node, int[] counts) {
    if (node == null) {
      return 0;
    }
    counts[node.val]++;
    int pathsCount = 0;
    if (node.left == null && node.right == null) {
      // leaf node
      if (isPalindromic(counts)) {
        pathsCount = 1;
      }
    } else {
      pathsCount += findPseudoPalindromicPaths(node.left, counts);
      pathsCount += findPseudoPalindromicPaths(node.right, counts);
    }
    counts[node.val]--;
    return pathsCount;
  }

  private boolean isPalindromic(int[] counts) {
    int oddCount = 0;
    for (int count : counts) {
      if (count % 2 == 1) {
        oddCount++;
      }
      if (oddCount > 1) {
        return false;
      }
    }
    return true;
  }
}
