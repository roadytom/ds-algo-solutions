package leetcode.java.daily.january2024.sumofsubarrayminimums;

/**
 * DIVIDE AND CONQUER
 * N * LOG(N) OPTIMAL
 * N * N WORST CASE TIME COMPLEXITY
 * NOT OPTIMAL BUT PROVIDES
 * THE MAIN LOGIC FOR MONOTONIC
 * STACK SOLUTION
 */
public class Solution4 {

  public int sumSubarrayMins(int[] arr) {
    return (int) findSumSubarrayMins(arr, 0, arr.length - 1);
  }

  private long findSumSubarrayMins(int[] arr, int left, int right) {
    if (left == right) {
      return arr[left];
    }
    if (left > right) {
      return 0;
    }
    int minElement = Integer.MAX_VALUE;
    int minIndex = -1;
    for (int i = left; i <= right; i++) {
      if (minElement > arr[i]) {
        minElement = arr[i];
        minIndex = i;
      }
    }
    int MOD = 1_000_000_007;
    long curr = (((long) minIndex - left + 1) * (right - minIndex + 1) * minElement) % MOD;
    curr = (curr + findSumSubarrayMins(arr, left, minIndex - 1)) % MOD;
    curr = (curr + findSumSubarrayMins(arr, minIndex + 1, right)) % MOD;
    return curr;
  }
}
