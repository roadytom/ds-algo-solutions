package leetcode.kotlin.binarysearch.minimizethemaximumdifferenceofpairs2616

import leetcode.kotlin.println

/**
 * TIME COMPLEXITY: O(n * log(V) + n * log(n))
 * V here difference between max and min element
 * of array
 */
class Solution2 {
  /**
   * 1,1,2,3,7,10, p = 2
   */
  fun minimizeMax(nums: IntArray, p: Int): Int {
    val nums = nums.sortedArray()
    var left = 0
    var right = nums.last() - nums.first()
    while (left <= right) {
      val mid = (right - left) / 2 + left
      if (countNumberOfPairs(mid, nums) >= p) {
        right = mid - 1
      } else {
        left = mid + 1
      }
    }
    return left
  }

  private fun countNumberOfPairs(maxDifference: Int, nums: IntArray): Int {
    var index = 0
    var pairCount = 0
    while (index < nums.lastIndex) {
      if (nums[index + 1] - nums[index] <= maxDifference) {
        pairCount++
        index += 2
        continue
      }
      index++
    }
    return pairCount
  }
}

fun main() {
  Solution2().minimizeMax(intArrayOf(10, 1, 2, 7, 1, 3), 2).println()
}
