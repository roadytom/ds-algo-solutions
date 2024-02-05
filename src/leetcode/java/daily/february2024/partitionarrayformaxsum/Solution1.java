package leetcode.java.daily.february2024.partitionarrayformaxsum;

public class Solution1 {
    public int maxSumAfterPartitioning(int[] arr, int k) {
        Integer[] memo = new Integer[arr.length];
        return dp(0, k, arr, memo);
    }

    private int dp(int index, int k, int[] arr, Integer[] memo) {
        // BASE CASE:
        if (index >= arr.length) {
            return 0;
        }
        if (memo[index] != null) {
            return memo[index];
        }
        int max = -1;
        int sum = 0;
        for (int i = index; i < Math.min(index + k, arr.length); i++) {
            max = Math.max(max, arr[i]);
            sum = Math.max(sum, max * (i - index + 1) + dp(i + 1, k, arr, memo));
        }
        return memo[index] = sum;
    }

    public static void main(String[] args) {
        System.out.println(new Solution1().maxSumAfterPartitioning(new int[]{1, 15, 7, 9, 2, 5, 10}, 3));
    }
}
