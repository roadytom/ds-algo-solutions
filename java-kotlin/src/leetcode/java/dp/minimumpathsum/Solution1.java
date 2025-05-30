package leetcode.java.dp.minimumpathsum;

public class Solution1 {
    public int minPathSum(int[][] grid) {
        Double[][] memo = new Double[grid.length][grid[0].length];
        return minPathSum(0, 0, grid, memo).intValue();
    }

    private Double minPathSum(int r, int c, int[][] grid, Double[][] memo) {
        // BASE case: when out of boundary
        if (r >= grid.length || c >= grid[0].length) {
            return Double.POSITIVE_INFINITY;
        }
        if (memo[r][c] != null) {
            return memo[r][c];
        }
        // BASE case: when reached destination
        if (c == grid[0].length - 1 && r == grid.length - 1) {
            return memo[r][c] = (double) grid[r][c];
        }
        double max = Math.min(minPathSum(r, c + 1, grid, memo), minPathSum(r + 1, c, grid, memo));
        return memo[r][c] = max + grid[r][c];
    }

    public static void main(String[] args) {
        System.out.println(new Solution1().minPathSum(new int[][]{{1, 3, 1}, {1, 5, 1}, {4, 2, 1}}));
    }
}
