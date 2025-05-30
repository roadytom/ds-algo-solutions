package designgurus.dp.knapsack.knapsack01;

import java.util.Arrays;

/**
 * BOTTOM-UP
 * dp[index][capacity] =
 * 1. if enough capacity p + dp[index - 1][capacity - w]
 * 2. dp[index - 1][capacity];
 */
public class Solution2 {
    public int solveKnapsack(int[] profits, int[] weights, int capacity) {
        int[][] dp = new int[profits.length + 1][capacity + 1];
        for (int i = 1; i <= profits.length; i++) {
            for (int c = 1; c <= capacity; c++) {
                int consider = 0;
                if (c - weights[i - 1] >= 0) {
                    consider = dp[i - 1][c - weights[i - 1]] + profits[i - 1];
                }
                int skip = dp[i - 1][c];
                dp[i][c] = Math.max(consider, skip);
            }
        }
        return dp[profits.length][capacity];
    }

    public static void main(String[] args) {
        System.out.println(new Solution2().solveKnapsack(new int[]{1, 6, 10, 16}, new int[]{1, 2, 3, 5}, 7));
    }
}
