package leetcode.java.septemberchallenge2023.uniquepaths62;

import java.util.Arrays;

public class Solution1 {
  public int uniquePaths(int m, int n) {
    int[][] dp = new int[m][n];
    Arrays.stream(dp)
        .forEach(row -> Arrays.fill(row, -1));
    return solve(0, 0, m, n, dp);
  }

  private int solve(int currX, int currY, int x, int y, int[][] dp) {
    if (currX == x - 1 && currY == y - 1) {
      return 1;
    } else if (currX >= x || currY >= y) {
      return 0;
    }
    if (dp[currX][currY] != -1) {
      return dp[currX][currY];
    }
    return dp[currX][currY] = solve(currX + 1, currY, x, y, dp) + solve(currX, currY + 1, x, y, dp);
  }
}
