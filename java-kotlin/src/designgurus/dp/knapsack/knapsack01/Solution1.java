package designgurus.dp.knapsack.knapsack01;

/**
 * F(index, capacity) = max(F(index + 1, capacity), F(index + 1, capacity - weight) + price)
 * F is max achievable price from [index, lastIndex]
 */
public class Solution1 {
    public int solveKnapsack(int[] profits, int[] weights, int capacity) {
        int[][] memo = new int[profits.length][capacity + 1];
        return dp(0, profits, weights, capacity, memo);
    }

    private int dp(int index, int[] profits, int[] weights, int capacity, int[][] memo) {
        // BASE CASE
        if (index == profits.length) {
            return 0;
        }
        if (memo[index][capacity] != -1) {
            return memo[index][capacity];
        }
        int skip = dp(index + 1, profits, weights, capacity, memo);
        int consider = Integer.MIN_VALUE;
        if (capacity - weights[index] >= 0) {
            consider = dp(index + 1, profits, weights, capacity - weights[index], memo) + profits[index];
        }
        return memo[index][capacity] = Math.max(skip, consider);
    }
}
