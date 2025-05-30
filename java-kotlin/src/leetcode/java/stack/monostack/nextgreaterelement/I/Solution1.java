package leetcode.java.stack.monostack.nextgreaterelement.I;

import java.util.ArrayDeque;
import java.util.Deque;
import java.util.HashMap;
import java.util.Map;

public class Solution1 {
  public int[] nextGreaterElement(int[] nums1, int[] nums2) {
    Map<Integer, Integer> map = new HashMap<>();
    Deque<Integer> stack = new ArrayDeque<>();
    int[] ans = new int[nums1.length];
    for (int num : nums2) {
      while (!stack.isEmpty() && stack.peek() < num) {
        int solutionFound = stack.pop();
        map.put(solutionFound, num);
      }
      stack.push(num);
    }
    for (int i = 0; i < nums1.length; i++) {
      int curr = nums1[i];
      ans[i] = map.getOrDefault(curr, -1);
    }
    return ans;
  }
}
