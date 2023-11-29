package leetcode.kotlin.binarysearch.binarysearch704

class Solution1 {
  fun search(nums: IntArray, target: Int): Int {
    return findUpperBound(nums, target)
  }

  //left most insert position
  private fun findLowerBound(nums: IntArray, target: Int): Int {
    var left = 0
    var right = nums.size
    while (left < right) {
      val mid = (right - left) / 2 + left
      if (nums[mid] < target) {
        left = mid + 1
      } else {
        right = mid
      }
    }
    return if (left < nums.size && nums[left] == target) {
      left
    } else {
      -1
    }
  }

  //right most insert position
  private fun findUpperBound(nums: IntArray, target: Int): Int {
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
    return if (left > 0 && nums[left - 1] == target) {
      left - 1
    } else {
      -1
    }
  }
}