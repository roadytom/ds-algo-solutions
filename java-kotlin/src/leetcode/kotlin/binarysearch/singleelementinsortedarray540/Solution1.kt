package leetcode.kotlin.binarysearch.singleelementinsortedarray540

import leetcode.kotlin.println


/**
 * [1,1,2,3,3,4,4,8,8]
 * [3,3,7,7,10,11,11]
 */
class Solution1 {
  fun singleNonDuplicate(nums: IntArray): Int {
    var left = 0
    var right = nums.size
    while (left < right) {
      val mid = (right - left) / 2 + left
      if (nums[mid] == nums.getOrNull(mid - 1)) {
        if (mid % 2 == 0) {
          right = mid - 1
        } else {
          left = mid + 1
        }
      } else if (nums[mid] == nums.getOrNull(mid + 1)) {
        if (mid % 2 == 0) {
          left = mid + 2
        } else {
          right = mid
        }
      } else {
        return nums[mid]
      }
    }
    throw IllegalStateException("cannot be here, if there is at least element appears exactly once")
  }
}

fun main() {
  Solution1().singleNonDuplicate(intArrayOf(3, 3, 7, 7, 10, 11, 11)).println()
}