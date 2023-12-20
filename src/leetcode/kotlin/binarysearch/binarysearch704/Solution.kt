package leetcode.kotlin.binarysearch.binarysearch704

class Solution {
  fun search(nums: IntArray, target: Int): Int {
    var left = 0
    var right = nums.lastIndex
    while (left <= right) {
      val mid = (left + right) / 2
      if (nums[mid] == target) {
        return mid
      }
      if (nums[mid] < target) {
        left = mid + 1
      } else {
        right = mid - 1
      }
      val a = intArrayOf()
    }
    return -1
  }
}

fun main() {
  println(Solution().search(intArrayOf(-1, 0, 3, 5, 9, 12), 0))
}