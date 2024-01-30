package leetcode.java.dp.numberofwaystobuildtiles;

import java.util.Arrays;

public class Solution1 {
  public long arrangeTiles(int n) {
    long[] dp = new long[n + 1];
    Arrays.fill(dp, -1);
    return arrangeTiles(n, dp);
  }

  public long arrangeTiles(int n, long[] dp) {
    if (n == 0) {
      return 1;
    }
    if (dp[n] != -1) {
      return dp[n];
    }
    long count = 0;
    if (n - 4 >= 0) {
      count += arrangeTiles(n - 4);
    }
    count += arrangeTiles(n - 1);
    return dp[n] = count;
  }

  public static void main(String[] args) {
    System.out.println(new Solution1().arrangeTiles(1));
  }
}
