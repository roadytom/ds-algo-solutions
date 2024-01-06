package leetcode.kotlin.daily.january2024.longestincreasingsubsequence

import leetcode.kotlin.println

class Solution2 {
  fun lengthOfLIS(nums: IntArray): Int {
    val dp = IntArray(nums.size) { 1 }
    for (idx in nums.indices) {
      for (before in 0..<idx) {
        if (nums[idx] > nums[before]) {
          dp[idx] = dp[idx].coerceAtLeast(dp[before] + 1)
        }
      }
    }
    return dp.max()
  }
}

fun main() {
  Solution1().lengthOfLIS(intArrayOf(10, 9, 2, 5, 3, 7, 101, 18)).println()
}