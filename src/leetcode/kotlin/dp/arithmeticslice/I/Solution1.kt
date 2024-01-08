@file:Suppress("PackageName")

package leetcode.kotlin.dp.arithmeticslice.I

import leetcode.kotlin.println

class Solution1 {
  var ans = 0
  fun numberOfArithmeticSlices(nums: IntArray): Int {
    findNumberOfArithmeticSlices(nums.size - 1, nums)
    return ans
  }

  private fun findNumberOfArithmeticSlices(index: Int, nums: IntArray): Int {
    if (index < 2) {
      return 0
    }
    return if (nums[index] - nums[index - 1] == nums[index - 1] - nums[index - 2]) {
      val count = 1 + findNumberOfArithmeticSlices(index - 1, nums)
      count.also { ans += it }
    } else {
      findNumberOfArithmeticSlices(index - 1, nums)
      0
    }
  }
}

fun main() {
  Solution1().numberOfArithmeticSlices(intArrayOf(1, 2, 3, 4)).println()
}