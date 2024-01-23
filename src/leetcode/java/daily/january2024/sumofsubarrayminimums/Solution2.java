package leetcode.java.daily.january2024.sumofsubarrayminimums;

/**
 * NEED TO FINALIZE
 * DIVIDE AND CONQUER
 * N * LOG(N) SOLUTION
 */
public class Solution2 {
  final int MOD = 1_000_000_007;

  public int sumSubarrayMins(int[] arr) {
    return findSumSubarrayMins(arr, 0, arr.length - 1);
  }

  private int findSumSubarrayMins(int[] arr, int left, int right) {
    if (left == right) {
      return arr[left];
    }
    int mid = (right - left) / 2 + left;
    int ans = findSumSubarrayMins(arr, left, mid) + findSumSubarrayMins(arr, mid + 1, right);
    ans %= MOD;
    ans += merge(arr, left, right, mid);
    return ans % MOD;
  }

  private int merge(int[] arr, int left, int right, int mid) {
    int leftPointer = mid, rightPointer = mid + 1;
    int leftMin = Integer.MAX_VALUE, rightMin = Integer.MAX_VALUE;
    while (leftPointer >= left || rightPointer <= right) {
      if (leftPointer >= left) {
        leftMin = Math.min(leftMin, arr[leftPointer]);
      }
      if (leftPointer >= left) {
        leftMin = Math.min(leftMin, arr[leftPointer]);
      }
      rightMin = Math.min(rightMin, arr[rightPointer]);
    }
    return -1;
  }
}