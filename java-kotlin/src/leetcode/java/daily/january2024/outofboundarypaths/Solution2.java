package leetcode.java.daily.january2024.outofboundarypaths;

public class Solution2 {
  int[][] directions = new int[][]{{0, 1}, {1, 0}, {0, -1}, {-1, 0},};
  private final int MOD = 1_000_000_007;

  public int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    int[][] dp = new int[m][n];
    for (int move = 1; move <= maxMove; move++) {
      int[][] temp = new int[m][n];
      for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
          temp[i][j] = add((i > 0) ? dp[i - 1][j] : 1, (j > 0) ? dp[i][j - 1] : 1, (i < m - 1) ? dp[i + 1][j] : 1, (j < n - 1) ? dp[i][j + 1] : 1);
        }
      }
      dp = temp;
    }
    return dp[startRow][startColumn];
  }

  public int add(int... arr) {
    int sum = 0;
    for (int j : arr) {
      sum = add(sum, j);
    }
    return sum;
  }

  public int add(int f, int s) {
    return (f + s) % MOD;
  }
}
