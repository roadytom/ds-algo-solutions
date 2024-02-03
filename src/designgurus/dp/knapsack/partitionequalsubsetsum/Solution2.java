package designgurus.dp.knapsack.partitionequalsubsetsum;

public class Solution2 {
    /**
     * 1,2,3,4
     * target           0 1 2 3 4 5
     * end          0   t f f f f f
     * x            1   t t f f f f
     * x            2   t t t t f f
     * x            3   t
     * x            4   t
     */
    public boolean canPartition(int[] nums) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        if (sum % 2 == 1) {
            return false;
        }
        int targets = sum / 2;
        // from index [0..i] is it possible
        // to find subset equal to target
        boolean[][] dp = new boolean[nums.length + 1][targets + 1];
        // any subset with target equals zero is true;
        for (int i = 0; i <= nums.length; i++) {
            dp[i][0] = true;
        }
        for (int i = 1; i <= nums.length; i++) {
            for (int target = 0; target <= targets; target++) {
                boolean consider = false;
                if (target - nums[i - 1] >= 0) {
                    consider = dp[i - 1][target - nums[i - 1]];
                }
                boolean skip = dp[i - 1][target];
                dp[i][target] = consider || skip;
            }
        }
        return dp[nums.length][targets];
    }
}
