package leetcode.java.daily.february2024.rearrangearrayelementsbysign;

public class Solution1 {
    public int[] rearrangeArray(int[] nums) {
        final int n = nums.length;
        int[] ans = new int[n];
        int negativeIndex = 1;
        int positiveIndex = 0;
        for (int num : nums) {
            if (num > 0) {
                ans[positiveIndex] = num;
                positiveIndex += 2;
            } else {
                ans[negativeIndex] = num;
                negativeIndex += 2;
            }
        }
        return ans;
    }
}
