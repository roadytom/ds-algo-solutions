package leetcode.kotlin.binarysearch.searchinrotatedsortedarrayII81

import leetcode.kotlin.binarysearch.searchsuggestionssystem1268.println

/**
 * Worst case O(n)
 * we just changed one logic:
 * if we check and nums[mid] != target
 * then our nums[mid]==nums[low] then
 * our solution might be in the left site
 * or right site or not exist, we don't know
 * BUT we know than nums[low] cannot be the answer
 * because it is equal to nums[mid] and != to target
 * SO we can only increase low until we found solution
 */
class Solution1 {
  fun search(nums: IntArray, target: Int): Boolean {
    var low = 0
    var high = nums.size - 1
    while (low <= high) {
      val mid = (high - low) / 2 + low
      if (nums[mid] == target) {
        return true
      }
      if (isBinarySearchPossible(nums, mid, low)) {
        if (nums[low] < nums[mid]) {
          // left subarray is sorted
          // so we can easily check it
          if (target in nums[low]..nums[mid]) {
            high = mid - 1
          } else {
            low = mid + 1
          }
        } else {
          // right subarray is sorted
          // so we can easily check it
          if (target in nums[mid]..nums[high]) {
            low = mid + 1
          } else {
            high = mid - 1
          }
        }
      } else {
        low++
      }
    }
    return false
  }

  private fun isBinarySearchPossible(nums: IntArray, mid: Int, low: Int): Boolean {
    return nums[low] != nums[mid]
  }
}

fun main() {
  Solution1().search(intArrayOf(1, 0, 1, 1, 1), 0).println()
}