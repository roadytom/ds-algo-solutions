package leetcode.kotlin.daily.january2024.longestincreasingsubsequence

import leetcode.kotlin.println

class Solution1 {
  fun lengthOfLIS(nums: IntArray): Int {
    val memo = IntArray(nums.size) { -1 }
    for (i in nums.indices) {
      lengthOfLIS(i, nums, memo)
    }
//    memo.contentToString().println()
    return memo.max()
  }

  private fun lengthOfLIS(idx: Int, nums: IntArray, memo: IntArray): Int {
    if (memo[idx] != -1) {
      return memo[idx]
    }
    var lis = 1
    for (k in (idx + 1)..nums.lastIndex) {
      if (nums[idx] < nums[k]) {
        lis = lis.coerceAtLeast(lengthOfLIS(k, nums, memo) + 1)
      }
    }
    return lis.also { memo[idx] = it }
  }
}

fun main() {
  Solution1().lengthOfLIS(intArrayOf(10, 9, 2, 5, 3, 7, 101, 18)).println()
}