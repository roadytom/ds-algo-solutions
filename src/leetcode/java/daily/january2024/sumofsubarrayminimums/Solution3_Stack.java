package leetcode.java.daily.january2024.sumofsubarrayminimums;

import leetcode.java.util.Pair;

import java.util.ArrayDeque;
import java.util.Deque;

public class Solution3_Stack {
  public int sumSubarrayMins(int[] arr) {
    final int MOD = 1_000_000_007;
    long answer = 0;
    Deque<Pair<Integer, Integer>> stack = new ArrayDeque<>();

    for (int i = 0; i <= arr.length; i++) {
      int curr;
      if (i == arr.length) {
        curr = Integer.MIN_VALUE;
      } else {
        curr = arr[i];
      }
      while (!stack.isEmpty() && stack.peek().getValue() >= curr) {
        var foundNextSmaller = stack.pop();
        var index = foundNextSmaller.getKey();
        var value = foundNextSmaller.getValue();
        int prevSmallerIndex = -1;
        if (!stack.isEmpty()) {
          prevSmallerIndex = stack.peek().getKey();
        }
        answer = (answer + (long) value * (index - prevSmallerIndex) * (i - index)) % MOD;
      }
      stack.push(new Pair<>(i, curr));
    }
    return (int) answer;
  }
}
