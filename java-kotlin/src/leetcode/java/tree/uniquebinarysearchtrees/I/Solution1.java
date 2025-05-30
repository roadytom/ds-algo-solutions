package leetcode.java.tree.uniquebinarysearchtrees.I;

import java.util.Arrays;

public class Solution1 {
  public int numTrees(int n) {
    if (n == 0 || n == 1) {
      return 1;
    } else if (n == 2) {
      return 2;
    }
    int[] memo = new int[n + 1];
    Arrays.fill(memo, -1);
    memo[0] = 1;
    memo[1] = 1;
    memo[2] = 2;
    return dp(n, memo);
  }

  public int dp(int n, int[] memo) {
    if (memo[n] != -1) {
      return memo[n];
    }
    var sum = 0;
    for (int i = 0; i < n; i++) {
      sum += numTrees(i) * numTrees(n - i - 1);
    }
    memo[n] = sum;
    return memo[n];
  }
}
