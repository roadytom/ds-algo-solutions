package leetcode.java.daily.february2024.cherrypickup.II;

public class Solution1 {
    private final int NEGATIVE_INFINITY = -1_000_000_000;

    public int cherryPickup(int[][] grid) {
        Integer[][][] memo = new Integer[grid.length][grid[0].length][grid[0].length];
        return dp(0, 0, grid[0].length - 1, grid, memo);
    }

    public int dp(int r, int c1, int c2, int[][] grid, Integer[][][] memo) {
        int n = grid.length, m = grid[0].length;
        if (c1 < 0 || c2 < 0 || c1 == m || c2 == m) {
            return NEGATIVE_INFINITY;
        }
        if (r == n - 1) {
            return grid[r][c1] + ((c1 != c2) ? grid[r][c2] : 0);
        }
        if (memo[r][c1][c2] != null) {
            return memo[r][c1][c2];
        }
        int max = NEGATIVE_INFINITY;
        for (int dr1 = -1; dr1 <= 1; dr1++) {
            for (int dr2 = -1; dr2 <= 1; dr2++) {
                int possibleCount = grid[r][c1] + ((c1 != c2) ? grid[r][c2] : 0);
                possibleCount += dp(r + 1, c1 + dr1, c2 + dr2, grid, memo);
                max = Math.max(max, possibleCount);
            }
        }
        return memo[r][c1][c2] = max;
    }
}
