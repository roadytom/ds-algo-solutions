package leetcode.java.stack.monostack.shortestunsortedcontinuoussubarray581;

import leetcode.java.util.Pair;

import java.util.ArrayDeque;
import java.util.Deque;

/**
 * Monotonic stack solution
 * for each element we have to find
 * next smaller element, which will beginning
 * of unsorted array
 * and vice versa
 */
public class Solution4 {
  public int findUnsortedSubarray(int[] nums) {
    Deque<Pair<Integer, Integer>> stack = new ArrayDeque<>();
    int l = nums.length, r = 0;
    for (int i = 0; i < nums.length; i++) {
      int num = nums[i];
      while (!stack.isEmpty() && stack.peek().getValue() > num) {
        var foundSmaller = stack.pop();
        var foundSmallerIndex = foundSmaller.getKey();
        l = Math.min(l, foundSmallerIndex);
      }
      stack.push(new Pair<>(i, num));
    }
    stack.clear();
    for (int i = nums.length - 1; i >= 0; i--) {
      int num = nums[i];
      while (!stack.isEmpty() && stack.peek().getValue() < num) {
        var foundNextGreater = stack.pop();
        var foundNextGreaterIndex = foundNextGreater.getKey();
        r = Math.max(r, foundNextGreaterIndex);
      }
      stack.push(new Pair<>(i, num));
    }
    return r < l ? 0 : r - l + 1;
  }
}
