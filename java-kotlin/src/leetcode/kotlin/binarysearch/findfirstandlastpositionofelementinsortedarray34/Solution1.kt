package leetcode.kotlin.binarysearch.findfirstandlastpositionofelementinsortedarray34

import leetcode.kotlin.println

class Solution1 {
  fun searchRange(nums: IntArray, target: Int): IntArray {
    return intArrayOf(
      getBeginOfTarget(nums, target), getEndOfTarget(nums, target)
    )
  }

  private fun getEndOfTarget(nums: IntArray, target: Int): Int {
    var left = 0
    var right = nums.size
    while (left < right) {
      val mid = (right - left) / 2 + left
      if (nums[mid] <= target) {
        left = mid + 1
      } else {
        right = mid
      }
    }
    return if (left == 0 || nums[left - 1] != target) {
      -1
    } else {
      left - 1
    }
  }

  private fun getBeginOfTarget(nums: IntArray, target: Int): Int {
    var left = 0
    var right = nums.size
    while (left < right) {
      val mid = (right - left) / 2 + left
      if (nums[mid] >= target) {
        right = mid
      } else {
        left = mid + 1
      }
    }
    return if (left == nums.size || nums[left] != target) {
      -1
    } else {
      left
    }
  }
}

fun main() {
  Solution1().searchRange(
    intArrayOf(), 6
  ).contentToString().println()
}