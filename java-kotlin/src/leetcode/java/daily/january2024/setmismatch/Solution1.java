package leetcode.java.daily.january2024.setmismatch;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

/**
 * TIME COMPLEXITY: O(n)
 * SPACE COMPLEXITY: O(n)
 * NEED OPTIMIZE SPACE COMPLEXITY
 */
public class Solution1 {
  public int[] findErrorNums(int[] nums) {
    int[] ans = new int[2];
    Set<Integer> set = new HashSet<>();
    for (int num : nums) {
      if (set.contains(num)) {
        ans[0] = num;
      }
      set.add(num);
    }
    for (int i = 1; i <= nums.length; i++) {
      if (!set.contains(i)) {
        ans[1] = i;
        break;
      }
    }
    return ans;
  }

  public static void main(String[] args) {
    System.out.println(Arrays.toString(new Solution1().findErrorNums(new int[]{1, 2, 2, 4})));
  }
}
