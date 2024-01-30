package leetcode.java.stack.monostack.shortestunsortedcontinuoussubarray581;

/**
 * BRUTE FORCE SOLUTION
 * LIKE SELECTION SORT ALGORITHM
 */
public class Solution2 {
  public int findUnsortedSubarray(int[] nums) {
    int l = nums.length, r = 0;
    for (int i = 0; i < nums.length - 1; i++) {
      for (int j = i + 1; j < nums.length; j++) {
        if (nums[i] > nums[j]) {
          l = Math.min(l, i);
          r = Math.max(r, j);
        }
      }
    }
    return l > r ? 0 : r - l + 1;
  }
}
