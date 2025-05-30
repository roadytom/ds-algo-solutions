package leetcode.java.tree.uniquebinarysearchtrees.I;

import java.util.Arrays;

public class Solution2 {
  public int numTrees(int n) {
    if (n == 0 || n == 1) {
      return 1;
    } else if (n == 2) {
      return 2;
    }
    int[] dp = new int[n + 1];
    Arrays.fill(dp, -1);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++) {
      var sum = 0;
      for (int root = 1; root <= i; root++) {
        sum += dp[root - 1] * dp[i - root];
      }
      dp[i] = sum;
    }
    return dp[n];
  }
}
