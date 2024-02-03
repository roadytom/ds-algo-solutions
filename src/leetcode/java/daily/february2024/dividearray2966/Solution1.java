package leetcode.java.daily.february2024.dividearray2966;

import java.util.Arrays;

/**
 * [1,3,4,8,7,9,3,5,1]
 * 1, 1, 3, 3, 4, 5, 7, 8, 9
 * 2
 * 1 -> find elements less than 1 - k <= x <= k + 1
 */
public class Solution1 {
    public int[][] divideArray(int[] nums, int k) {
        Arrays.sort(nums);
        int start = 0;
        int[][] ans = new int[nums.length / 3][3];
        int aIndex = 0;
        while (start < nums.length) {
            if (nums[start + 2] - nums[start] > k) {
                return new int[][]{};
            }
            System.arraycopy(nums, start, ans[aIndex], 0, 3);
            aIndex++;
            start += 3;
        }
        return ans;
    }

    public static void main(String[] args) {
        System.out.println(Arrays.toString(Arrays.stream(new int[]{15, 13, 12, 13, 12, 14, 12, 2, 3, 13, 12, 14, 14, 13, 5, 12, 12, 2, 13, 2, 2}).sorted().toArray()));
    }
}
