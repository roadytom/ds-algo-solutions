package leetcode.kotlin.binarysearch.searchinrotatedsortedarray33

import leetcode.kotlin.println


class Solution1 {
  fun search(nums: IntArray, target: Int): Int {
    var low = 0
    var high = nums.size - 1
    while (low <= high) {
      val mid = (high - low) / 2 + low
      if (nums[mid] == target) {
        return mid
      }
      if (nums[low] <= nums[mid]) {
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
    }
    return -1
  }
}

fun main() {
  Solution1().search(intArrayOf(3, 1), 1).println()
}