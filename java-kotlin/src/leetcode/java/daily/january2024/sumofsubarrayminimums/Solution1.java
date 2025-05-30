package leetcode.java.daily.january2024.sumofsubarrayminimums;
/**
 * BRUTE FORCE SOLUTION
 * TC: O(n^2)
 * SC: O(1)
 * TLE
 */
public class Solution1 {
  public int sumSubarrayMins(int[] arr) {
    int n = arr.length;
    int sum = 0;
    for (int i = 0; i < n; i++) {
      int min = Integer.MAX_VALUE;
      for (int j = i; j < n; j++) {
        min = Math.min(min, arr[j]);
        sum += min;
        sum %= (1_000_000_007);
      }
    }
    return sum;
  }
}
