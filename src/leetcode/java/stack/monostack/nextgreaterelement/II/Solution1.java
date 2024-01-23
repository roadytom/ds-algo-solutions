package leetcode.java.stack.monostack.nextgreaterelement.II;

import leetcode.java.util.Pair;

import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Deque;

public class Solution1 {
  public int[] nextGreaterElements(int[] nums) {
    int n = nums.length;
    int[] ans = new int[n];
    Arrays.fill(ans, -1);
    Deque<Pair<Integer, Integer>> stack = new ArrayDeque<>();
    for (int i = 0; i < 2 * n; i++) {
      int index = (i % n);
      int curr = nums[index];
      while (!stack.isEmpty() && stack.peek().getValue() < curr) {
        var solutionFound = stack.pop();
        ans[solutionFound.getKey()] = curr;
      }
      stack.push(new Pair<>(index, curr));
    }
    return ans;
  }

  public static void main(String[] args) {
    System.out.println(Arrays.toString(new Solution1().nextGreaterElements(new int[]{5, 4, 3, 2, 1})));
  }
}
