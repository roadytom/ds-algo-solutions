package leetcode.java.stack.monostack.shortestunsortedcontinuoussubarray581;

/**
 * If we know max and min elements
 * in the unsorted part of the array
 * then their corresponding index in the
 * whole array, indicates actual correct positions
 * to begin sorting
 */
public class Solution3 {
  public int findUnsortedSubarray(int[] nums) {
    int min = Integer.MAX_VALUE;
    boolean flag = false;
    for (int i = 1; i < nums.length; i++) {
      if (nums[i] < nums[i - 1]) {
        flag = true;
      }
      if (flag) {
        min = Math.min(min, nums[i]);
      }
    }
    flag = false;
    int max = Integer.MIN_VALUE;
    for (int i = nums.length - 2; i >= 0; i--) {
      if (nums[i] > nums[i + 1]) {
        flag = true;
      }
      if (flag) {
        max = Math.max(max, nums[i]);
      }
    }
    int l = nums.length;
    for (int i = 0; i < nums.length; i++) {
      if (nums[i] > min) {
        l = i;
        break;
      }
    }
    int r = 0;
    for (int i = nums.length - 1; i >= 0; i--) {
      if (nums[i] < max) {
        r = i;
        break;
      }
    }
    return r < l ? 0 : r - l + 1;
  }
}
