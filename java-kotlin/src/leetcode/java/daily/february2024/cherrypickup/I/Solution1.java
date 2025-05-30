package leetcode.java.daily.february2024.cherrypickup.I;

public class Solution1 {
    private final int NEGATIVE_INFINITY = -1_000_000_000;

    public int cherryPickup(int[][] grid) {
        Integer[][][] memo = new Integer[grid.length][grid[0].length][grid[0].length];
        int solution = dp(0, 0, 0, grid, memo);
        return Math.min(solution, 0);
    }

    /**
     * if we walk simultaneously then definitely
     * r1 + c1 = r2 + c2 = steps, because both of
     * them walking simultaneously exact number of steps
     */
    public int dp(int r1, int c1, int c2, int[][] grid, Integer[][][] memo) {
        int n = grid.length, m = grid[0].length;
        int r2 = r1 + c1 - c2;
        if (r1 == n || r2 == n || c1 < 0 || c2 < 0 || c1 == m || c2 == m || grid[r1][c1] == -1 || grid[r2][c2] == -1) {
            return NEGATIVE_INFINITY;
        }
        if (r1 == n - 1 && c1 == n - 1) {
            return grid[r1][c1];
        }
        if (memo[r1][c1][c2] != null) {
            return memo[r1][c1][c2];
        }
        int max = NEGATIVE_INFINITY;
        int currCherry = grid[r1][c1] + ((c1 != c2) ? grid[r2][c2] : 0);
        for (int[] dr : new int[][]{{0, 1}, {1, 0}}) {
            for (int second : new int[]{0, 1}) {
                max = Math.max(max, dp(r1 + dr[0], c1 + dr[1], c2 + second, grid, memo));
            }
        }
        return memo[r1][c1][c2] = currCherry + max;
    }
}
