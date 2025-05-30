@file:Suppress("PackageName")

package leetcode.kotlin.dp.arithmeticslice.II

import leetcode.kotlin.println

/**
 * TOP DOWN DP, RECURSION
 * SLIGHTLY BETTER TO UNDERSTAND
 * BUT EVERYTHING IS THE SAME AS
 * SOLUTION 1
 */
class Solution2 {
  fun numberOfArithmeticSlices(nums: IntArray): Int {
    // memo to store number of arithmetic slices
    // starting from the index till the end
    // for the taken difference
    val memo = Array(nums.size) { mutableMapOf<Long, Int>() }
    var ans = 0
    for (i in 0..nums.lastIndex - 2) {
      for (j in i + 1..nums.lastIndex) {
        ans += findNumberOfArithmeticSlices(j, nums[j].toLong() - nums[i].toLong(), nums, memo)
      }
    }
    return ans
  }

  private fun findNumberOfArithmeticSlices(
    start: Int,
    diff: Long,
    nums: IntArray,
    memo: Array<MutableMap<Long, Int>>
  ): Int {
    if (start >= nums.lastIndex) {
      return 0
    }
    if (memo[start][diff] != null) {
      return memo[start][diff]!!
    }
    var total = 0
    for (i in start + 1..nums.lastIndex) {
      if (nums[i].toLong() - nums[start].toLong() == diff) {
        total += 1 + findNumberOfArithmeticSlices(i, diff, nums, memo)
      }
    }
    return total.also { memo[start][diff] = it }
  }
}

fun main() {
  Solution2().numberOfArithmeticSlices(intArrayOf(2, 4, 6, 8, 10)).println()
}