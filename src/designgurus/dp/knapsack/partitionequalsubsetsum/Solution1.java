package designgurus.dp.knapsack.partitionequalsubsetsum;

import java.util.Arrays;


public class Solution1 {
    public boolean canPartition(int[] nums) {
        int totalSum = Arrays.stream(nums).sum();
        if (totalSum % 2 != 0) {
            return false;
        }
        Boolean[][] memo = new Boolean[totalSum / 2 + 1][nums.length];
        return dp(0, 0, totalSum, nums, memo);
    }

    private boolean dp(int currSum, int index, int totalSum, int[] nums, Boolean[][] memo) {
        // BASE CASE:
        if (totalSum / 2 == currSum) {
            return true;
        }
        if (index >= nums.length) {
            return false;
        }
        if (memo[currSum][index] != null) {
            return memo[currSum][index];
        }
        boolean skip = dp(currSum, index + 1, totalSum, nums, memo);
        boolean consider = false;
        if (currSum + nums[index] <= totalSum / 2) {
            consider = dp(currSum + nums[index], index + 1, totalSum, nums, memo);
        }
        return memo[currSum][index] = skip || consider;
    }
}
