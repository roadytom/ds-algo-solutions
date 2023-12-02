package leetcode.java.septemberchallenge2023.uniquepaths62;

public class Solution2 {
  public int uniquePaths(int m, int n) {
    int[][] dp = new int[m + 1][n + 1];
    dp[1][1] = 1;
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
      }
    }
    return dp[m][n];
  }

  public static void main(String[] args) {
    System.out.println(new Solution2().uniquePaths(3, 2));
  }
}
