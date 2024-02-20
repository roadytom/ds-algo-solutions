package leetcode.java.daily.february2024.findpolygonwiththelargestperimerter;

import java.util.Arrays;

public class Solution1 {
    public long largestPerimeter(int[] nums) {
        Arrays.sort(nums);
        long sum = nums[0];
        long max = -1;
        for (int i = 2; i < nums.length; i++) {
            sum += nums[i - 1];
            if (sum > nums[i]) {
                max = Math.max(max, sum + nums[i]);
            }
        }
        return max;
    }
}
