package leetcode.java.dp.numberofwaystobuildtiles;

import static java.lang.Integer.max;

public class Solution2 {
  public long arrangeTiles(int n) {
    long[] dp = new long[max(4, n + 1)];
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;

    for (int i = 4; i <= n; i++) {
      dp[i] = dp[i - 1] + dp[i - 4];
    }
    return dp[n];
  }


  public static void main(String[] args) {
    System.out.println(new Solution2().arrangeTiles(1));
  }
}
