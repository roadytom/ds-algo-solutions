package leetcode.kotlin.binarysearch.minimizethemaximumdifferenceofpairs2616

import leetcode.kotlin.println

/**
 * TIME COMPLEXITY: O(p * n + n * log(n))
 * gives TLE
 */
class Solution1 {
  /**
   * 1,1,2,3,7,10
   */
  fun minimizeMax(nums: IntArray, p: Int): Int {
    val sortedNums = nums.sortedArray()
    val dp = Array(p + 1) { IntArray(nums.size) { -1 } }
    return recurrenceRelation(dp, sortedNums, 0, p)
  }

  private fun recurrenceRelation(dp: Array<IntArray>, nums: IntArray, index: Int, p: Int): Int {
    if (p == 0) {
      return 0
    }
    if (index >= nums.lastIndex) {
      return Integer.MAX_VALUE
    }
    if (dp[p][index] != -1) {
      return dp[p][index]
    }

    dp[p][index] = minOf(
      maxOf(nums[index + 1] - nums[index], recurrenceRelation(dp, nums, index + 2, p - 1)),
      recurrenceRelation(dp, nums, index + 1, p)
    )
    return dp[p][index]
  }
}

fun main() {
  Solution1().minimizeMax(intArrayOf(10, 1, 2, 7, 1, 3), 2).println()
}
