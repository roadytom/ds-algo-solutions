package leetcode.java.daily.january2024.kinversepairsarray;

import java.util.Arrays;

public class Solution1 {
  public int kInversePairs(int n, int k) {
    int[][] memo = new int[n + 1][k + 1];
    for (int[] arr : memo) {
      Arrays.fill(arr, -1);
    }
    return kInversePairs(n, k, memo);
  }

  private int kInversePairs(int n, int k, int[][] memo) {
    if (memo[n][k] != -1) {
      return memo[n][k];
    }
    // base case
    if (n == 0) {
      return memo[n][k] = 0;
    }
    if (k == 0) {
      return memo[n][k] = 1;
    }

    int sum = 0;
    for (int i = 0; i <= Math.min(k, n - 1); i++) {
      sum = add(sum, kInversePairs(n - 1, k - i));
    }
    return memo[n][k] = sum;
  }

  private int add(int f, int s) {
    return (f + s) % 1_000_000_007;
  }

  public static void main(String[] args) {
    System.out.println(new Solution1().kInversePairs(10, 33));
  }
}
