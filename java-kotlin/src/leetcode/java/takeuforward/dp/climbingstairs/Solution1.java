package leetcode.java.takeuforward.dp.climbingstairs;

public class Solution1 {
    public int climbStairs(int n) {
        Integer[] memo = new Integer[n];
        return dp(0, n, memo);
    }

    private int dp(int curr, int n, Integer[] memo) {
        if (curr == n) {
            return 1;
        }
        if (curr > n) {
            return 0;
        }
        if (memo[curr] != null) {
            return memo[curr];
        }
        return memo[curr] = dp(curr + 1, n, memo) + dp(curr + 2, n, memo);
    }
}
