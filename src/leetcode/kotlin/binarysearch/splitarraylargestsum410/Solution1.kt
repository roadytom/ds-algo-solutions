package leetcode.kotlin.binarysearch.splitarraylargestsum410

import leetcode.kotlin.binarysearch.searchsuggestionssystem1268.println

/**
 * BINARY SEARCH
 * TIME COMPLEXITY:
 * O(N * log(S)) S is sumOf array elements
 */
class Solution1 {
  fun splitArray(nums: IntArray, k: Int): Int {
    var left = nums.max()
    var right = nums.sum()
    while (left <= right) {
      val mid = (right - left) / 2 + left
      if (possible(nums, mid, k)) {
        right = mid - 1
      } else {
        left = mid + 1
      }
    }
    return left
  }

  fun possible(nums: IntArray, threshold: Int, k: Int): Boolean {
    var count = 1
    var current = 0
    var index = 0
    while (index < nums.size) {
      if (current + nums[index] <= threshold) {
        current += nums[index]
      } else {
        current = nums[index]
        count++
      }
      if (count > k) {
        return false
      }
      index++
    }
    return true
  }
}

fun main() {
  Solution1().splitArray(intArrayOf(1, 4, 4), 3).println()
  Solution1().possible(intArrayOf(1, 4, 4), 1, 3).println()
}