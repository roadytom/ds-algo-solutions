package leetcode.java.stack.monostack.finalpricewithspecialdiscount;

import leetcode.java.util.Pair;

import java.util.ArrayDeque;
import java.util.Deque;

/**
 * MONOTONIC INCREASING STACK
 * SOLUTION
 */
public class Solution2 {
  public int[] finalPrices(int[] prices) {
    final int n = prices.length;
    int[] ans = new int[n];
    Deque<Pair<Integer, Integer>> stack = new ArrayDeque<>();
    for (int i = 0; i < n; i++) {
      int curr = prices[i];
      while (!stack.isEmpty() && stack.peek().getValue() >= curr) {
        Pair<Integer, Integer> nextSmallerFound = stack.pop();
        ans[nextSmallerFound.getKey()] = nextSmallerFound.getValue() - curr;
      }
      stack.push(new Pair<>(i, curr));
    }
    while (!stack.isEmpty()) {
      Pair<Integer, Integer> answerNotFound = stack.pop();
      ans[answerNotFound.getKey()] = answerNotFound.getValue();
    }
    return ans;
  }
}
