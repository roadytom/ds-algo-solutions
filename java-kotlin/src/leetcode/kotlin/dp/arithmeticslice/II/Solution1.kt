@file:Suppress("PackageName")

package leetcode.kotlin.dp.arithmeticslice.II

import leetcode.kotlin.println

/**
 * TOP DOWN DP, RECURSIVE
 * TC: O(n^2)
 * SC: O(n^2)
 */
class Solution1 {
  fun numberOfArithmeticSlices(nums: IntArray): Int {
    var ans = 0

    /**
     * memo stores memo[index][diff], which is
     * number of arithmetic slices ending at index
     * with difference diff
     */
    val memo = Array(nums.size) { mutableMapOf<Long, Int>() }
    for (i in nums.lastIndex downTo 2) {
      for (j in i - 1 downTo 0) {
        ans += findArithmeticSlices(j, nums[i].toLong() - nums[j].toLong(), nums, memo)
      }
    }
    return ans
  }

  private fun findArithmeticSlices(index: Int, diff: Long, nums: IntArray, memo: Array<MutableMap<Long, Int>>): Int {
    if (index < 1) {
      return 0
    }
    if (memo[index][diff] != null) {
      return memo[index][diff]!!
    }
    var total = 0
    for (i in index - 1 downTo 0) {
      if (nums[index].toLong() - nums[i].toLong() == diff) {
        total += 1 + findArithmeticSlices(i, diff, nums, memo)
      }
    }
    return total.also { memo[index][diff] = it }
  }
}

fun main() {
  Solution1().numberOfArithmeticSlices(intArrayOf(2, 4, 6, 8, 10)).println()
}